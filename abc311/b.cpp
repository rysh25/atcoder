#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, D;
    cin >> N >> D;

    vector<string> S(N);

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < D; i++)
    {
        bool ok = true;
        for (int j = 0; j < N; j++)
        {
            if (S[j][i] == 'x')
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
