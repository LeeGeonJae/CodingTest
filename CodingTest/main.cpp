#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	vector<int> cross(3, 0);

	// A[1] A[2] A[0] A[1]
	// B[1] B[2] B[0] B[1]

	cross[0] = A[1] * B[2] - A[2] * B[1];
	cross[1] = A[2] * B[0] - A[0] * B[2];
	cross[2] = A[0] * B[1] - A[1] * B[0];

	return cross[2] > 0 ? 1 :cross[2] == 0 ? 0 : -1;
}


int main()
{
	vector<pair<int, int>> coordinate;
	
	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;
		coordinate.push_back({ a, b });
	}

	vector<int> A;
	vector<int> B;

	A.push_back(coordinate[1].first - coordinate[0].first);
	A.push_back(coordinate[1].second - coordinate[0].second);
	A.push_back(0);
	B.push_back(coordinate[2].first - coordinate[1].first);
	B.push_back(coordinate[2].second - coordinate[1].second);
	B.push_back(0);

	cout << solution(A, B);
	
	return 0;
}