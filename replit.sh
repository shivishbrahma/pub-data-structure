# !/bin/bash

# Color Constants
RESTORE='\033[0m'

RED='\033[00;31m'
GREEN='\033[00;32m'
YELLOW='\033[00;33m'
BLUE='\033[00;34m'
PURPLE='\033[00;35m'
CYAN='\033[00;36m'
LIGHTGRAY='\033[00;37m'

LRED='\033[01;31m'
LGREEN='\033[01;32m'
LYELLOW='\033[01;33m'
LBLUE='\033[01;34m'
LPURPLE='\033[01;35m'
LCYAN='\033[01;36m'
WHITE='\033[01;37m'


if [ -d ../build ]; then
    rm -rf ../build
fi
mkdir -p ../build
cd ../build
cmake ../pub-data-structure/
make

if [ -f ./pub_ds_test ]; then
    printf "\n${LBLUE}Running tests...${RESTORE}\n"
    ./pub_ds_test
else
    printf "\n${LRED}Error: ./pub_ds_test not found.${RESTORE}\n"
fi

if [ -f ./pub_ds_main ]; then
    printf "\n${LBLUE}Running main...${RESTORE}\n"
    ./pub_ds_main
else
    printf "\n${LRED}Error: ./pub_ds_main not found.${RESTORE}\n"
fi

cd ../pub-data-structure/