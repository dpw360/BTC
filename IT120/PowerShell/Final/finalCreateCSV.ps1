# Goal Output
# "Password","First","Last","Userid","FullName"
New-Item -Path '.\Final.csv' -ItemType File
Add-Content -Path '.\Final.csv' -Value "Password First Last Userid FullName"

foreach ($line in Get-Content -Path .\Final.txt) {
    $items = $line -split ' '

    $password = $items[0] + "-000"
    $first = $items[1]
    $last = $items[2]
    $userID = $items[3]
    $fullName = "$first $last"
    
    Add-Content -Path '.\Final.csv' -Value "$password, $first, $last, $userID, $fullName"
}