#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

vector<double> solution(vector<double> A, vector<double> B)
{
	vector<double> cross(3, 0);

	// A[1] A[2] A[0] A[1]
	// B[1] B[2] B[0] B[1]

	cross[0] = A[1] * B[2] - A[2] * B[1];
	cross[1] = A[2] * B[0] - A[0] * B[2];
	cross[2] = A[0] * B[1] - A[1] * B[0];

	return cross;
}


int main()
{
	vector<double> value = solution({1, 0, 0}, {0, 1, 0});

	for (int i = 0; i < value.size(); i++)
		cout << value[i] << " ";

	return 0;
}