/*
 * Converts CIDR to IPADDRESS
 * Copyright (C) 2018 z0noxz, <chris@noxz.tech>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char *usage = "usage: cidr2ip <CIDR>";

int
main(int argc, char **argv) {
    int ip, cidr,
        input_size;
    int buffer_size = 80;
    unsigned char mask[4];
    char buffer[buffer_size];
    char *input;

    /* validate input from STDIN */
    if (!isatty(fileno(stdin)) && fgets(buffer, buffer_size, stdin) != NULL) {
        input_size = strlen(buffer);
        input = malloc(input_size);
        input[0] = '\0';
        strcat(input, buffer);

    /* validate input from CLI */
    } else if (argc == 2) {
        input_size = strlen(argv[1]);
        input = malloc(input_size);
        input[0] = '\0';
        strcat(input, argv[1]);

    /* no valid input, so show usage */
    } else {
        fprintf(stderr, "%s\n", usage);
        return 1;
    }

    if (sscanf(input, "%d", &cidr) == 1 && cidr >= 1 && cidr <= 32) {
        ip = 0xffffffffu >> (32-cidr) << (32-cidr);
        mask[0] = (ip >>  0) & 0xff;
        mask[1] = (ip >>  8) & 0xff;
        mask[2] = (ip >> 16) & 0xff;
        mask[3] = (ip >> 24) & 0xff;
    } else {
        fprintf(stderr, "error: not a CIDR\n");
        return 1;
    }

    /* finally print the mask */
    printf("%d.%d.%d.%d\n", mask[3], mask[2], mask[1], mask[0]);
    return 0;
}
