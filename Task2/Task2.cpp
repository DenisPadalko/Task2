#include <iostream>
#include "Class.h"

int main()
{
	cout << "Default constructor" << endl;
	Matrix M;
	M.ShowMatrix();
	cout << "Task 2" << endl;
	Matrix OneNumberMatrix(7);
	OneNumberMatrix.ShowMatrix();
	cout << "Task 3"<< endl; 
	int Lines = 3, Columns = 3;
	double** Array = new double* [Lines];
	for (int i = 0; i < Lines; i++)
	{
		Array[i] = new double[Columns];
	}
	for (int i = 0; i < Lines; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			Array[i][j] = (i + 1) * (j + 1);
		}
	}
	Matrix AnotherMatrix((const double**)Array, Lines, Columns);
	AnotherMatrix.ShowMatrix();
	cout << "Task 4" << endl;
	cout << "Move operator and constructor" << endl;
	Matrix Matrix1 = CreateMatrix((const double**)Array, Lines, Columns); // срабатывает оператор и конструктор перемещения
	Matrix1.ShowMatrix();
	cout << "Copy constructor" << endl;
	Matrix Matrix2 = Matrix1;             // срабатывает конструктор копирования
	Matrix2.ShowMatrix();
	Matrix2 = CreateMatrix((const double**)Array, Lines, Columns);        // срабатывает конструктор перемещения, затем оператор перемещения
	cout << "Copy operator" << endl;
	Matrix2 = Matrix1;                    // срабатывает оператор присваивания
	Matrix2.ShowMatrix();
	cout << "Task 5" << endl;
	string Str = M.ConvertMatrixToString();
	cout << Str << endl;
	cout << "Task 6" << endl;
	char* CStr = (char*)Str.c_str();
	Matrix OneMoreMatrix(CStr);
	OneMoreMatrix.ShowMatrix();
	return 0;
}