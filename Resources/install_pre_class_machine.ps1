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
choco install -y win-no-annoy anydesk notepadplusplus

# Done
Write-Host -Foreground yellow "Reboot when done"
