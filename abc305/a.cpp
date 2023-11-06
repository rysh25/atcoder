#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int mod = N % 5;

    int ans = 0;
    if (mod == 0)
    {
        ans = N;
    }
    else if (abs(mod) > abs(5 - mod))
    {
        ans = N + (5 - mod);
    }
    else
    {
        ans = N - mod;
    }

    cout << ans << endl;
    return 0;
}
