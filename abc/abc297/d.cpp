#include <iostream>
#include <algorithm>

using namespace std;

// template <typename T>
// T f(T x, T y)
// {
//     if (x == y)
//     {
//         // cout << x << endl;
//         return 0;
//     }
//     return ((x > y) ? f(x - y, y) : f(x, y - x)) + 1;
// }

template <typename T>
T f(T x, T y)
{
    if (x == y)
    {
        // cout << x << endl;
        return 0;
    }

    if (x > y)
    {
        if (x % y == 0)
        {
            return x / y - 1;
        }
        else
        {
            return f(x % y, y) + x / y;
        }
    }
    else
    {
        if (y % x == 0)
        {
            return y / x - 1;
        }
        else
        {
            return f(x, y % x) + y / x;
        }
    }
}

int main()
{
    long long A, B;
    cin >> A >> B;

    cout << f(A, B) << endl;

    return 0;
}
