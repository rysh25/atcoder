#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<long double, long double>> xy(N);

    for (int i = 0; i < N; i++)
    {
        long double x, y;
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }

    sort(xy.begin(), xy.end());

    long double res = 0;
    int count = 0;
    do
    {
        long double d = 0;
        pair<long double, long double> prev = xy[0];
        for (int i = 1; i < N; i++)
        {
            d += sqrt((prev.first - xy[i].first) * (prev.first - xy[i].first) + (prev.second - xy[i].second) * (prev.second - xy[i].second));
            // cout << sqrt((prev.first - xy[i].first) * (prev.first - xy[i].first) + (prev.second - xy[i].second) * (prev.second - xy[i].second)) << endl;
            prev = xy[i];
        }

        // cout << "d=" << d << endl;

        res += d;
        count++;
    } while (next_permutation(xy.begin(), xy.end()));

    // cout << "cout=" << count << ", res=" << res << endl;

    printf("%.10Lf\n", res / count);
    return 0;
}
