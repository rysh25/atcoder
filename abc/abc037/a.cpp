// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int A, B, C;

    cin >> A >> B >> C;

    int res = C / (A > B ? B : A);

    cout << res << endl;

    return 0;
}
