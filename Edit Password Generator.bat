@ECHO OFF
REM This script requires the following environment variables to be set:
REM 1. DEVENV_ROOT_2022
REM 2. QTDIR_ROOT

IF "%DEVENV_ROOT_2022%" == "" (
	ECHO Please specify the following environment variables: DEVENV_ROOT_2022
	goto PAUSE_END
)

IF "%QTDIR_ROOT%" == "" (
	ECHO Please specify the following environment variables: QTDIR_ROOT
	goto PAUSE_END
)

REM Setup eviroment
SET QTDIR=%QTDIR_ROOT%
SET QDIR=%QTDIR%

START "" "%DEVENV_ROOT_2022%\devenv.exe" "C:\Repos\Password-Generator\PasswordGenerator.vcxproj"

GOTO END

:PAUSE_END
pause
GOTO END

:END
