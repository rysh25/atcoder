#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<string> S(N);

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++)
    {
        cout << S[N - i - 1] << endl;
    }

    return 0;
}
