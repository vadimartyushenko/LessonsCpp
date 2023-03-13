#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#pragma region Print

template <typename T>
void PrintVector(const vector<T>& vec) {
	for (auto i : vec)
		cout << setprecision(3) << setw(7) << i;
	cout << endl;
}

template <typename T>
void PrintMatrix(const vector<vector<T>>& matrix)
{
	for (auto i : matrix) {
		cout << endl;
		for (auto j : i)
			cout << setprecision(3) << setw(7) << j;
	}
	cout << endl;
}

#pragma endregion

#pragma region Insert in matrix
template <typename T>
void InsertLineBef(vector<vector<T>>& matrix, const vector<T>& newLine, int numb)
{
	if (numb <= matrix.size())
		matrix.insert(matrix.begin() + numb - 1, newLine);
	else
		cout << "Такой строки нет";
}

template <typename T>
void InsertLineLast(vector<vector<T>>& matrix, const vector<T>& newLine, int numb)
{
	if (numb <= matrix.size())
		matrix.insert(matrix.begin() + numb, newLine);
	else
		cout << "Такой строки нет";
}

template <typename T>
void InsertColumnBef(vector<vector<T>>& matrix, const vector<T>& newColumn, int numb)
{
	for (unsigned int i = 0; i < matrix.size(); i++)
		if (numb <= matrix[i].size())
			matrix[i].insert(matrix[i].begin() + numb - 1, newColumn[i]);
		else {
			cout << "Такого столбца нет" << endl; break;
		}
}

template <typename T>
void InsertColumnLast(vector<vector<T>>& matrix, const vector<T>& newColumn, int numb)
{
	for (unsigned int i = 0; i < matrix.size(); i++)
		if (numb <= matrix[i].size())
			matrix[i].insert(matrix[i].begin() + numb, newColumn[i]);
		else {
			cout << "Такого столбца нет" << endl; break;
		}
}

#pragma endregion

#pragma region Delete from matrix
template <typename T>
void DeleteLine(vector<vector<T>>& matrix, int numb)
{
	if (numb <= matrix.size())
		matrix.erase(matrix.begin() + numb - 1);
	else
		cout << "Такой строки нет";
}

template <typename T>
void DeleteColumn(vector<vector<T>>& matrix, int numb)
{
	for (unsigned int i = 0; i < matrix.size(); i++)
		if (numb <= matrix[i].size())
			matrix[i].erase(matrix[i].begin() + numb - 1);
		else {
			cout << "Такого столбца нет" << endl; break;
		}
}
#pragma endregion