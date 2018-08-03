# cidr2ip
Converts CIDR to IPADDRESS

install using `cp ./cidr2ip /usr/local/bin` or similar.

## print complete table
```
for i in {1..32}; do printf '\\%-5s' $i; cidr2ip $i;done
```
