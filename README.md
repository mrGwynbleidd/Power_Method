# Power Method for Eigenvalue Approximation

A simple C++ implementation of the **Power Method**, a numerical linear algebra algorithm used to approximate the **dominant eigenvalue** and its corresponding **eigenvector** of a square matrix.

This project is designed for educational purposes and demonstrates how iterative methods can be used to solve eigenvalue problems in Linear Algebra.

---

## Project Overview

The Power Method is an iterative algorithm used to find the largest eigenvalue of a matrix by repeatedly multiplying the matrix by a vector and normalizing the result.

In this project, the user enters a square matrix, and the program calculates:

* The approximate largest eigenvalue
* The corresponding eigenvector
* Iteration-by-iteration results
* Difference between the current and previous eigenvalue approximation

The program continues until the result converges within a given tolerance.

---

## What Is the Power Method?

The Power Method is based on the idea that repeated multiplication of a matrix by a non-zero vector gradually moves the vector toward the direction of the dominant eigenvector.

For a square matrix `A`, the algorithm starts with an initial vector `x` and repeatedly applies:

```text
x(k+1) = A × x(k)
```

After each multiplication, the vector is normalized to prevent the values from becoming too large.

The dominant eigenvalue is then approximated using the Rayleigh quotient.

---

## Features

* Accepts any `n × n` square matrix from the user
* Uses an initial vector of ones
* Performs matrix-vector multiplication
* Normalizes the eigenvector at each iteration
* Calculates the approximate eigenvalue using the Rayleigh quotient
* Displays intermediate eigenvectors and eigenvalues
* Stops automatically when the result converges
* Uses a tolerance value for convergence checking

---

## Algorithm Steps

1. The user enters the size of the square matrix.
2. The user enters all matrix elements.
3. The program creates an initial vector with all values equal to `1`.
4. The matrix is multiplied by the current vector.
5. The resulting vector is normalized.
6. The eigenvalue is approximated using the Rayleigh quotient.
7. The difference between the current and previous eigenvalue is checked.
8. The process repeats until the difference is smaller than the tolerance value.
9. The final approximate eigenvalue and eigenvector are displayed.

---

## Mathematical Formula

The Rayleigh quotient is used to approximate the eigenvalue:

```text
λ = (xᵀAx) / (xᵀx)
```

Where:

* `A` is the input matrix
* `x` is the current eigenvector approximation
* `λ` is the approximate dominant eigenvalue

---

## Project Structure

```text
Power_Method/
│
├── Eigenvalue Power Method.cpp
└── README.md
```

### File Description

| File                          | Description                                                      |
| ----------------------------- | ---------------------------------------------------------------- |
| `Eigenvalue Power Method.cpp` | Main C++ source file containing the Power Method implementation. |
| `README.md`                   | Project documentation.                                           |

---

## Main Functions

### `show()`

Displays the matrix entered by the user.

```cpp
void show(const vector<vector<double>>& A)
```

---

### `multiply()`

Multiplies the matrix by a vector.

```cpp
vector<double> multiply(const vector<vector<double>>& A, const vector<double>& x)
```

---

### `norm()`

Calculates the Euclidean norm of a vector.

```cpp
double norm(const vector<double>& x)
```

---

### `normalize()`

Normalizes a vector so that its length becomes equal to `1`.

```cpp
void normalize(vector<double>& x)
```

---

### `rayleighQuotient()`

Calculates the approximate eigenvalue using the Rayleigh quotient.

```cpp
double rayleighQuotient(const vector<vector<double>>& A, const vector<double>& x)
```

---

## How to Compile and Run

### Using g++

Open the terminal in the project folder and run:

```bash
g++ "Eigenvalue Power Method.cpp" -o power_method
```

Then run the program:

```bash
./power_method
```

### On Windows

```bash
g++ "Eigenvalue Power Method.cpp" -o power_method.exe
power_method.exe
```

---

## Example Input

```text
Enter matrix size (n x n): 2

Enter element for matrix in position a11
2
Enter element for matrix in position a12
1
Enter element for matrix in position a21
1
Enter element for matrix in position a22
2
```

Matrix:

```text
[2 1]
[1 2]
```

---

## Example Output

```text
Approximate largest eigenvalue: 3
Corresponding eigenvector: < 0.707107 ; 0.707107 ; >
```

The result means that the dominant eigenvalue is approximately `3`, and the corresponding normalized eigenvector is close to:

```text
< 0.707107, 0.707107 >
```

---

## Requirements

* C++ compiler
* C++11 or newer
* Terminal or command prompt

---

## Concepts Demonstrated

This project demonstrates several important Linear Algebra and programming concepts:

* Eigenvalues
* Eigenvectors
* Dominant eigenvalue
* Power Method
* Iterative numerical algorithms
* Matrix-vector multiplication
* Vector normalization
* Rayleigh quotient
* Convergence checking
* C++ vectors and functions

---

## Limitations

The Power Method works best when:

* The matrix is square
* The matrix has a dominant eigenvalue
* The dominant eigenvalue is clearly larger in magnitude than the other eigenvalues
* The initial vector is not orthogonal to the dominant eigenvector

The method may converge slowly or fail to produce a correct result if the matrix does not satisfy these conditions.

---

## Possible Improvements

Future improvements may include:

* Adding input validation
* Allowing the user to choose a custom initial vector
* Showing the number of iterations needed for convergence
* Improving the formatting of output
* Adding support for reading matrices from files
* Adding test cases
* Handling special cases where the method does not converge
* Fixing spelling mistakes in output messages and comments

---

## Educational Purpose

This project was created as a Linear Algebra programming assignment.
Its main goal is to show how mathematical algorithms can be implemented in C++ and used to solve practical numerical problems.

---

## Author

Created as a Linear Algebra project in C++.

GitHub Repository: `mrGwynbleidd/Power_Method`

---

## License

This project is for educational purposes.
You may add a license file if you want to make the project open-source.
