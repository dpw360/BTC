#! /bin/bash

sed 's/Unknown/Purple/g' $1 | sort | tr [:upper:] [:lower:] | sed 's/\(\b[a-z]\)/\U\1/g' | awk '{print "I am " $2 " " $1 ". My favorite color is " $3 }'

## First, we replace all Unknown favorite colors as Purple.

## We then pipe it into the sort function, which sorts the stream alphabetically
## by default.

## That's piped into the tr command, which changes all upper case characters to
## lower case. This means the whole stream is lower-case.

## That's then piped into another sed command, where we use RegEx to grab the
## first character after a non-word character, and change it to upper-case.

## We then pipe that into the awk function, to print it in the correct order.