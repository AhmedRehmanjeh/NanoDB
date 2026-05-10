@echo off
echo ========================================
echo   NanoDB Automated Test Runner
echo ========================================

echo 1. Compiling NanoDB...
g++ -o NanoDB.exe test_runner.cpp src/logger/Logger.cpp src/pager/BufferPool.cpp src/parser/Parser.cpp src/storage/DiskManager.cpp src/storage/Loader.cpp src/storage/Table.cpp src/optimizer/JoinOptimizer.cpp -Iinclude -std=c++11

if %errorlevel% neq 0 (
    echo [ERROR] Compilation failed!
    pause
    exit /b %errorlevel%
)

echo 2. Running Automated Tests...
NanoDB.exe

echo ========================================
echo   Tests Completed Successfully
echo ========================================
pause
