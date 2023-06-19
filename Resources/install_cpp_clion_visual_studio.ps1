# To run this script directly, run this in an elevated admin PowerShell prompt:
#     Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/install_cpp_clion_visual_studio.ps1 | Invoke-Expression

#Requires -RunAsAdministrator

iwr -useb cin.st | iex
choco feature enable --name=allowGlobalConfirmation

# -------------------------------------------------------
# Diff Tools
choco install  tortoisesvn

# -------------------------------------------------------
# IDEs and editors
choco install clion-ide
choco install visualstudio2022community
choco install visualstudio2022-workload-nativedesktop

choco install resharpercpp

# -------------------------------------------------------
# Build tools
choco install cmake.install --installargs 'ADD_CMAKE_TO_PATH=System'
choco install ninja conan

# -------------------------------------------------------
# CygWin
# cinst cygwin
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-core
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages make
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-g++

# -------------------------------------------------------
# mingw
# cinst mingw

Write-Host -Foreground yellow "Reboot when done"
