#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> diffs;
    int total_seats = 0;

    for (int i = 0; i < N; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        total_seats += z;
        if (x > (x + y) / 2)
        {
            diffs.push_back({0, z});
        }
        else
        {
            diffs.push_back({(x + y) / 2 - x + 1, z});
        }
    }

    // ソートのためのカスタム比較関数
    sort(diffs.begin(), diffs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return 1LL * a.first * b.second < 1LL * b.first * a.second; });

    int answer = 0;
    int seats_gained = 0;
    for (const auto &[diff, z] : diffs)
    {
        if (seats_gained * 2 > total_seats)
        {
            break;
        }
        answer += diff;
        seats_gained += z;
    }

    cout << answer << endl;
    return 0;
}
