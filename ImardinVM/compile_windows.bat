:: Imardin Compiler Script

:setup
@echo off
title Imardin Compiler
if not exist compile.log echo --- Imardin Compiler Log --- >compile.log

:compile
echo Compiling ImardinVM...
echo [%date% %time%] Compiling Imardin >>compile.log
tcc\tcc.exe main.c -o imardin.exe -w >>compile.log
if %errorlevel% == 0 echo [%date% %time%] Imardin was successfully compiled >>compile.log
if not %errorlevel% == 0 echo [%date% %time%] There was a compiler error :/ >>compile.log
pause
del compile.log