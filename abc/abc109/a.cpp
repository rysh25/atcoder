// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    // even x odd = even
    // even x even = even
    // odd x odd = odd

    int ab = A * B;

    if (ab % 2 == 0)
    {
        cout << "No" << endl;
    }
    else if (ab % 2 == 1)
    {
        cout << "Yes" << endl;
    }

    return 0;
}
