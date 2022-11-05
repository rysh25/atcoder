#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    // vector<int> a(N);

    int res = 1;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
        {
            cout << a << ": 2" << endl;
            res *= 2;
        }
        else
        {

            cout << a << ": 1" << endl;
        }
    }

    cout << res - 1 << endl;

    return 0;
}
