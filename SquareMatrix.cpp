#include <chrono>
#include <iostream>

using namespace std;

void ComputeTime( const int);



int main(int argc, char const *argv[])
{
	ComputeTime(1000);
	ComputeTime(5000);
	ComputeTime(10000);
	return 0;
}

void ComputeTime(const int N)
{
	cout << endl;

	int sum = 0;
	float** M = new float*[N];
	for(int i = 0; i < N; ++i)
    	M[i] = new float[N];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			M[i][j]=1.0;

	//Start clock
	const auto begin_time1 = chrono::high_resolution_clock::now();

	//Sum all entries in matrix
	for(int row = 0; row < N; row++)
		for(int col = 0; col < N; col++)
			sum += M[row][col];

	//End clock
	const auto end_time1 = chrono::high_resolution_clock::now();

	//Output time taken to complete task row-wise
	cout << "N = " << N << " row-wise took: " << chrono::duration_cast<chrono::milliseconds>(end_time1-begin_time1).count() << " ms" << endl;

	//Start clock
	const auto begin_time2 = chrono::high_resolution_clock::now();

	//Sum all entries in matrix
	for(int row = 0; row < N; row++)
		for(int col = 0; col < N; col++)
			sum += M[col][row];

	//End clock
	const auto end_time2 = chrono::high_resolution_clock::now();

	//Output time taken to complete task col-wise
	cout << "N = " << N << " col-wise took: " << chrono::duration_cast<chrono::milliseconds>(end_time2-begin_time2).count() << " ms" << endl;

	for(int i = 0; i < N; ++i)
  	delete [] M[i];

  	delete [] M;
  	cout << endl;
}