#include <iostream>
using namespace std;

// String manipulation

int main()
{
    //input = <lunar month> <lunar day> <Waxxing/wanning>
    string input;
    getline(cin, input); // this works fine despite the warning

    string res = input.substr(input.find(' ') + 1, input.length());
    res = res.substr(0, res.find(' '));

    //output
    if (res == "15")
    {
        cout << "Wan Pra Yai" << endl;
    }
    else
    {
        cout << "Normal day" << endl;
    }
    return 0;
}