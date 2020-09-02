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
choco install -y vscode win-no-annoy googlechrome notepadplusplus adobereader

choco install -y --ignore-checksums anydesk
start C:\ProgramData\chocolatey\lib\anydesk.portable\tools\
Write-Host -Foreground yellow "Pin AnyDesk to Task Bar - and add short cut to desktop"

$ProgressPreference = 'SilentlyContinue'

$mobtimeVersion = '1.7.4'
iwr https://github.com/GreatWebGuy/MobTime/releases/download/v$mobtimeVersion/MobTime-$mobtimeVersion.msi -O MobTime.msi
./MobTime.msi /qr

Set-Service Audiosrv -StartupType Automatic

# -------------------------------------------------------
# Version Control
choco install -y git github-desktop

# -------------------------------------------------------
#install project specific tools

# -------------------------------------------------------
# Diff Tools
choco install -y beyondcompare

# -------------------------------------------------------
# IDEs and editors
choco install -y clion-ide
choco install -y visualstudio2019community
choco install -y visualstudio2019-workload-nativedesktop

choco install -y resharpercpp

# -------------------------------------------------------
# Build tools
choco install -y cmake.install --installargs 'ADD_CMAKE_TO_PATH=System'
choco install -y ninja conan

# -------------------------------------------------------
# CygWin
# choco install -y cygwin
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-core
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages make
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-g++

# -------------------------------------------------------
# mingw
# choco install -y mingw

# -------------------------------------------------------
# Clone repos
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp.git C:\Code\TestingLegacyCodeCourse.cpp
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/LearnWithLlew/TestingLegacyCodeCourse.slides.git C:\Code\TestingLegacyCodeCourse.slides
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/claremacrae/talks.git C:\Code\CourseResources

#Set desktop background image
 set-itemproperty -path "HKCU:Control Panel\Desktop" -name WallPaper -value c:\Code\TestingLegacyCodeCourse.cpp\Resources\desktop_background_dark.png
 RUNDLL32.EXE USER32.DLL,UpdatePerUserSystemParameters ,1 ,True

# Done
# cls
echo "Done!"
