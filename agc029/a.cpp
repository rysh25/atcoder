// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    // 0. BBW
    // 1. BWB
    // 2. WBB

    // 0. BWBWBW
    // 1. BWBWWB
    // 2. BWWBWB
    // 3. BWWWBB
    // 4. WBWWBB
    // 5. WWBWBB
    // 6. WWWBBB

    int count_b = 0;
    long long count_move = 0;
    for (int i = S.length() - 1; i >= 0; i--)
    {
        if (S[i] == 'B')
        {
            int move = S.length() - 1 - i - count_b;
            count_move += move;
            count_b++;
        }
    }

    cout << count_move << endl;

    // long long count = 0;
    // int count_b = 0;
    // for (int i = 0; i < S.length(); i++)
    // {
    //     if (S[i] == 'B')
    //     {
    //         count += i;
    //         count_b++;
    //     }
    // }

    // cout << ((S.length() - count_b) + (S.length() - 1)) * count_b / 2 - count << endl;

    // int count_b = 0;
    // long long ans = 0;
    // for (int i = 0; i < S.length(); i++)
    // {
    //     if (S[i] == 'B')
    //     {
    //         count_b++;
    //     }
    //     else
    //     {
    //         ans += count_b;
    //     }
    // }

    // cout << ans << endl;

    return 0;
}
