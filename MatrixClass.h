// Created by Marcello Martins on 09/10/2015
// Last modified on 09/12/2015
// Header file for the ADT Matrix.

/** @file MatrixClass.h */

#ifndef MATRIX_CLASS_H_
#define MATRIX_CLASS_H_

#include <iostream>
#include <vector>

template<typename Comparable>
class Matrix
{
	public:
		//Delfault Constructor for Matrix class
		Matrix();

		//Copy Constructor
		//@param: Matrix instance to be copied.
		Matrix( const Matrix<Comparable>& );

		//Move Constructor
		//@param: Matrix rvalue instance to be moved.
		Matrix( Matrix<Comparable>&& );

		//Copy Assignment Operator
		//@param: Matrix instance to be copied into caller.
		//@return: Returns *this to allow for piping.
		Matrix<Comparable>& operator=( const Matrix<Comparable> & );

		//Move Assignment Operatpor
		//@param: Matrix rvalue instance to be moved into caller.
		//@return: Returns *this to allow for piping.
		Matrix<Comparable>& operator=( Matrix<Comparable> && );

		//Deconstructor
		~Matrix();

		//Swap Fuction which uses std::move()
		//@param: Takes in a Matrix to be swapped with caller.
		void Swap( Matrix<Comparable> & );


		//Getter for num_rows_ 
		//@return: Returns private variable num_rows_ of caller.
		size_t NumRows() const;

		//Getter for num_cols_
		//@return: Returns private variable num_cols_ of caller.
		size_t NumCols() const;

		//Matrix Manual Input Method which outputs a serious of prompts.
		//@precondition: Assumes that the caller is a matrix created by the default constructor.
		void ReadMatrix();

		//Overloaded Addition Operator (lvalue)
		//@param: A matrix instance to be summed with *this.
		//@return: A newly created matrix with the sum of parameter and *this.
		//@precondidtion: Assumes all matrices are of the same size.
		Matrix<Comparable> operator+( Matrix<Comparable>& );

		//Overloaded Addition Operator (rvalue)
		//@param: A matrix rvalue instance to be summed with *this.
		//@return: A newly created matrix with the sum of parameter and *this.
		//@precondidtion: Assumes all matrices are of the same size.
		Matrix<Comparable> operator+( Matrix<Comparable>&& );

		//Overloaded Addition Operator (litteral)
		//@param: A Comparable rvalue instance to be summed with *this.
		//@return: A newly created matrix with the sum of parameter and *this.
		Matrix<Comparable> operator+( Comparable&& );

		//Overloaded [] operator
		//@param: An int which specifies which row to print.
		//@return: A vector with the contents of array_[row][*]
		std::vector<Comparable> operator[]( int );

		//Helper method for << operator.
		//@param: Ostream reference to be filled with contents array_
		void print( std::ostream & );

	private:
		size_t num_rows_, num_cols_;
		Comparable** array_; 

};


#include "MatrixClass.cpp"
#endif  // MATRIX_CLASS_H_