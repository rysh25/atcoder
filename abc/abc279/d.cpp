#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    long long A, B;

    cin >> A >> B;

    double prev = 0;
    int g = 1;

    for (long long i = 0; i < 1e18 + 1; i++)
    {
        // cout << (B * i) << "+" << A << "/" << sqrt(g) << endl;

        double c = A / sqrt(g);
        double d = (B * i) + A / sqrt(g);
        cout << "c=" << c << endl;
        // cout << "d=" << d << endl;
        // cout << "c - prev=" << abs(c - prev) << endl;

        // cout << d << endl;

        if (abs(c - prev) < B)
        {
            if (i == 0)
            {
                cout << d << endl;
            }
            else
            {
                cout << (B * i - 1) + prev << endl;
            }
            return 0;
        }

        prev = c;
        g += B;
    }

    return 0;
}
