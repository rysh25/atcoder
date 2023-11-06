#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    int res = -1;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'o')
        {
            count++;
        }
        else
        {
            res = max(res, count);
            count = 0;
        }
    }

    res = max(res, count);
    if (res == N)
        res = -1;
    cout << (res <= 0 ? -1 : res) << endl;

    return 0;
}
