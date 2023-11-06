#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string W;
        cin >> W;

        if (W == "and" || W == "not" ||
            W == "that" || W == "the" || W == "you")
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
