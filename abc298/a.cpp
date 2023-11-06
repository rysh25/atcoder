#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    int good = 0;
    int bad = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'o')
        {
            good++;
        }
        else if (S[i] == 'x')
        {
            bad++;
        }
    }

    cout << ((good > 0 && bad == 0) ? "Yes" : "No") << endl;

    return 0;
}
