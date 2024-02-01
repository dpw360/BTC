Write-Host "Please wait, currently finding .dll's ..."
$list = Get-ChildItem -Path 'C:\Windows' -Filter '*.dll' -Recurse

$numFiles = $list.Count
Write-Host "You have $numFiles's dll's in you C:\Windows directory.`nPlease wait while your .csv is generated"

New-Item -Path 'C:\Users\Drew\Documents\dll.csv' -ItemType File

for ($i = $numFiles - 1; $i -gt $numFiles - 100; $i--) {
    Out-File -FilePath 'C:\Users\Drew\Documents\dll.csv' $list[$i].Name
}