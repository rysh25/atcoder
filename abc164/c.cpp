// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    map<string, int> exist;

    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;

        exist[S] = 1;
    }

    cout << exist.size() << endl;

    return 0;
}
