#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> max_s(N, -1);
    vector<int> max2_s(N, -1);

    int max_s_index = -1;
    for (int i = 0; i < N; i++)
    {
        int F, S;
        cin >> F >> S;
        F--;

        if (S > max_s[F])
        {
            max2_s[F] = max_s[F];
            max_s[F] = S;
            max_s_index = F;
        }
        else if (S > max2_s[F])
        {
            max2_s[F] = S;
        }
    }

    int max_same = 0;
    for (int i = 0; i < N; i++)
    {
        // cout << "max2_s[" << i << "]: " << max2_s[i] << endl;
        if (max2_s[i] != -1)
        {
            max_same = max(max_same, max_s[i] + (max2_s[i] / 2));
        }
    }
    // cout << "max_same: " << max_same << endl;

    sort(max_s.rbegin(), max_s.rend());

    int max_diff = max_s[0] + max_s[1];

    // cout << "max_s[0]: " << max_s[0] << endl;
    // cout << "max_diff: " << max_diff << endl;

    cout << max(max_diff, max_same) << endl;

    return 0;
}
