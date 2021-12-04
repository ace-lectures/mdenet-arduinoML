
FROM ubuntu:focal

###
# Install VisualStudio IDE - Web server
###

RUN apt-get update && apt-get install -y curl
WORKDIR /codeserver 
RUN curl -fOL https://github.com/cdr/code-server/releases/download/v3.12.0/code-server_3.12.0_amd64.deb
RUN dpkg -i code-server_3.12.0_amd64.deb
COPY ./code_server.yml  /root/.config/code-server/config.yaml

###
# Tutorial-related packages
###

# Arduino
RUN apt-get update && apt-get install -y make arduino-core gcc-avr avrdude avr-libc

# Java (maven installs Java transitively)
RUN apt-get update && apt-get install -y maven 

# Lustre
RUN apt-get update && apt-get install -y wget tcl

###
# Operational concerns
###

# Where to mount the tutorial file
VOLUME ["/tutorial"]
WORKDIR /tutorial

# starting the visual studio code web service
ENTRYPOINT [ "/usr/bin/code-server", "/tutorial"]

