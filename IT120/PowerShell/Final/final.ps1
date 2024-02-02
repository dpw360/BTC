# Goal Output
# "Password","First","Last","Userid","FullName"
# "734-44-2041-000","James","Smith","jsmith","James Smith"
# "655-84-8254-000","John","Johnson","jjohnson","John Johnson"
# "138-49-0705-000","Robert","Williams","rwilliams","Robert Williams"
# "329-17-8632-000","Michael","Jones","mjones","Michael Jones"

# New-Item -Path '.\Final.csv' -ItemType File

$i = 0
$currentFirst = $currentLast = ""

foreach ($item in Get-Content -Path .\Final.txt) {
    $item | Select-String -Pattern "^*" -AllMatches
}

## Gives the following wrong output:
# 734-44-2041, James, Smith, jsmith
# 655-84-8254, James Smith
# John, Johnson, jjohnson
# 138-49-0705, Robert, Johnson jjohnson
# 138-49-0705
# Williams, rwilliams
# 329-17-8632, Michael, Jones, rwilliams
# 329-17-8632 Michael
# mjones