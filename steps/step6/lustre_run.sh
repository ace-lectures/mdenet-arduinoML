#!/bin/sh

# Script d'installation de Lustre
# Thierry Excoffier pour MIF25, 2017
# Modifié pour CR10, ENSL 2017
# Modifié pour MDENet, mosser, 2021

###################################################
# Configure l'environnement
###################################################

V="linux64/lustre-v4-XX-0-linux64" 
NOM="$(basename "$V")"

OLD=$(pwd)
cd "/lustre/$NOM"
export LUSTRE_INSTALL="$(pwd)"
. ./setenv.sh
cd $OLD
export PS1="\[\e[0m\]## LUSTRE ## \[\e[0m\]\W\[\e[0m\]$\[\e[0m\] "
echo "############################################################
Some Examples
   cd $LUSTRE_INSTALL/examples/     # Official Lustre tests
   # Simulate a node
   luciole filename.lus node
   # Compile (see the provided makefile)
############################################################
For the arduino led
   cd $(pwd)/LustreArduino
   make all upload
############################################################
If you quit this shell, you quit the Lustre environment.
############################################################
"

exec /bin/bash --norc
