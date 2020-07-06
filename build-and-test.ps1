mkdir  -force cmake-build-vs2019-x64
Push-Location cmake-build-vs2019-x64

$Env:GTEST_COLOR = "1"

cmake -G "Visual Studio 16 2019" -A x64 ..
cmake --build . --config Debug
ctest . --build-config Debug --output-on-failure

Pop-Location
