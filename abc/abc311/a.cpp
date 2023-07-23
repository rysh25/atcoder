#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    int N;
    string S;
    cin >> N >> S;

    bool found_a, found_b, found_c;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'A')
        {
            found_a = true;
        }
        else if (S[i] == 'B')
        {
            found_b = true;
        }
        else if (S[i] == 'C')
        {
            found_c = true;
        }

        if (found_a && found_b && found_c)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}
