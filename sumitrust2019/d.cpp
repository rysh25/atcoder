#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    int res = 0;
    for (int i = 0; i < 1000; i++)
    {
        string t;
        int x = i;
        for (int j = 0; j < 3; j++)
        {
            t += '0' + x % 10;
            x /= 10;
        }

        int ti = 0;
        for (int j = 0; j < N; j++)
        {
            if (S[j] == t[ti])
                ti++;
            if (ti == 3)
                break;
        }

        if (ti == 3)
            res++;
    }

    cout << res << endl;

    return 0;
}
