#include <iostream>

using namespace std;

int main()
{
    string S, T;

    cin >> S >> T;

    if (S.find(T) != string::npos)
    {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
