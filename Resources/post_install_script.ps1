# To run this script directly, run this in a NON-elevated admin PowerShell prompt,
# after install_script.ps1 has been installed
#     Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/post_install_script.ps1 | Invoke-Expression

# You may need to run this to enable scripts to be run:
#     Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted

# -------------------------------------------------------
# Set up build spaces

& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
Push-Location C:\Code\TestingLegacyCodeCourse.cpp
mkdir  -force cmake-build-vs2019-x64
Push-Location cmake-build-vs2019-x64
cmake -G "Visual Studio 16 2019" -A x64 ..
Pop-Location
Pop-Location

# Done
# cls
echo "Done!"
