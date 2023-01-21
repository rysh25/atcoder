#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;

    cin >> N >> S;

    for (int i = 0; i < N - 1; i++)
    {
        int l = 0;
        l = N - (i + 1);
        int res = 0;
        // cout << "i=" << i + 1 << ", l=" << l << ": " << endl;
        for (int k = 0; k < l; k++)
        {
            // cout << "S["
            //      << k + 1 << "]=" << S[k] << ", "
            //      << "S[" << k + i + 1 + 1 << "]=" << S[k + i + 1] << endl;
            if (S[k] == S[k + (i + 1)])
                break;
            res++;
        }
        cout << res << endl;
    }

    return 0;
}
