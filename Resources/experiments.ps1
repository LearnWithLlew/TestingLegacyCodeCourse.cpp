choco install -y visualstudio2019community
choco install -y cmake --installargs 'ADD_CMAKE_TO_PATH=System'
choco install -y cmake --force --installargs 'ADD_CMAKE_TO_PATH=System'  'ALLUSERS=1' 'DESKTOP_SHORTCUT_REQUESTED=1'
choco install -y visualstudio2019-workload-nativedesktop
