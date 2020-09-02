# To run this script directly, run this in an elevated admin PowerShell prompt:
#     Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/install_quiz_machine.ps1 | Invoke-Expression

# You may need to run this to enable scripts to be run:
#     Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted

# -------------------------------------------------------
#install chocolatey
Invoke-WebRequest -useb cin.st | Invoke-Expression
choco feature disable -n=showDownloadProgress

# -------------------------------------------------------
#install common tools
choco install -y win-no-annoy notepadplusplus

choco install -y --ignore-checksums anydesk
start C:\ProgramData\chocolatey\lib\anydesk.portable\tools\
Write-Host -Foreground yellow "Pin AnyDesk to Task Bar - and add short cut to desktop"

# Done
Write-Host ""
Write-Host -Foreground yellow "Reboot when done"
