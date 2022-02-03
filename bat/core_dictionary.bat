@echo off
set BAT_BASE_PATH=%~dp0
set PRJ_BASE_PATH=%BAT_BASE_PATH%..
set BIN_PATH=%PRJ_BASE_PATH%\bin
set CORE_PATH=%PRJ_BASE_PATH%\ds-core

MD %BIN_PATH%
clang ^
    -I%CORE_PATH%\include ^
    -o %BIN_PATH%\mydictionary.lib ^
    %CORE_PATH%\src\dictionary.c ^
    -fuse-ld=llvm-lib