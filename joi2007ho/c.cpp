#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> p;
    set<pair<int, int>> s;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
        s.emplace(x, y);
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int dx = p[i].first - p[j].first;
            int dy = p[i].second - p[j].second;

            if (s.count(make_pair(p[i].first - dy, p[i].second + dx)) &&
                s.count(make_pair(p[j].first - dy, p[j].second + dx)))
            {
                res = max(res, abs(dx * dx) + abs(dy * dy));
            }
            if (s.count(make_pair(p[i].first + dy, p[i].second - dx)) &&
                s.count(make_pair(p[j].first + dy, p[j].second - dx)))
            {
                res = max(res, abs(dx * dx) + abs(dy * dy));
            }
        }
    }

    cout << res << endl;

    return 0;
}
