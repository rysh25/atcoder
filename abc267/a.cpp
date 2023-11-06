// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int result = 0;
    if (S == "Monday")
    {
        result = 5;
    }
    else if (S == "Tuesday")
    {
        result = 4;
    }
    else if (S == "Wednesday")
    {
        result = 3;
    }
    else if (S == "Thursday")
    {
        result = 2;
    }
    else if (S == "Friday")
    {
        result = 1;
    }

    cout << result << endl;

    return 0;
}
