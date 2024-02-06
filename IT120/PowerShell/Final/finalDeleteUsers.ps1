## Imports the data into the csvData variable.
$csvData = Import-Csv -Path '.\Final.csv'

## For each row in the .csv data, I use the userID information to delete the
## user accounts.
foreach ($row in $csvData) {
    Remove-LocalUser -Name $row.userID -WhatIf
}