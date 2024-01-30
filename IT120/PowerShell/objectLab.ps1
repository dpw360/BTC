$list = Get-ChildItem -Path 'C:\Windows' -Filter '*.dll' -Recurse
$numFiles = $list.Count
Write-Host $numFiles