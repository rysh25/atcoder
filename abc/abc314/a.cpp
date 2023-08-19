#include <iostream>
#include <vector>

using namespace std;

int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

int main()
{
    int N;

    string pi = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    cin >> N;

    cout << "3.";

    for (int i = 0; i < N; i++)
    {
        cout << pi[i];
    }

    cout << endl;

    return 0;
}
