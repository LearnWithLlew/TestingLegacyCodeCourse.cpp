# To run this script directly, run this in a NON-elevated admin PowerShell prompt,
# after install_script.ps1 has been installed
#     Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/post_install_script.ps1 | Invoke-Expression

# You may need to run this to enable scripts to be run:
#     Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted

# -------------------------------------------------------
# Install Visual Studio plugins
# TODO https://stackoverflow.com/questions/30574829/how-to-install-visual-studio-gallery-extensions-from-command-line

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
