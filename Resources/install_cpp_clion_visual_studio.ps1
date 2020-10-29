# To run this script directly, run this in an elevated admin PowerShell prompt:
#     Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/install_cpp_clion_visual_studio.ps1 | Invoke-Expression

#Requires -RunAsAdministrator

iwr -useb cin.st | iex
choco feature enable --name=allowGlobalConfirmation

# -------------------------------------------------------
# Diff Tools
cinst -y  tortoisesvn

# -------------------------------------------------------
# IDEs and editors
cinst -y clion-ide
cinst -y visualstudio2019community
cinst -y visualstudio2019-workload-nativedesktop

cinst -y resharpercpp

# -------------------------------------------------------
# Build tools
cinst -y cmake.install --installargs 'ADD_CMAKE_TO_PATH=System'
cinst -y ninja conan

# -------------------------------------------------------
# CygWin
# cinst -y cygwin
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-core
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages make
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-g++

# -------------------------------------------------------
# mingw
# cinst -y mingw

Write-Host -Foreground yellow "Reboot when done"
