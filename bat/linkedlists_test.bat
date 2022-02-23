@echo off
set BAT_BASE_PATH=%~dp0
set PRJ_BASE_PATH=%BAT_BASE_PATH%..
set BIN_PATH=%PRJ_BASE_PATH%\bin
set CORE_PATH=%PRJ_BASE_PATH%\ds-core
set TEST_PATH=%PRJ_BASE_PATH%\ds-test

MD %BIN_PATH%
clang -I%TEST_PATH%\include -I%CORE_PATH%\include ^
    -o %BIN_PATH%\test_linkedlists.exe %TEST_PATH%\src\main_test_linkedlists.c ^
    -L %BIN_PATH% -l linkedlists && %BIN_PATH%\test_linkedlists.exe