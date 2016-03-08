// Created by Marcello Martins on 09/10/2015
// Last modified on 09/12/2015
// Driver file for the ADT Matrix.

/** @file TestMatric.cpp */

#include "MatrixClass.h"

void TestPart1();
void TestPart2();
void TestPart3();


int main() 
{ 
	TestPart1();
	TestPart2();
	TestPart3();
	return 0;
}

void TestPart1() 
{	std::cout << "\nTEST PART ONE" << std::endl;
	Matrix<int> a, b; //Two empty matrices are created
	std::cout << a.NumRows() << " <- A.num_rows_\n" << a.NumCols() << " <- A.num_cols_ " << std::endl; // yields 0 0
	a.ReadMatrix(); // User provides number of rows, columns and matrix values.
	std::cout << a << " ^ Matrix B\n" << std::endl; // Output should be what user entered. 
	b.ReadMatrix();
	std::cout << b << " ^ Matrix B\n" << std::endl;
	a = b; // Should call the copy assignment operator for a.
	std::cout << a << " ^ A = B\n" << std::endl;
	Matrix<int> c = b; // Should call the copy constructor for c. 
	std::cout << c << " ^ C = B\n" << std::endl;
	Matrix<int> d = std::move(c); // Move constructor for d. 
	std::cout << d << " ^ D = std::move(C)\n" << std::endl;
	a = std::move(d); // Move assignment operator for a.
	std::cout << a << " ^ A = std::move(D)\n" << std::endl;
} // Destructors will be called.


void TestPart2() 
{	std::cout << "\nTEST PART TWO" << std::endl;
	Matrix<std::string> a, b;
	a.ReadMatrix(); // User provides input for matrix a.
	std::cout << a << " ^ Matrix A\n" << std::endl;
	b.ReadMatrix(); // User provides input for matrix b. 
	std::cout << b << " ^ Matrix B\n" << std::endl;
	std::cout << a + b << " ^ A + B\n" << std::endl;
	Matrix<std::string> d = a + b;
	std::cout << d << " ^ D = A + B\n" << std::endl;
	std::cout << d + "hi_there" << " ^ D + \"hi_there\"\n" << std::endl;
	// Matrices should have same size.
	// The default + operator for strings 
	// will be used.
	PrintVec(a[1]);
	std::cout << " ^ PrintVec(a[1])\n" << std::endl;
	PrintVec(b[2]);
	std::cout << " ^ PrintVec(b[2])\n" << std::endl;
	// Should print the first row of a.
	// Should be print the second row of b.
	// Note, that the [] operator should return 
	// a vector object.
	// PrintVec() is a templated function that 
	// std::couts the elements of a vector.
} // End of TestPart2.

void TestPart3() 
{	std::cout << "\nTEST PART THREE" << std::endl;
	Matrix<double> a, b;
	a.ReadMatrix(); // User provides input for matrix a.
	std::cout << a << " ^ Matrix A\n" << std::endl;
	b.ReadMatrix(); // User provides input for matrix b. 
	std::cout << b << " ^ Matrix B\n" << std::endl;
	a.Swap(b);
	std::cout << a << " ^ Matrix A After SWAP \n" << std::endl;
	std::cout << b << " ^ Matrix B After SWAP \n" << std::endl;
} // End of TestPart3.