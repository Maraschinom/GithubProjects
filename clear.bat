@REM @Author: Maraschino
@REM @Date:   2021-09-17 10:31:16
@REM @Last Modified by:   Maraschino
@REM Modified time: 2021-09-17 10:32:11

@echo off

attrib -h G:\Code\*.exe /s
del /s /q /f G:\Code\*.exe

pause

cls

echo ÊÇ·ñÉ¾³ýstd

set /p num=

if "%num%"=="1"
(
attrib -h G:\Code\std.cpp /s
del /s /q /f G:\Code\std.cpp
pause
)