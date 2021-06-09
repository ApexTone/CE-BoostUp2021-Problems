#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Quicksum, Array, Loop
/*
Testcase
- Random
- Always negative
- Always positive
- With grouped negative
- With grouped positive
*/

int main()
{
    long changeLength, goalLength; //number of change, number of question
    cin >> goalLength;
    long goalList[11000]; //target money to achieve
    for (long i = 0; i < goalLength; i++)
    {
        cin >> goalList[i];
    }

    cin >> changeLength;

    long changeList[11000]; //change list
    for (long i = 0; i < changeLength; i++)
    {
        long temp;
        cin >> temp;
        changeList[i] = temp + ((i >= 1) * changeList[i - 1]);
    }

    /*  Quicksum debug
    for (long i = 0; i < changeLength; i++)
    {
        cout << changeList[i] << " ";
    }
    cout << endl;
    */

    vector<pair<long, long>> p;
    long maxValue = LONG_MIN;
    for (long i = 0; i < changeLength; i++)
    {
        long item = changeList[i];
        if (item > maxValue)
        {
            maxValue = item;
            p.push_back(make_pair(maxValue, i));
        }
    }

    for (long i = 0; i < goalLength; i++)
    {
        long goal = goalList[i];
        bool isAchieved = false;
        for (auto it = begin(p); it != end(p); ++it)
        {
            pair<long, long> value = *it;
            //cout << value.first << " " << value.second << endl;

            if (value.first >= goal)
            {
                cout << i + 1 << "# Target achieved at day " << value.second + 1 << "!" << endl;
                isAchieved = true;
                break;
            }
        }
        if (!isAchieved)
        {
            cout << i + 1 << "# Target failed to achieve." << endl;
        }
    }
    return 0;
}