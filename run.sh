#!/usr/bin/env bash

# start the containerized environment
echo "Starting the containerized environment"
docker run --rm -it -p 8080:8080 --name arduinoml \
        -v `pwd`/steps:/tutorial \
        -d acedesign/arduinoml 

echo ""
echo "to access the built-in IDE and start working on the tutorial:"
echo "==>> http://localhost:8080/?folder=/tutorial"
echo 

# Attach a terminal to the container
echo "Now starting a terminal in the containerized environment"
echo "Use `exit` to quit the environment."
echo ""
docker exec -it arduinoml /bin/bash  

# When finished, end the container
docker stop arduinoml


