#include "Class.h"

Matrix::Matrix() 
{
	Lines = new int;
	*Lines = 3;
	Columns = new int;
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

Matrix::Matrix(const double** AnotherMatrix, const int AnotherMatrixLines, const int AnotherMatrixColumns)
{
	Lines = new int;
	*Lines = AnotherMatrixLines;
	Columns = new int;
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
	Lines = new int;
	*Lines = *AnotherMatrix.Lines;
	Columns = new int;
	*Columns = *AnotherMatrix.Lines;
	MatrixElements = new double* [*Lines];
	for (int i = 0; i < *Lines; i++)
	{
		MatrixElements[i] = new double[*Columns];
	}
	for (int i = 0; i < *Lines; i++)
	{
		for (int j = 0; j < *Columns; j++) 
		{
			MatrixElements[i][j] = AnotherMatrix.MatrixElements[i][j];
		}
	}
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
	Lines = new int;
	*Lines = 1;
	Columns = new int;
	*Columns = 1;
	MatrixElements = new double* [1];
	MatrixElements[0] = new double[1];
	MatrixElements[0][0] = Number;
};

Matrix::Matrix(const char* AnotherMatrix) 
{
	int i = 0, j = 0, k = 0;
	char str[1000];
	Lines = new int;
	*Lines = 0;
	Columns = new int;
	int Col = 1;
	while (AnotherMatrix[i] != '\0')
	{
		if (AnotherMatrix[i] == ',')
		{
			Col += 1;
		}
		else if (AnotherMatrix[i] == ';')
		{
			*Lines += 1;
			*Columns = Col;
			Col = 1;
		}
		i++;
	}
	MatrixElements = new double* [*Lines];
	for (i = 0; i < *Lines; i++)
	{
		MatrixElements[i] = new double[*Columns];
	}
	const char s[6] = "[];, ";
	char* Number;
	char* NextNumber;
	Number = strtok_s((char*)AnotherMatrix, s, &NextNumber);
	for(i = 0; i < *Lines; i++)
	{
		for (j = 0; j < *Columns; j++) 
		{
			MatrixElements[i][j] = strtod(Number, NULL);
			Number = strtok_s(NULL, s, &NextNumber);
		}
	}
};

Matrix::~Matrix()
{
	if ((Lines != nullptr) && (Columns != nullptr) && (MatrixElements != nullptr))
	{
		for (int i = 0; i < *Lines; i++)
		{
			delete[] MatrixElements[i];
		}
		delete[] MatrixElements;
		delete Lines;
		delete Columns;
	}
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

	Columns = new int;
	*Columns = *AnotherMatrix.Columns;
	Lines = new int;
	*Lines = *AnotherMatrix.Lines;
	MatrixElements = new double* [*Lines];
	for (int i = 0; i < *Lines; i++)
	{
		MatrixElements[i] = new double[*Columns];
	}
	for (int i = 0; i < *Lines; i++)
	{
		for (int j = 0; j < *Columns; j++) 
		{
			MatrixElements[i][j] = AnotherMatrix.MatrixElements[i][j]; 
		}
	}

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

void Matrix::ShowMatrix() const 
{
	for (int i = 0; i < *Lines; i++)
	{
		for (int j = 0; j < *Columns; j++) 
		{
			cout << MatrixElements[i][j] << " ";
		}
		cout << endl;
	}
};

const string& Matrix::ConvertMatrixToString() const
{
	string* str = new string();
	*str += '[';
	for (int i = 0; i < *Lines; i++)
	{
		for (int j = 0; j < *Columns; j++)
		{
			*str += to_string(MatrixElements[i][j]);
			if (j < (*Columns - 1))
			{
				*str += ", ";
			}
		}
		*str += "; ";
	}
	*str += ']';
	return *str;
};

Matrix CreateMatrix(const double** AnotherMatrix, const int AnotherMatrixLines, const int AnotherMatrixColumns) 
{
	Matrix* Mat = new Matrix(AnotherMatrix, AnotherMatrixLines, AnotherMatrixColumns);
	return *Mat;
};