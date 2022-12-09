@echo off

mkdir ..\..\build\release
pushd ..\..\build\release
cl ..\Code\win32_handmadeEngine.cpp user32.lib Kernel32.lib
popd



