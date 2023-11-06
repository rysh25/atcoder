#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

int main()
{
    int N;

    cin >> N;

    vector<string> S(N);

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            if (is_palindrome(S[i] + S[j]))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
