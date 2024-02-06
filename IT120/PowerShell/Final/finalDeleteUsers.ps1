$csvData = Import-Csv -Path '.\Final.csv'
foreach ($row in $csvData) {
    Remove-LocalUser -Name $row.userID -WhatIf
}