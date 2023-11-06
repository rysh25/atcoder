#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    map<int, int> m;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;

        auto ittr = m.find(a);
        if (ittr == m.end())
        {
            // cout << "a=" << a << ": " << 1 << endl;
            m[a] = 1;
        }
        else
        {
            ittr->second++;
            // cout << "a=" << a << ": " << ittr->second << endl;
        }
    }

    int res = 0;
    for (auto ittr = m.begin(); ittr != m.end(); ittr++)
    {
        res += ittr->second / 2;
    }

    cout << res << endl;

    return 0;
}
