@echo off
:loop
rand>input.txt
l<input.txt>output.txt
bao<input.txt>output2.txt
fc output.txt output2.txt
if not errorlevel 1 goto loop

pause

goto loop