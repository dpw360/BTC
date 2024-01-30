## Prompt the user for their name, and store it
$myName = Read-Host "What is your name?"

## The counting up block. We start at one. As long as the intUp is less than or
## equal to 8, we write the value of intUp to the terminal, and increment. The
## while loop ensures that once we reach 8, it leaves the loop.
$intUp = 1
while ($intUp -le 8) {
    Write-Host "$intUp"
    $intUp++
}

## The counting down block. We start at 8, decrementing by one every iteration
## and as long as the intDown is less greater than or equal to 1, we write the
## value of intDown to the terminal. The for loop does the decrementing for us.
for (($intDown = 8); $intDown -ge 1; $intDown--) {
    Write-Host "$intDown"
}

## We write the variable myName to the terminal.
Write-Host "Hello my name is $myName"