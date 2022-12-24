#include <iostream>

using namespace std;

int main()
{
    int K;

    cin >> K;

    char c = 'A';

    for (int i = 0; i < K; i++)
    {
        cout << c;
        c++;
    }

    cout << endl;

    return 0;
}
