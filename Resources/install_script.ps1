# To run this script directly, run this in an elevated admin PowerShell prompt:
#     Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/install_script.ps1 | Invoke-Expression

# You may need to run this to enable scripts to be run:
#     Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted

# -------------------------------------------------------
#install chocolatey
Invoke-WebRequest -useb cin.st | Invoke-Expression
choco feature disable -n=showDownloadProgress

# -------------------------------------------------------
#install common tools
choco install -y vscode win-no-annoy git github-desktop anydesk.install googlechrome notepadplusplus
start-process https://github.com/GreatWebGuy/MobTime/releases
Set-Service Audiosrv -StartupType Automatic

#install project specific tools
choco install -y cygwin notepadplusplus beyondcompare araxismerge clion-ide visualstudio2019-workload-vctools

# -------------------------------------------------------
# Clone repo
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp.git C:\Code\TestingLegacyCodeCourse.cpp
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/approvals/ApprovalTests.cpp.StarterProject.git C:\Code\ApprovalTests.cpp.StarterProject

# Other c++ compilers
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-core
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages make
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-g++
# choco install -y visualstudio2019buildtools
# choco install -y mingw


#Set desktop background image
 set-itemproperty -path "HKCU:Control Panel\Desktop" -name WallPaper -value c:\Code\TestingLegacyCodeCourse.cpp\Resources\desktop_background_dark.png
 RUNDLL32.EXE USER32.DLL,UpdatePerUserSystemParameters ,1 ,True

# Done
# cls
echo "Done!"
