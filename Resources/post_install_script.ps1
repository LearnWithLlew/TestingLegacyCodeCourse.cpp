# To run this script directly, run this in a NON-elevated admin PowerShell prompt,
# after install_script.ps1 has been installed
#     Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/master/Resources/post_install_script.ps1 | Invoke-Expression

# You may need to run this to enable scripts to be run:
#     Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted

# -------------------------------------------------------
# Install Visual Studio plugins

# Auto Save: https://marketplace.visualstudio.com/items?itemName=HangjitRai.AutoSaveFile
iwr https://marketplace.visualstudio.com/_apis/public/gallery/publishers/HRai/vsextensions/AutoSaveFile/2.4/vspackage -O AutoSaveFile.vsix

# Markdown Editor: https://github.com/madskristensen/MarkdownEditor
iwr https://marketplace.visualstudio.com/_apis/public/gallery/publishers/MadsKristensen/vsextensions/MarkdownEditor/1.12.253/vspackage -O MarkdownEditor.vsix

# Catch2 test adapter:  https://marketplace.visualstudio.com/items?itemName=JohnnyHendriks.ext01
iwr https://marketplace.visualstudio.com/_apis/public/gallery/publishers/JohnnyHendriks/vsextensions/ext01/1.5.1/vspackage -O Catch2TestAdapter.vsix

# VSColorOutput: https://marketplace.visualstudio.com/items?itemName=MikeWard-AnnArbor.VSColorOutput
iwr https://marketplace.visualstudio.com/_apis/public/gallery/publishers/MikeWard-AnnArbor/vsextensions/VSColorOutput/2.71/vspackage -O VSColorOutput.vsix

# OpenCppCoverage: https://marketplace.visualstudio.com/items?itemName=OpenCppCoverage.OpenCppCoveragePlugin
# This will be installed by students during the course
# iwr https://marketplace.visualstudio.com/_apis/public/gallery/publishers/OpenCppCoverage/vsextensions/OpenCppCoveragePlugin/0.9.7.1/vspackage -O OpenCppCoverage.vsix

start .
Write-Host -Foreground yellow "Run and install *.vsix"

# -------------------------------------------------------
# Set up build spaces

& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
Push-Location C:\Code\TestingLegacyCodeCourse.cpp
& ".\build-and-test.ps1"
Pop-Location

# Done
# cls
echo "Done!"
