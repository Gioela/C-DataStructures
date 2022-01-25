@echo off
set BAT_BASE_PATH=%~dp0
set PRJ_BASE_PATH=%BAT_BASE_PATH%..
set BIN_PATH=%PRJ_BASE_PATH%\bin
set CORE_PATH=%PRJ_BASE_PATH%\ds-core
set TEST_PATH=%PRJ_BASE_PATH%\ds-test
set TEST_EXE_FILE=%BIN_PATH%\test_linkedlists.exe

MD %BIN_PATH%
clang -I%TEST_PATH%\include -I%CORE_PATH%\include ^
    -o %TEST_EXE_FILE% %TEST_PATH%\src\main_test_doublelinkedlists.c ^
    -L %BIN_PATH% -l doublelinkedlists && %TEST_EXE_FILE%