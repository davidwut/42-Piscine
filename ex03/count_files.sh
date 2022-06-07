#!/bin/bash
find . \( -type f -o -type d \) | wc -l | tr -d ' '
#find . | wc -l | bc