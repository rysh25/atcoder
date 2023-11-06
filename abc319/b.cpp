#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N;
    cin >> N;

    string result = "";

    for (int i = 0; i <= N; ++i)
    {
        bool found = false;
        for (int j = 1; j <= 9; ++j)
        {
            if (N % j == 0 && i % (N / j) == 0)
            {
                result += to_string(j);
                found = true;
                break;
            }
        }
        if (!found)
        {
            result += '-';
        }
    }

    cout << result << endl;

    return 0;
}
