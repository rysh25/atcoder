#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> A(N);

    for (auto &a : A)
    {
        cin >> a;
    }

    int Q;

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int q, k, x;
        cin >> q;

        if (q == 1)
        {
            cin >> k >> x;
            k--;
            A[k] = x;
        }
        else if (q == 2)
        {
            cin >> k;
            k--;
            cout << A[k] << endl;
        }
    }

    return 0;
}
