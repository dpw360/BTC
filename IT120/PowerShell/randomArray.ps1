## We initialize the array with 1000 entries, and then fill it with 1000 random
## numbers between 0 and 1000 inclusive.
$randArray = @($null) * 1000
for ($i = 0; $i -lt 1000; $i++) {
    $randArray[$i] = Get-Random -Minimum 0 -Maximum 1000
}

## If 42 is in the array, we can say so and exit.
if (42 -in $randArray) {
    Write-Host "The answer to life the universe and everything is found"
## Else, we check if the user dadams exists, and store that bool value in a var.
} else {
    $userExists = (Get-LocalUser).Name -Contains "dadams"

    ## If it does exist, we delete the user and print a messgae.
    if ($userExists) {
        Remove-LocalUser -Name "dadams"
        Write-Host "So long and thanks for all the fish!"
    ## If it doesn't, we create the user, specifying the username, full name,
    ## and that no password is required.
    } else {
        New-LocalUser -Name "dadams" -FullName "Douglas Adams" -NoPassword
    }
}