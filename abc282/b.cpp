#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    int ans = 0;

    vector<int> S(N, 0);

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
        {
            if (s[j] == 'o')
            {
                S[i] |= 1 << j;
            }
        }
    }

    // for (int i = 0; i < N; i++)
    //     cout << S[i] << endl;

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if ((S[i] | S[j]) == (1 << (M)) - 1)
            {
                res++;
            }
        }
    }

    cout << res << endl;
    return 0;
}
