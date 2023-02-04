#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, A, B;
    string S;

    cin >> N >> A >> B >> S;
    long long res = 0;

    int cnt = 0;

    for (int i = 0; i < N / 2; i++)
    {
        if (S[i] != S[N - i - 1])
        {
            if (S[i] != S[N - i - 1])
                res += min(abs(S[i] - S[N - i - 1]), 26 - abs(S[i] - S[N - i - 1]));
            res += min(B, 2 * A);
        }
    }
    cnt = count(S.begin(), S.end(), S[0]);
    if (cnt == N)
        res = 0;
    cout << res << endl;
    return 0;
}
