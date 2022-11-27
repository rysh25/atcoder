#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int H, W;

    cin >> H >> W;

    // vector<string> S(H);

    vector<string> SW(W, string(H, ' '));

    for (int i = 0; i < H; i++)
    {
        string S;
        cin >> S;

        for (int j = 0; j < W; j++)
        {
            SW[j][i] = S[j];
        }
    }
    sort(SW.begin(), SW.end());

    vector<string> TW(W, string(H, ' '));

    for (int i = 0; i < H; i++)
    {
        string T;
        cin >> T;

        for (int j = 0; j < W; j++)
        {
            TW[j][i] = T[j];
        }
    }

    sort(TW.begin(), TW.end());

    // cout << endl;
    // for (int i = 0; i < W; i++)
    // {
    //     cout << SW[i] << endl;
    // }

    // for (int i = 0; i < W; i++)
    // {
    //     cout << TW[i] << endl;
    // }

    for (int i = 0; i < W; i++)
    {
        if (SW[i] != TW[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
