#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int m;
    cin >> m;

    vector<pair<int, int>> t(m);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        t[i] = make_pair(x, y);
    }

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    set<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        s.emplace(x, y);
        v[i] = make_pair(x, y);
    }

    for (int i = 0; i < n; i++)
    {
        int dx = v[i].first - t[0].first;
        int dy = v[i].second - t[0].second;

        bool found = true;
        for (int j = 1; j < m; j++)
        {
            if (!s.count(make_pair(t[j].first + dx, t[j].second + dy)))
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            cout << dx << " " << dy << endl;
            return 0;
        }
    }

    return 0;
}
