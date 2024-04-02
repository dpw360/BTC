## Create the empty Final.csv file, and append the header row
New-Item -Path '.\Final.csv' -ItemType File
Add-Content -Path '.\Final.csv' -Value "Password, First, Last, Userid, FullName"

## For each line in the input text, I split the contents of the line into an
## array using -split, with a space as the delineator. I then store all of
## the data from the line in appropriate variables, performing some formatting
## on the password and fullName data. Finally, we append the Final.csv file
## with the correctly formatted data.
foreach ($line in Get-Content -Path '.\Final.txt') {
    $items = $line -split ' '

    $password = $items[0] + "-000"
    $first = $items[1]
    $last = $items[2]
    $userID = $items[3]
    $fullName = "$first $last"
    
    Add-Content -Path '.\Final.csv' -Value "$password, $first, $last, $userID, $fullName"
}