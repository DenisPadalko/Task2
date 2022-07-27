#include "Class.h"

Matrix::Matrix() 
{
	*Lines = 3;
	*Columns = 3;
	MatrixElements = new double* [*Lines];
	for (int i = 0; i < *Lines; i++)
	{
		MatrixElements[i] = new double[*Columns];
	}
	for (int i = 0; i < *Lines; i++)
	{
		for (int j = 0; j < *Columns; j++)
		{
			MatrixElements[i][j] = j + 1;
		}
	}
};

Matrix::Matrix(const double** AnotherMatrix, const int AnotherMatrixColumns, const int AnotherMatrixLines)
{
	*Lines = AnotherMatrixLines;
	*Columns = AnotherMatrixColumns;
	MatrixElements = new double*[*Lines];
	for (int i = 0; i < *Lines; i++)
	{
		MatrixElements[i] = new double[*Columns];
	}
	for (int i = 0; i < *Lines; i++)
	{
		for (int j = 0; j < *Columns; j++)
		{
			MatrixElements[i][j] = AnotherMatrix[i][j];
		}
	}
};

Matrix::Matrix(const Matrix& AnotherMatrix) 
{
	*Lines = *AnotherMatrix.Lines;
	*Columns = *AnotherMatrix.Lines;
	MatrixElements = AnotherMatrix.MatrixElements;
};

Matrix::Matrix(Matrix&& AnotherMatrix) 
{
	Lines = AnotherMatrix.Lines;
	Columns = AnotherMatrix.Columns;
	MatrixElements = AnotherMatrix.MatrixElements;

	for (int i = 0; i < *AnotherMatrix.Lines; i++)
	{
		AnotherMatrix.MatrixElements[i] = nullptr;
	}
	AnotherMatrix.MatrixElements = nullptr;
	AnotherMatrix.Lines = nullptr;
	AnotherMatrix.Columns = nullptr;
};

Matrix::Matrix(const int Number) 
{
	*Lines = 1;
	*Columns = 1;
	MatrixElements = new double* [1];
	MatrixElements[0] = new double[1];
	MatrixElements[0][0] = Number;
};

Matrix::Matrix(const double** AnotherMatrix) 
{
};

Matrix::~Matrix() 
{
	for (int i = 0; i < *Lines; i++)
	{
		delete [] MatrixElements[i];
	}
	delete[] MatrixElements;
	delete Lines;
	delete Columns;
};

Matrix& Matrix::operator=(const Matrix& AnotherMatrix) 
{
	if (&AnotherMatrix == this) return *this;

	for (int i = 0; i < *Lines; i++)
	{
		delete[] MatrixElements[i];
	}
	delete[] MatrixElements;
	delete Columns;
	delete Lines;

	Columns = AnotherMatrix.Columns;
	Lines = AnotherMatrix.Lines;
	MatrixElements = AnotherMatrix.MatrixElements;

	return *this;
};

Matrix& Matrix::operator=(Matrix&& AnotherMatrix)
{
	if (&AnotherMatrix == this) return *this;

	for (int i = 0; i < *Lines; i++)
	{
		delete[] MatrixElements[i];
	}
	delete[] MatrixElements;
	delete Columns;
	delete Lines;

	Lines = AnotherMatrix.Lines;
	Columns = AnotherMatrix.Columns;
	MatrixElements = AnotherMatrix.MatrixElements;
	for (int i = 0; i < *AnotherMatrix.Lines; i++)
	{
		AnotherMatrix.MatrixElements[i] = nullptr;
	}
	AnotherMatrix.MatrixElements = nullptr;
	AnotherMatrix.Lines = nullptr;
	AnotherMatrix.Columns = nullptr;

	return *this;
};
