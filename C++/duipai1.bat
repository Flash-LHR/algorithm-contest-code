@echo off
:loop
rand>input.txt
my<input.txt>output.txt
std<input.txt>output2.txt
fc output.txt output2.txt
if not errorlevel 1 goto loop

pause

goto loop