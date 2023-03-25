#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int res = 0;
    for (int i = 1; i <= N; i += 2)
    {
        int count = 0;
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                if (j * j == i)
                    count++;
                else
                    count += 2;
            }
        }

        if (count == 8)
            res++;
    }

    cout << res << endl;

    return 0;
}
