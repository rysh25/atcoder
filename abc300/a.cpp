#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    bool in = false;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == '|')
        {
            in = !in;
        }
        else if (S[i] == '*' && in)
        {
            cout << "in" << endl;
            return 0;
        }
    }

    cout << "out" << endl;

    return 0;
}
