:: Imardin Compiler Script

:setup
@echo off
title Imardin Compiler

:compile
tcc\tcc\tcc.exe main.c -o imardin.exe
echo Done.
pause >nul