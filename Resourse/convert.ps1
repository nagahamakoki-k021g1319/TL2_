$files = Get-Item *.png

$options = "-ml 1" 

foreach($f in $files)
{
    Start-Process -FilePath TextureConverter.exe -ArgumentList $f -Wait
    Write-Output $f
    Start-Process -FilePath TextureConverter.exe -ArgumentList $f,$options -Wait
}
pause