#! /bin/bash

# This initializes the variables we'll need. We randomize the number to guess
# between 1 and 10, set the attempted tries to zero, and the limit to 3.
numberToGuess=$(( $RANDOM % 10 + 1 ))
tries=0
triesLimit=3

# This loop will continue to run as long as they haven't used all of their
# allotted guesses, or until we break out of it if they guess correctly.
while [ $tries -lt $triesLimit ];
do
    # Prompt the user for their guess and store it in $guess
    echo -n Enter a number to guess: ''
    read guess

    # If they guessed correctly, print 'You win!' and break out of the loop,
    # ending the program.
    if [ $guess -eq $numberToGuess ]
    then
        echo You win!
        break
    # Else, they guessed incorrectly. We incremement the $tries variable, as
    # they have used a try, and then test further.
    else
        let "tries++"

        # If they have used all their allotted tries, we print the correct
        # number, and on the next loop test, it will fail and the program will
        # end. Else if the guess is too low, we prompt that they should guess
        # higher. Else, we prompt that they should guess lower.
        if [ $tries -eq $triesLimit ]
        then
            echo Sorry, the correct answer was $numberToGuess. Better luck next time!
        elif [ $guess -lt $numberToGuess ]
        then
            echo The number is higher than $guess.
        else
            echo The number is lower than $guess.
        fi
    fi
done