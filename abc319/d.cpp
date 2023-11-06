#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> L(N);

    int maxL = 0;
    ll sumL = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> L[i];
        maxL = max(maxL, L[i]);
        sumL += L[i];
    }

    long long left = maxL, right = sumL + N - 1;

    auto is_valid = [&](int W) -> bool
    {
        int lines = 1, current_width = 0;
        for (int i = 0; i < N; i++)
        {
            if (current_width + L[i] + (current_width != 0) > W)
            {
                lines++;
                current_width = L[i];
            }
            else
            {
                current_width += L[i] + (current_width != 0);
            }
        }
        return lines <= M;
    };

    while (left < right)
    {
        long long mid = left + (right - left) / 2;

        if (is_valid(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << left << endl;

    return 0;
}
