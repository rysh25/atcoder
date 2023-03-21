#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
            cout << a << " ";
    }

    cout << endl;

    return 0;
}
