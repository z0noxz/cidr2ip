.POSIX:

include config.mk

SRC = cidr2ip.c
OBJ = $(SRC:.c=.o)

all: options cidr2ip

options:
	@echo cidr2ip build options:
	@echo "CC      = $(CC)"

.c.o:
	$(CC) $(STCFLAGS) -c $<

$(OBJ): config.mk

cidr2ip: $(OBJ)
	$(CC) -g -o $@ $(OBJ) $(STLDFLAGS)

clean:
	rm -f cidr2ip $(OBJ)

install: cidr2ip
	mkdir -p /usr/local/bin
	cp -f cidr2ip /usr/local/bin
	chmod 755 /usr/local/bin/cidr2ip

uninstall:
	rm -f /usr/local/bin/cidr2ip

.PHONY: all options clean install uninstall
