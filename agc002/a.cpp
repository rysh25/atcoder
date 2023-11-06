// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a < 0 && b > 0)
    {
        cout << "Zero" << endl;
    }
    else if (a < 0)
    {
        if ((b < 0 ? b + 1 : 0) - a % 2 == 0)
        {
            cout << "Positive" << endl;
        }
        else
        {
            cout << "Negative" << endl;
        }
    }
    else
    {
        cout << "Positive" << endl;
    }

    return 0;
}
