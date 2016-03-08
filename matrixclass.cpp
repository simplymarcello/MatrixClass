// Created by Marcello Martins on 09/10/2015
// Last modified on 09/12/2015
// Header file for the ADT Matrix.

/** @file MatrixClass.cpp */

#include <iostream>
#include <vector>
#include "MatrixClass.h"

//Delfault Constructor
template<typename Comparable>
Matrix<Comparable>::Matrix() : num_rows_{0} , num_cols_{0}
{
	// Array Allocation
	array_ = nullptr;
}

//Copy Constructor
template<typename Comparable>
Matrix<Comparable>::Matrix( const Matrix<Comparable>& rhs ) : num_rows_{ rhs.num_rows_ } , num_cols_{ rhs.num_cols_} 
{
	//Array Allocation
	array_ = new Comparable *[num_rows_];
	for (int i = 0; i < num_rows_; ++i)
		array_[i] = new Comparable[num_cols_];

	//Matrix Copy
	for (int i = 0; i < num_rows_; ++i)
	{
		for (int j = 0; j < num_cols_; ++j)
			array_[i][j] = rhs.array_[i][j];
	}
}

//Move Constructor
template<typename Comparable>
Matrix<Comparable>::Matrix( Matrix<Comparable>&& rhs ) : num_rows_{ rhs.num_rows_ } , num_cols_{ rhs.num_cols_ }
{
	rhs.num_rows_ = 0;
	rhs.num_cols_ = 0;
	array_ = std::move(rhs.array_);
	rhs.array_ = nullptr;
}


//Copy Assignment Operator
template<typename Comparable>
Matrix<Comparable>& Matrix<Comparable>::operator=( const Matrix<Comparable>& rhs )
{
	if (this != &rhs)
	{
		//Delete Old Array.
		for (int i = 0; i < num_rows_; ++i)
			delete[] array_[i];
		delete[] array_;
	
		//Array Allocation
		array_ = new Comparable *[num_rows_];
		for (int i = 0; i < num_rows_; ++i)
			array_[i] = new Comparable[num_cols_];

		//Copy Matrix Values
		for (int i = 0; i < num_rows_; ++i)
		{
			for (int j = 0; j < num_cols_; ++j)
				array_[i][j] = rhs.array_[i][j];
		}
	}
	return *this;
}


//Move Assignment Operator
template<typename Comparable>
Matrix<Comparable>& Matrix<Comparable>::operator=( Matrix<Comparable>&& rhs )
{
	if (&rhs != this)
	{
		//Delete Old Array.
		for (int i = 0; i < num_rows_; ++i)
			delete[] array_[i];
		delete[] array_;

		//Steal rhs Values
		num_rows_ = rhs.num_rows_;
		num_cols_ = rhs.num_cols_;
		array_ = rhs.array_;

		//Clean up
		rhs.num_rows_ = 0;
		rhs.num_cols_ = 0;
		rhs.array_ = nullptr;
	}
	return *this;
}

//MatrixClass Deconstructor
template<typename Comparable>
Matrix<Comparable>::~Matrix()
{
	//Delete array_
	for (int i = 0; i < num_rows_; ++i)
		delete[] array_[i];
	delete[] array_;
}

//Swap Method
template<typename Comparable>
void Matrix<Comparable>::Swap( Matrix<Comparable>& rhs )
{
	Matrix<Comparable> tmp = std::move( rhs );
	rhs = std::move( *this );
	*this = std::move( tmp );
}

//Getter method for num_rows_
template<typename Comparable>
size_t Matrix<Comparable>::NumRows() const
{
	return num_rows_; 
}

//Getter method for num_cols_
template<typename Comparable>
size_t Matrix<Comparable>::NumCols() const
{
	return num_cols_; 
}

//Matrix Manual Input Method
template<typename Comparable>
void Matrix<Comparable>::ReadMatrix()
{
	int row, col;
	Comparable input;
	std::cout << "Please enter the number of rows for this matrix | ";
	std::cin >> row;
	num_rows_ = row;
	std::cout << "Please enter the number of columns for this matrix | ";
	std::cin >> col;
	num_cols_ = col;
	array_ = new Comparable *[row];
	for (int i = 0; i < row; ++i)
		array_[i] = new Comparable[col];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cout << "Please enter a value to input @ row " << i << " column " << j << " : ";
			std::cin >> input;
			array_[i][j] = input;
		}
	}
}

//Overloaded Addition Operator (lvalue)
template<typename Comparable>
Matrix<Comparable> Matrix<Comparable>::operator+( Matrix<Comparable>& rhs )
{
	//Create Matrix to be return with this + rhs
	Matrix<Comparable> output;
	output.num_rows_ = num_rows_;
	output.num_cols_ = num_cols_;
	output.array_ = new Comparable *[output.num_rows_];
	for (int i = 0; i < output.num_rows_; ++i)
		output.array_[i] = new Comparable[output.num_cols_];
    for ( int i = 0; i < output.num_rows_; ++i) 
    {
        for ( int j = 0; j < output.num_cols_; ++j)
        	output.array_[i][j] = array_[i][j] + rhs.array_[i][j];
    }
    return output;
}

//Overloaded Addition Operator (rvalue)
template<typename Comparable>
Matrix<Comparable> Matrix<Comparable>::operator+( Matrix<Comparable>&& rhs ) 
{
	//Create Matrix to be return with this + rhs
	Matrix<Comparable> output;
	output.num_rows_ = num_rows_;
	output.num_cols_ = num_cols_;
	output.array_ = new Comparable *[output.num_rows_];
	for (int i = 0; i < output.num_rows_; ++i)
		output.array_[i] = new Comparable[output.num_cols_];
    for ( int i = 0; i < output.num_rows_; ++i) 
    {
        for ( int j = 0; j < output.num_cols_; ++j)
            output.array_[i][j] = array_[i][j] + rhs.array_[i][j];
    }
    return output;
}

//Overloaded Addition Operator (literal)
template<typename Comparable>
Matrix<Comparable> Matrix<Comparable>::operator+( Comparable&& rhs )
{
	//Create Matrix to be return with this + rhs
	Matrix<Comparable> output;
	output.num_rows_ = num_rows_;
	output.num_cols_ = num_cols_;
	output.array_ = new Comparable *[output.num_rows_];
	for (int i = 0; i < output.num_rows_; ++i)
		output.array_[i] = new Comparable[output.num_cols_];

    for ( int i = 0; i < output.num_rows_; ++i) 
    {
        for ( int j = 0; j < output.num_cols_; ++j)
            output.array_[i][j] = array_[i][j] + rhs;
    }
    return output;
}

//Overloaded [] method
template<typename Comparable>
std::vector<Comparable> Matrix<Comparable>::operator[]( int row )
{
	std::vector<Comparable> output;
	if (row-1 < num_rows_ ) // Checks if row actually exists in matrix.
	{
		for (int i = 0; i < num_cols_; ++i)
			output.push_back(array_[row-1][i]);
		return output;
	}
	else return output;
}

//Print Helper Method
template<typename Comparable>
void Matrix<Comparable>::print( std::ostream & out ) 
{
	for (int i = 0; i < num_rows_; ++i)    
    {
        for (int j = 0; j < num_cols_; ++j)
        	out << array_[i][j] << " ";
        out << "\n"; 
    }
}

//Overloaded << operator
template<typename Comparable>
std::ostream& operator<<( std::ostream& out, Matrix<Comparable> & rhs )
{
	rhs.print( out );
	return out;
}

//Overloaded << operator 
template<typename Comparable>
std::ostream& operator<<( std::ostream& out, Matrix<Comparable> && rhs )
{
	rhs.print( out );
	return out;
}

//PrintVec function
template<typename Comparable>
void PrintVec( const std::vector<Comparable> vec )
{
	for ( int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout<<std::endl;
}
