#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<string> S(N);
    vector<string> D(M);

    map<string, int> mp;

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> D[i];
    }

    int P0;
    cin >> P0;
    // cout << "P0 = " << P0 << endl;
    for (int i = 0; i < M; i++)
    {
        int P;
        cin >> P;
        // cout << "D[i] = " << D[i] << ", P=" << P << endl;
        mp[D[i]] = P;
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        // cout << "S[i] = " << S[i] << endl;
        // cout << "mp[S[i]] = " << mp[S[i]] << endl;
        // cout << "mp.count(S[i]) = " << mp.count(S[i]) << endl;
        if (mp.count(S[i]) == 0)
            res += P0;
        else
            res += mp[S[i]];
    }

    cout << res << endl;

    return 0;
}
