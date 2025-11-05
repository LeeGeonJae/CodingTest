#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

double solution(vector<double> A, vector<double> B)
{
	double dot = 0;
	double Alength = 0;
	double Blength = 0;

	for (int i = 0; i < A.size(); i++)
	{
		dot += A[i] * B[i];
		Alength += A[i] * A[i];
		Blength += B[i] * B[i];
	}

	Alength = sqrt(Alength);
	Blength = sqrt(Blength);

	double value = dot / (Alength * Blength);
	return acos(value) / 3.141592 * 180;
}


int main()
{
	cout << solution({1, 0, 0}, {1, 2, 2});

	return 0;
}