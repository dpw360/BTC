## Imports the data into the csvData variable.
$csvData = Import-Csv -Path '.\Final.csv'

## For each row in the .csv file, I convert the password string into a secure
## string, so that the New-LocalUser command will accept it as a password. I
## then use the data in the .csv file to create a new user with the desried
## attributes. All users are described as "test accounts".
foreach ($row in $csvData) {
    $securePassword = ConvertTo-SecureString $row.Password -AsPlainText -Force
    New-LocalUser -Name $row.userID -FullName $row.FullName -Password $securePassword -Description "test account"
}