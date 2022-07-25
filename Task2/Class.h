#pragma once
#include <iostream>

class Matrix 
{
private:
	double** MatrixElements;
	int* Columns, Lines;
public:
	Matrix();
	Matrix(const double** AnotherMatrix, const int AnotherMatrixColumns, const int AnotherMatrixLines);
	Matrix(const Matrix& AnotherMatrix);
	Matrix(const Matrix&& AnotherMatrix);
	Matrix(const int Number);
	~Matrix();
	Matrix& operator=(const Matrix& AnotherMatrix);
	Matrix& operator=(const Matrix&& AnotherMatrix);
};