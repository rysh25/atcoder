#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int count = 0;
    int res = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T')
        {
            count++;
            res = max(count, res);
        }
        else
        {
            count = 0;
        }
    }

    cout << res << endl;

    return 0;
}
