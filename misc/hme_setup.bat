@echo off
subst f: E:\Dev\HandmadeEngine
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
set path=E:\Dev\HandmadeEngine\misc;%path%
set path=E:\Dev\HandmadeEngine\Code;%path%
start E:\Dev\HandmadeEngine\Code\win32_handmadeEngine.cpp