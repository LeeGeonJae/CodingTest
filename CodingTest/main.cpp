#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int maxPriorityNumber = *max_element(priorities.begin(), priorities.end());
    int indexCnt = 0;
    while (true)
    {
        for (int i = 0; i < priorities.size(); i++)
        {
            if (maxPriorityNumber == priorities[i])
            {
                indexCnt++;
                if (i == location)
                    return indexCnt;

                priorities[i] = 0;
                maxPriorityNumber = *max_element(priorities.begin(), priorities.end());
            }
        }
    }
}