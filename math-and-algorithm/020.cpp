#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

using ll = long long;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);

    rep(i, N)
    {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                for (int l = k + 1; l < N; l++)
                {
                    for (int m = l + 1; m < N; m++)
                    {
                        if (A[i] + A[j] + A[k] + A[l] + A[m] == 1000)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
