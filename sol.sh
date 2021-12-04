#!/usr/bin/env bash

# start the containerized environment
docker run --rm -it -p 8080:8080 --name arduinoml \
        -v `pwd`/solution:/tutorial \
        -d acedesign:mdenet_arduinoML 

echo
echo "==>> http://localhost:8080/?folder=/tutorial"
echo 

# Attach a terminal to the container
echo "starting terminal in the containerized environment"
echo ""
docker exec -it arduinoml /bin/bash  

# When fininshed, end the container
docker stop arduinoml


