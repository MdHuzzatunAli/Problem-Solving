@echo off
set /p filename="Enter the C++ file name (without extension): "
g++ -o %filename% %filename%.cpp
%filename%.exe
