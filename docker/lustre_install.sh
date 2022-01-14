#!/bin/sh

# Script d'installation de Lustre
# Thierry Excoffier pour MIF25, 2017
# Modifié pour CR10, ENSL 2017
# Modifié pour MDENet, mosser, 2021


###################################################
# Détermine les paquets à installer sur le système
###################################################

NEED=""
[ "$(which avr-gcc)" = "" ] && NEED="$NEED gcc-avr"
#[ "$(which arduino)" = "" ] && NEED="$NEED arduino"
[ "$(which tclsh)"   = "" ] && NEED="$NEED tcl"
if [ "$NEED" != "" ]
then
    echo "Vous devez installer les paquets suivants :"
    echo "    apt-get install    $NEED"
    exit 1
fi >&2

set -e # Arrête le script en cas de problème


###################################################
# Install LUSTRE
###################################################

# http://www-verimag.imag.fr/~raymond/?p=148

V="linux64/lustre-v4-XX-0-linux64" 
NOM="$(basename "$V")"
TGZ="http://www-verimag.imag.fr/DIST-TOOLS/SYNCHRONE/lustre-v4/distrib/$V.tgz"

if [ ! -d "$NOM" ]
then
    if [ ! -f "$NOM.tgz" ]
    then
	wget "$TGZ"
    fi
    zcat <"$NOM.tgz" | tar -xvf -
fi

rm -rf "$NOM.tgz"

###################################################
# Ajoute la commande wish si elle manque
###################################################

echo ln -s /usr/bin/tclsh8.6 "$NOM"/bin/wish


