#!/bin/bash
make;
#test is buggy at the moment
touch ./client/client_hello
echo "hello this is client" > ./client/client_hello 
touch ./client1/client1_hello
echo "hello this is client1" > ./client1/client1_hello
touch ./server/server_hello
echo "hello this is server" > ./server/server_hello
#while PID_SRVR == $$
#sleep 100
PORT=$((RANDOM % 100 + 5000))
cd ./server
./server $PORT &
PID_SRVR=$!
cd ..
sleep 1
cd client 
PID_CLNT=$!
cat ../client_test | ./client localhost $PORT &
cd ../client1
cat  ../client1_test | ./client1 localhost $PORT &
PID_CLNT1=$!
cd ..
sleep 2
pkill server
pkill client2 
pkill client
make fclean 