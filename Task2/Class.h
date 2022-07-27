#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Matrix 
{
private:
	double** MatrixElements;
	int* Columns;
	int* Lines;
public:
	Matrix();
	Matrix(const double** AnotherMatrix, const int AnotherMatrixColumns, const int AnotherMatrixLines);
	Matrix(const Matrix& AnotherMatrix);
	Matrix(Matrix&& AnotherMatrix);
	Matrix(const int Number);
	Matrix(const double** AnotherMatrix);
	~Matrix();
	Matrix& operator=(const Matrix& AnotherMatrix);
	Matrix& operator=(Matrix&& AnotherMatrix);
};