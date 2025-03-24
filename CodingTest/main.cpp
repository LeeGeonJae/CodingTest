#include <string>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

const int NN = 10000000;

void checkFuntion(set<int>& prime, vector<int>& basket, vector<bool>& checkBoard, const string& numbers, vector<bool>& primeNumber)
{
    if (!basket.empty())
    {
        int number = 0;
        for (int i = 0; i < basket.size(); i++)
            number += basket[i] * (pow(10, basket.size() - i - 1));

        if (!primeNumber[number])
            prime.insert(number);
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (checkBoard[i])
            continue;

        basket.push_back(numbers[i] - '0');
        checkBoard[i] = true;
        checkFuntion(prime, basket, checkBoard, numbers, primeNumber);
        basket.pop_back();
        checkBoard[i] = false;
    }
}

int solution(string numbers)
{
    vector<bool> primeNumber(NN + 1);
    primeNumber[0] = true; primeNumber[1] = true;
    for (int i = 2; i < sqrt(NN); i++)
    {
        if (primeNumber[i])
            continue;

        for (int j = i * 2; j <= NN; j += i)
            primeNumber[j] = true;
    }

    set<int> prime;
    vector<int> basket;
    vector<bool> checkBoard(numbers.size());
    checkFuntion(prime, basket, checkBoard, numbers, primeNumber);

    return prime.empty() ? 0 : prime.size();
}