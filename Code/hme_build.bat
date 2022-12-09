@echo off

mkdir ..\..\build
pushd ..\..\build
cl -Zi ..\Code\win32_handmadeEngine.cpp user32.lib Kernel32.lib
popd



