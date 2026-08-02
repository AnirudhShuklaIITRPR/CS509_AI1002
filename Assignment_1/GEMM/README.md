# CS509 - Assignment 1
## General Matrix Multiplication (GEMM) (Individual Task)

### Student Information
- NAME: ANIRUDH SHUKLA
- ENTRY NO.: 2026AIM1002
- BRANCH: ARTIFICIAL INTELLIGENCE(AI)  

**Algorithm:**
- Simple Matrix Multiplication (Simple GEMM)
- Blocked/Tiled Matrix Multiplication (Blocked GEMM)

**Programming Language:** C

**Compiler:** GCC (MSYS2 UCRT64)

---

# Objective

The objective of this assignment is to implement and compare two matrix multiplication algorithms:

1. Simple General Matrix Multiplication (Simple GEMM)
2. Blocked (Tiled) General Matrix Multiplication (Blocked GEMM)

The assignment also compares the execution time of both algorithms.

---

# Project Structure

```
GEMM/
│
├── driver/
│   └── driver.c
│
├── include/
│   └── matrix.h
│
├── src/
│   └── matrix.c
│
├── tests/
│   ├── test_case_1.txt
│   ├── test_case_2.txt
│   ├── test_case_3.txt
│   └── ...
│
├── output/
│   ├── output_1.txt
│   ├── output_2.txt
│   ├── output_3.txt
│   └── ...
│
├── Makefile
│
└── README.md
```

---

# Algorithms Implemented

## 1. Simple GEMM

The Simple GEMM algorithm uses three nested loops to perform matrix multiplication.

Formula:

```
C[i][j] = Σ A[i][k] × B[k][j]
```

This algorithm performs direct multiplication without considering cache optimization.

---

## 2. Blocked GEMM

Blocked GEMM divides matrices into smaller blocks (tiles).

Instead of multiplying the entire matrices at once, it processes one block at a time.

Advantages:

- Better cache utilization
- Reduced cache misses
- Improved execution time for larger matrices

Block Size Used:

```
32
```

---

# Input File Format

Each input file follows the format:

```
M K N

Matrix A

Matrix B
```

Example:

```
2 3 2

1 2 3
4 5 6

7 8
9 10
11 12
```

Where

```
A = M × K

B = K × N

C = M × N
```

---

# Output

The program prints:

- Matrix A
- Matrix B
- Result using Simple GEMM
- Execution Time (Simple GEMM)
- Result using Blocked GEMM
- Execution Time (Blocked GEMM)

The output is also stored inside the `output` directory.

---

# Compilation

Using GCC:

```bash
gcc driver/driver.c src/matrix.c -Iinclude -o gemm.exe
```

Or using Makefile:

```bash
make
```

---

# Execution

Run the executable:

Windows

```bash
gemm.exe
```

Linux

```bash
./gemm
```

---

# Test Cases

The following test cases were used.

| Test Case | Matrix Size |
|------------|------------|
| Test Case 1 | 2 × 3 × 2 |
| Test Case 2 | 50 × 50 × 50 |
| Test Case 3 | 250 × 250 × 250 |

Additional test cases can be added inside the `tests` folder.

---

# Performance Measurement

Execution time is measured using the C Standard Library function:

```
clock()
```

Only the algorithm execution time is measured.

The following operations are excluded from timing:

- File Reading
- Input Parsing
- Matrix Allocation
- Output Printing
- Memory Deallocation

---


# Results

The program was tested on different matrix sizes. The execution time of both algorithms is shown below.

| Test Case | Matrix Size | Simple GEMM (s) | Blocked GEMM (s) | Speedup |
|-----------|-------------|----------------:|-----------------:|---------:|
| Test Case 1 | 2 × 3 × 2 | 0.000000 | 0.000000 | N/A |
| Test Case 2 | 50 × 50 × 50 | 0.001000 | 0.001000 | 1.00× |
| Test Case 3 | 250 × 250 × 250 | 0.100000 | 0.062000 | 1.61× |

---

# Time Complexity

## Simple GEMM

```
O(M × K × N)
```

For square matrices:

```
O(n³)
```

---

## Blocked GEMM

The theoretical complexity remains

```
O(M × K × N)
```

However, due to improved cache locality, the practical execution time is lower for larger matrices.

---

# Space Complexity

Input Matrix A

```
O(M × K)
```

Input Matrix B

```
O(K × N)
```

Result Matrix C

```
O(M × N)
```

Total

```
O(MK + KN + MN)
```

---

# Features

- Dynamic memory allocation
- Modular implementation
- Separate driver and algorithm files
- File-based input
- File-based output
- Execution time comparison
- Simple GEMM implementation
- Blocked GEMM implementation

---

# Files Description

## driver.c

Reads input files, creates matrices, calls algorithms, measures execution time, and writes output.

---

## matrix.c

Implements

- Matrix creation
- Matrix deletion
- Matrix input
- Matrix output
- Simple GEMM
- Blocked GEMM

---

## matrix.h

Contains

- Matrix structure
- Function declarations
- Header guards

---

# Conclusion

This project demonstrates the implementation of both Simple GEMM and Blocked GEMM.

Although both algorithms have the same theoretical time complexity, Blocked GEMM performs better in practice because of improved cache utilization.

The execution time comparison confirms that the blocked implementation is more efficient for larger matrices.

---

# References

1. CS509 Assignment 1 Document
2. GCC Documentation
