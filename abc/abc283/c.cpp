#include <iostream>

using namespace std;

int main()
{
    string S;

    cin >> S;

    int res = 0;
    int zero_count = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] >= '1' && S[i] <= '9')
        {
            if (zero_count > 0)
            {
                res += (zero_count / 2) + (zero_count % 2);
                zero_count = 0;
            }
            res++;
        }
        else
        {
            zero_count++;
        }
    }

    if (zero_count > 0)
    {
        res += (zero_count / 2) + (zero_count % 2);
        zero_count = 0;
    }
    cout << res << endl;

    return 0;
}
