@echo off

REM Arguments: SourceDir TargetDir
set "SourceDir=%1"
set "TargetDir=%2"

REM Copy command 1
xcopy "%SourceDir%\res\*" "%TargetDir%\res\" /e /h /y

REM Copy command 2
xcopy "%SourceDir%\raylib-3.7.0_win32_msvc16\*" "%TargetDir%\" /e /h /y /exclude:exclude.txt

REM Copy command 3
xcopy "%SourceDir%\raylib-4.5.0_win64_msvc16\*" "%TargetDir%\" /e /h /y /exclude:exclude.txt
