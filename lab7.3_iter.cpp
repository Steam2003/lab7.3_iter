#include <iostream>
#include <iomanip>
#include <windows.h>

void input(int** a, int rowCount, int colCount);
void print(int** a, int rowCount, int colCount);
int zero(int** a, int rowCount, int colCount);
void sum(int** a, int* b, int rowCount, int colCount);
void sortRows(int** a, int* b, int rowCount, int colCount);
void change(int** a, int *b,int row1, int row2, int colCount);
void print2(int* b, int rowCount);

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int rowCount, colCount;
	cout << "Введіть кількість рядків масиву: "; cin >> rowCount;
	cout << "Введіть кількість стовпців масиву: "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	int* b = new int[rowCount];
	input(a, rowCount, colCount);
	print(a, rowCount, colCount);
	int check = zero(a, rowCount, colCount);
	if (check > 0)
		cout << "Номер першого стовпця, в якому є хоча б один нуль: " << check << endl;
	else
		cout << "У масиві немає нульових елементів." << endl;
	sum(a, b, rowCount, colCount);
	sortRows(a, b, rowCount, colCount);
	print(a, rowCount, colCount);
		for (int i = 0; i < rowCount; i++)
			delete[] a[i];
	delete[] a;
	delete[] b;
	
}
void input(int** a, int rowCount, int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void print(int** a, int rowCount, int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int zero(int** a, int rowCount, int colCount)
{
	for (int col = 0; col < colCount; col++)
	{
		for (int row = 0; row < rowCount; row++)
		{
			if (a[row][col] == 0)
				
				return col+1;

		}
	}
	
	return -1;

}
void sum(int** a, int* b, int rowCount, int colCount)
{
	//Характеристикою рядка матриці цілих чисел назвемо суму її від’ємних парних елементів. 
	//Для того аби запам'ятати характеристику кожного рядка, введемо матрицю b, де індекс = індексу рядка, а елемент = характеристиці рядка
	for (int row = 0; row < rowCount; row++)
	{
		int S = 0;
		for (int col = 0; col < colCount; col++)
		{
			if (a[row][col] < 0 && a[row][col] % 2 == 0)
				S += a[row][col];
		}
		b[row] = S;
	}

}
void sortRows(int** a, int* b, int rowCount, int colCount)
{
	for (int row = 0; row < rowCount - 1; row++)
		for (int j = 0; j < rowCount - row - 1; j++)
		{
			if (b[j] < b[j + 1])
				change(a, b,j, j + 1, colCount);
		}


}
void change(int** a, int *b,int row1, int row2, int colCount)
{
	int tmp;
	for (int col = 0; col < colCount; col++)
	{
		tmp = a[row1][col];
		a[row1][col] = a[row2][col];
		a[row2][col] = tmp;
	}
	tmp = b[row1];
	b[row1] = b[row2];
	b[row2] = tmp;
}
