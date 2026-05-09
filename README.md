# NanoDB - Architecture & Query Optimizer

A mini database system built from scratch in C++ for the CS-4002 Applied Programming course at FAST-NUCES.

## Project Structure
```text
NanoDB/
├── include/           # Header files (.h)
├── src/               # Implementation files (.cpp)
├── data/              # TPC-H datasets (.tbl) and DB files (.db)
├── logs/              # Execution logs
├── test_runner.cpp    # Automated Test Runner (Entry Point)
├── CMakeLists.txt     # Build Script (CMake)
├── Makefile           # Build Script (Make)
├── run_tests.bat      # Windows Executable Script
├── run_tests.sh       # Linux/macOS Executable Script
└── README.md          # This file
```

## Final Project Submission Guidelines

### Compilation Instructions
You can compile the engine using any of the following methods:

1. **Using Makefile (Recommended)**:
   ```powershell
   make
   ```

2. **Using Automated Script**:
   Double-click `run_tests.bat` or run:
   ```powershell
   ./run_tests.bat
   ```

3. **Using CMake**:
   ```powershell
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release
   ```

### Execution (Test Runner)
The engine automatically processes the `queries.txt` workload file and executes all test cases (A-G).

```powershell
./NanoDB.exe
```

### Log Evaluation
The engine generates a highly detailed execution log at `logs/nanodb_execution.log`. This log contains:
- **Cache Evictions**: Internal LRU events and disk writes (Test Case D).
- **Parser Steps**: Infix to Postfix conversions (Test Case A & F).
- **Optimizer Paths**: MST join routes (Test Case C).

## Test Cases Covered
- **Test Case A**: Parser & Evaluator (Postfix output & Filtered rows).
- **Test Case B**: Index Optimizer (Sequential vs AVL Tree speedup).
- **Test Case C**: Join Optimizer (MST Path for 3-way join).
- **Test Case D**: Memory Stress Test (50-page Buffer Pool constraint).
- **Test Case E**: Priority Queue Concurrency (Admin priority handling).
- **Test Case F**: Deep Expression Tree Edge Case (Operator precedence).
- **Test Case G**: Durability & Persistence (Insertion across reboots).

## Core Features
- **Zero STL Usage**: All data structures are custom-built.
- **Memory Management**: Fixed-size Buffer Pool with LRU eviction.
- **Query Optimizer**: Graph-based MST for optimal join paths.
- **Indexing**: AVL Tree for O(log N) search.

---
**GitHub Repository**: [Public Repo Link Placeholder]
