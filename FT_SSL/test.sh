#!/bin/bash
make > /dev/null
echo "test MD5:"
echo "pickle" | ./ft_ssl md5
echo "pickle" | openssl md5
echo
echo "test SHA256:"
echo "pickle" | ./ft_ssl sha256
echo "pickle" | openssl sha256
echo
echo "test SHA224:"
echo "pickle" | ./ft_ssl sha224
echo "pickle" | openssl sha224
echo
echo "test file:"
./ft_ssl sha256 test.sh
openssl sha256 test.sh
echo
./ft_ssl sha256 test.sh
openssl sha256 test.sh
echo
echo "test -s:"
./ft_ssl sha224 -s"Do not pity the dead, Harry"
./ft_ssl sha224 -s "Do not pity the dead, Harry"
echo
./ft_ssl sha224 -sHarry
./ft_ssl sha224 -s Harry
echo
./ft_ssl sha224 -sHarry -s Ron
echo 
echo "test -q:"
./ft_ssl sha224 -sHarry -q
echo
echo "test -p:"
echo -n "Harry" | ./ft_ssl sha224 -p
./ft_ssl sha224 -sHarry -q
echo
echo "test -r:"
./ft_ssl sha224 -s"Do not pity the dead, Harry"
make fclean > /dev/null