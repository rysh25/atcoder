#include <iostream>

using namespace std;

void f(int N, string s)
{
    if (s.length() == N)
    {
        cout << s << endl;
        return;
    }

    f(N, "(" + s + ")");
    if (s.length() != 0)
    {
        f(N, s + "()");
    }
}

int main()
{
    int N;

    cin >> N;

    if (N % 2 != 0)
        return 0;

    f(N, "");

    return 0;
}
