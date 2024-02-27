## This block recurses through the C:\Windows directory looking for any file
## that follows *.dll pattern. Those objects are stored in the $list variable
## as an array.
Write-Host "Please wait, currently finding .dll's ..."
$list = Get-ChildItem -Path 'C:\Windows' -Filter '*.dll' -Recurse

## We store the count of the objects as a variable then print how many we found.
$numFiles = $list.Count
Write-Host "You have $numFiles's dll's in you C:\Windows directory.`nPlease wait while your .csv is generated"

## We create the dll.csv at the specified path
New-Item -Path 'C:\Users\Drew\Documents\dll.csv' -ItemType File

## This for loop iterates through the last 100 elements of the $list, stores
## the name and last write time as variables, and appends the dll.csv file
## with that information formatted correctly.
for ($i = $numFiles - 1; $i -ge $numFiles - 100; $i--) {
    $dllName = $list[$i].Name
    $dllModified = $list[$i].LastWriteTime
    Add-Content -Path 'C:\Users\Drew\Documents\dll.csv' -Value "$dllName, $dllModified"
}

## Print that we're done!
Write-Host "Done!"