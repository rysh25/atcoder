#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    string prev = "0";

    for (int i = 2; i <= 22 || i <= N; i++)
    {
        cout << "? " << i << endl;

        string S;
        cin >> S;

        if (i == N - 1 && S == "0")
        {
            cout << "! " << i << endl;
            return 0;
        }
        else if (S != prev)
        {
            cout << "! " << i - 1 << endl;
            return 0;
        }
        prev = S;
    }

    return 0;
}
