// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string W;

    cin >> W;

    for (auto& c: W)
    {
        if (c != 'a' && c != 'i' && c != 'u' && c!= 'e' && c!='o')
        {
            cout << c;
        }
    }

    cout << endl;

    return 0;
}
