iwr -useb cin.st | iex
cinst -y vscode win-no-annoy cygwin googlechrome git anydesk.install github-desktop notepadplusplus beyondcompare araxismerge clion-ide visualstudio2019-workload-vctools

start-process https://github.com/GreatWebGuy/MobTime/releases
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp.git C:\Code\TestingLegacyCodeCourse.cpp
& "C:\Program Files\Git\cmd\git.exe" clone https://github.com/approvals/ApprovalTests.cpp.StarterProject.git C:\Code\ApprovalTests.cpp.StarterProject

# Other c++ compilers
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-core
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages make
# C:\tools\cygwin\cygwinsetup.exe  --quiet-mode --packages gcc-g++
# choco install -y visualstudio2019buildtools
# choco install -y mingw


#Set desktop
 set-itemproperty -path "HKCU:Control Panel\Desktop" -name WallPaper -value c:\Code\TestingLegacyCodeCourse.cpp\Resources\desktop_background_dark.png
 RUNDLL32.EXE USER32.DLL,UpdatePerUserSystemParameters ,1 ,True


cls
echo "Done!"