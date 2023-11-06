// #include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> result;
    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        if (result.find(n) == result.end())
        {
            result[n] = 0;
        }
        else
        {
            result[n]++;
        }
    }

    cout << result.size() << endl;

    return 0;
}
