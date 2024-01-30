#! /bin/bash

## Store the flag and filePath as variables for readability.
flag=$1
filePath=$2

## If the flag is not -c, print an error message. Otherwise, -c was used and
## the program can continue.
if [[ $flag != "-c" ]]
then
    echo You should use the \-c flag!
else
    ## Prompt for name and favorite color, and store in vars.
    echo -n Enter your name: ''
    read name

    echo -n Enter your favorite color: ''
    read faveColor

    ## This statement tests if the directory /tmp/faveColor exists. If it does,
    ## print out that it already exists. Otherwise continue.
    if [ -d /tmp/$faveColor ]
    then
        echo Bad luck $name, /tmp/$faveColor/ already exists.
    else
        ## Make the directory, and cd into it.
        mkdir /tmp/$faveColor/
        cd /tmp/$faveColor/

        ## Create the file, and append the empty midterm.csv file with header.
        touch midterm.csv
        echo Firstname,Lastname,Maildomain,Password >> midterm.csv

        ## GOAL OUTPUT
        ## firstname,lastname,email,maildomain-000

        ## First, we grab the contents of the file at filepath using cat.

        ## We then turn everything in the stream into lowercase using tr.

        ## We finally use awk to format the data, and append that into
        ## the csv file.
        cat $filePath | tr [:upper:] [:lower:] | awk '{print $3 "," $4 "," $5 "," $2 "-000"}' >> midterm.csv
    fi
fi
