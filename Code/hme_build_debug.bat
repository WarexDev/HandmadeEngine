@echo off

mkdir ..\..\build\debug
pushd ..\..\build\debug
cl -Zi ..\Code\win32_handmadeEngine.cpp user32.lib Kernel32.lib
popd



