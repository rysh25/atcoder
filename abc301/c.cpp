#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    vector<int> s_count(27, 0);
    vector<int> t_count(27, 0);

    string atcoder = "atcoder";

    for (int i = 0; i < S.size(); i++)
    {
        // cout << S[i] << ", S[" << i << "]=" << S[i] << endl;
        if (S[i] == '@')
        {
            s_count[26]++;
        }
        else
        {
            s_count[S[i] - 'a']++;
        }
    }

    for (int i = 0; i < T.size(); i++)
    {
        // cout << T[i] << ", T[" << i << "]=" << T[i] << endl;
        if (T[i] == '@')
        {
            t_count[26]++;
        }
        else
        {
            t_count[T[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (atcoder.find((char)(i + 'a')) == string::npos)
        {
            if (s_count[i] != t_count[i])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            if (s_count[i] > t_count[i])
            {
                t_count[26] -= s_count[i] - t_count[i];
            }
            else if (s_count[i] > t_count[i])
            {
                s_count[26] -= t_count[i] - s_count[i];
            }
        }
    }

    // cout << "atcoder_unmatch_count=" << atcoder_unmatch_count << ", s_count[26]=" << s_count[26] << endl;
    if (s_count[26] >= 0 && t_count[26] >= 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    else
    {
        cout << "No" << endl;
        return 0;
    }
}
