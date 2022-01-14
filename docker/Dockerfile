
FROM ubuntu:focal

###
# Install VisualStudio IDE - Web server
###

RUN apt-get update && apt-get install -y curl
WORKDIR /codeserver 
RUN curl -fOL https://github.com/coder/code-server/releases/download/v4.0.1/code-server_4.0.1_amd64.deb
RUN dpkg -i code-server_4.0.1_amd64.deb
COPY ./code_server.yml  /root/.config/code-server/config.yaml

###
# Tutorial-related packages
###

# Arduino
RUN apt-get update && apt-get install -y make arduino-core gcc-avr avrdude avr-libc

# Java (maven installs Java transitively)
RUN apt-get update && apt-get install -y maven 

# Lustre
WORKDIR /lustre
RUN apt-get update && apt-get install -y wget tcl
COPY ./lustre_install.sh .
RUN ./lustre_install.sh

###
# Operational concerns
###

# Where to mount the tutorial file
VOLUME ["/tutorial"]
WORKDIR /tutorial

# starting the visual studio code web service
ENTRYPOINT [ "/usr/bin/code-server", "/tutorial"]

