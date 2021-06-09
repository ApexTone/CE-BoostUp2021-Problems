#include <iostream>
using namespace std;

// Loop, Conditional

int main()
{
    char cmd[11000];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd[i];
    }

    int pancake = 0;
    for (int i = 0; i < n; i++)
    {
        if (cmd[i] == 'e')
        {
            if (pancake > 0)
            {
                pancake--;
            }
        }
        else if (cmd[i] == 'r')
        {
            pancake++;
        }
    }
    cout << pancake << endl;
    return 0;
}