cidr2ip
======
`cidr2ip` is a small and simple program for converting a CIDR into ip (mask).

Installation
------------
Edit config.mk to match your local setup (cidr2ip is installed into the
/usr/local namespace by default), then simply enter the following command to
install (if necessary as root):

    make clean install

Example usage of cidr2ip
------------------------
Print a complete CIDR to ip conversion table

    for i in {1..32}; do printf '\\%-5s' $i; cidr2ip $i;done

