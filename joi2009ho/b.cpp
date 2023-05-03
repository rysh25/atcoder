#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int d, n, m;
    cin >> d >> n >> m;

    vector<int> ds(n + 1, 0);

    for (int i = 1; i < n; i++)
    {
        cin >> ds[i];
    }
    ds[n] = d;

    sort(ds.begin(), ds.end());

    // cout << "ds: ";
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << ds[i] << " ";
    // }
    // cout << endl;

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        // cout << "k=" << k << endl;
        auto ittr = lower_bound(ds.begin(), ds.end(), k);

        // cout << "ittr=" << ittr - ds.begin() << ", *ittr=" << *ittr << endl;

        int dist = abs(k - *ittr);
        if (ittr - ds.begin() > 0)
        {
            // cout << "ittr-1=" << ittr - 1 - ds.begin() << ", *(ittr-1)=" << *(ittr - 1) << endl;
            dist = min(dist, abs(k - *(ittr - 1)));
        }

        // cout << "dist=" << dist << endl;

        res += dist;
    }

    cout << res << endl;

    return 0;
}
