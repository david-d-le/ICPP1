#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template<typename  T>
class Matrix
{
private: 
	T** _matrix;
	int _rows;
	int _columns;
	void checkInput(int rows, int columns) const;
public:
	Matrix(int rows, int columns);
	Matrix(const Matrix<T>& m); //copy constructor
	~Matrix();
	void Set(int row, int column, T value);
	void SetFrom(T* arr);
	T& Get(int row, int column);
	const T& Get(int row, int column) const;

	template <typename R>
	Matrix<R> Cast() const;	//create new matrix and cast to new type

	Matrix Transpose() const;
	Matrix Multiply(const Matrix& m) const;
	Matrix Multiply(T scalar) const;
	Matrix Add(const Matrix& m) const;
	Matrix Add(T scalar) const;

	bool IsEqual(const Matrix& m) const;
	void print() const;
};

template<typename T>
void Matrix<T>::Matrix::checkInput(int row, int column) const{
	if (row < 0 || row > _rows) {
		throw std::invalid_argument("invalid row number");
	}
	if (column < 0 || column > _columns) {
		throw std::invalid_argument("invalid column number");
	}
}

template<typename T>
inline Matrix<T>::Matrix(int rows, int columns){
	if (rows <= 0) {
		throw std::invalid_argument("invalid row number");
	}
	if (columns <= 0)
	{
		throw std::invalid_argument("invalid column number");
	}
	_rows = rows;
	_columns = columns;
	_matrix = new T*[rows];
	for (int i = 0; i < rows; i++){
		_matrix[i] = new T[columns];
	}
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& m){
	for (int i = 0; i < _rows; i++)
	{
		delete[] _matrix[i];
	}
	delete[] _matrix;
	_rows = m._rows;
	_columns = m._columns;
	_matrix = new T * [_rows];

	for (int i = 0; i < m._rows; i++)
	{
		_matrix[i] = new T[_columns];
		for (int j = 0; j < m._columns; j++)
		{
			_matrix[i][j] = m._matrix[i][j];
		}
	}
}

template<typename T>
inline Matrix<T>::~Matrix(){
	for (int i = 0; i < _rows; i++)
	{
		delete[] _matrix[i];
	}
	delete[] _matrix;
}

template<typename T>
inline void Matrix<T>::Set(int row, int column, T value){
	checkInput(row, column);
	_matrix[row][column] = T;
}

template<typename T>
inline void Matrix<T>::SetFrom(T* arr){
	//no array length check
	int count = 0;
	for (int i = 0; i < _rows; i++){
		for (int j = 0; j < _columns; j++) {
			_matrix[i][j] = arr[count++];
		}
	}
}

template<typename T>
inline T& Matrix<T>::Get(int row, int column) {
	checkInput(row, column);
	return _matrix[row][column];
}

template<typename T>
inline const T& Matrix<T>::Get(int row, int column) const {
	checkInput(row, column);
	return _matrix[row][column];
}

template<typename T>
template <typename R>
inline Matrix<R> Matrix<T>::Cast() const
{
	Matrix<R> newMatrix = Matrix<R>{_rows, _columns};
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			newMatrix.Get(i, j) = _matrix[i][j];
		}
	}

	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Transpose() const
{
	Matrix<T> newMatrix = Matrix{ _columns, _rows };
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			newMatrix.Get(j, i) = _matrix[i][j];
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Multiply(const Matrix& m) const
{
	if (_columns != m._rows)
	{
		throw std::invalid_argument("invalid matrix for multiplication");
	}
	Matrix<T> newMatrix = Matrix{ _rows, m._columns };
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			newMatrix._matrix[i][j] = 0;
			for (int k = 0; k < _columns; k++)
			{
				newMatrix._matrix[i][j] += _matrix[i][k] * m._matrix[k][j];
			}
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Multiply(T scalar) const
{
	Matrix<T> newMatrix = Matrix{ _columns, _rows };
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			newMatrix._matrix[i][j] = T * _matrix[i][j];
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Add(const Matrix& m) const
{
	if (_rows != m._rows || _columns != m._columns){
		throw std::invalid_argument("invalid matrix for addition");
	}
	Matrix<T> newMatrix = Matrix{ _columns, _rows };
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			newMatrix._matrix[i][j] = m._matrix[i][j] +  _matrix[i][j];
		}
	}
	return Matrix();
}

template<typename T>
inline Matrix<T> Matrix<T>::Add(T scalar) const
{
	Matrix<T> newMatrix = Matrix{ _columns, _rows };
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			newMatrix = T + _matrix[i][j];
		}
	}
	return newMatrix;
}

template<typename T>
inline bool Matrix<T>::IsEqual(const Matrix& m) const
{
	if (_rows != m._rows || _columns != _columns){
		return false;
	}
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			if (_matrix[i][j] != m._matrix[i][j]){
				return false;
			};
		}
	}
	return true;
}

template<typename T>
inline void Matrix<T>::print() const{
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}



#endif // !MATRIX_H