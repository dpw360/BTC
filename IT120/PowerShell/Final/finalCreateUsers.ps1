$csvData = Import-Csv -Path '.\Final.csv'
foreach ($row in $csvData) {
    $securePassword = ConvertTo-SecureString $row.Password -AsPlainText -Force
    New-LocalUser -Name $row.userID -FullName $row.FullName -Password $securePassword -Description "test account" -WhatIf
}