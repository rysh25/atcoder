#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    int t = 0;
    int a = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'T')
        {
            t++;
        }
        else
        {
            a++;
        }

        if (t >= (N + 2 - 1) / 2)
        {
            std::cout << "T" << endl;
            return 0;
        }
        else if (a >= (N + 2 - 1) / 2)
        {
            std::cout << "A" << endl;
            return 0;
        }
    }

    // std::cout << "a=" << a << ", t=" << t << "(N + 2 - 1) / 2" << (N + 2 - 1) / 2 << endl;
    if (t >= (N + 2 - 1) / 2)
    {
        std::cout << "T" << endl;
        return 0;
    }
    else if (a >= (N + 2 - 1) / 2)
    {
        std::cout << "A" << endl;
        return 0;
    }

    return 0;
}
