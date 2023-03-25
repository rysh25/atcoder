#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> pillars(N);

    int res = 0;
    for (int i = 0; i < 1000; i++)
    {
        int x, y;
        cin >> x >> y;
        pillars[i] = make_pair(x, y);
    }

    cout << res << endl;

    return 0;
}
