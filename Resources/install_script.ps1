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
choco install -y vscode win-no-annoy anydesk.install googlechrome notepadplusplus
start-process https://github.com/GreatWebGuy/MobTime/releases
Set-Service Audiosrv -StartupType Automatic

# -------------------------------------------------------
# Version Control
choco install -y git github-desktop

# -------------------------------------------------------
#install project specific tools

# -------------------------------------------------------
# Diff Tools
choco install -y beyondcompare araxismerge

# -------------------------------------------------------
# IDEs and editors
choco install -y clion-ide
choco install -y visualstudio2019community
choco install -y visualstudio2019-workload-nativedesktop

# TODO Install these VS extensions manually
# https://stackoverflow.com/questions/30574829/how-to-install-visual-studio-gallery-extensions-from-command-line
# Extensions to install:
#  Catch2 test adapter:
#    https://marketplace.visualstudio.com/items?itemName=JohnnyHendriks.ext01
#    https://marketplace.visualstudio.com/_apis/public/gallery/publishers/JohnnyHendriks/vsextensions/ext01/1.5.1/vspackage
#  OpenCppCoverage
#    https://marketplace.visualstudio.com/items?itemName=OpenCppCoverage.OpenCppCoveragePlugin
#    https://marketplace.visualstudio.com/_apis/public/gallery/publishers/OpenCppCoverage/vsextensions/OpenCppCoveragePlugin/0.9.7.1/vspackage
#  VSColorOutput
#    https://marketplace.visualstudio.com/items?itemName=MikeWard-AnnArbor.VSColorOutput
#    https://marketplace.visualstudio.com/_apis/public/gallery/publishers/MikeWard-AnnArbor/vsextensions/VSColorOutput/2.71/vspackage

# Cannot get OpenCppCoverage working - logged an issue:
#  https://github.com/OpenCppCoverage/OpenCppCoveragePlugin/issues/38

# -------------------------------------------------------
# Clone repo
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp.git C:\Code\TestingLegacyCodeCourse.cpp
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/approvals/ApprovalTests.cpp.StarterProject.git C:\Code\ApprovalTests.cpp.StarterProject

# -------------------------------------------------------
# CygWin
# choco install -y cygwin
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-core
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages make
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-g++

# -------------------------------------------------------
# mingw
# choco install -y mingw


#Set desktop background image
 set-itemproperty -path "HKCU:Control Panel\Desktop" -name WallPaper -value c:\Code\TestingLegacyCodeCourse.cpp\Resources\desktop_background_dark.png
 RUNDLL32.EXE USER32.DLL,UpdatePerUserSystemParameters ,1 ,True

# Done
# cls
echo "Done!"
