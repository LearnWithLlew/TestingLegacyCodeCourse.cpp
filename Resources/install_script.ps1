# To run this script directly, run this in an elevated admin PowerShell prompt:
#     Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/install_script.ps1 | Invoke-Expression

# You may need to run this to enable scripts to be run:
#     Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted

iwr -useb https://raw.githubusercontent.com/JayBazuzi/machine-setup/main/windows.ps1 | iex
choco install typora

iwr -useb https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/install_cpp_clion_visual_studio.ps1 | iex

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
Write-Host -Foreground yellow "Reboot when done"
