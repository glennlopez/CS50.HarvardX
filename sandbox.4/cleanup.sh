#!/bin/bash

# cleanup routine
shopt -s extglob 
rm -- !(*.c || *.sh)