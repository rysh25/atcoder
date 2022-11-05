#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string N;
    cin >> N;

    int sum = 0;
    for (auto &n : N)
    {
        sum += n - '0';
    }

    cout << (sum % 9 == 0 ? "Yes" : "No") << endl;

    return 0;
}
