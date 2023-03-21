#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long L;
    int N1, N2;
    cin >> L >> N1 >> N2;

    long long res = 0;

    vector<int> v1(N1), v2(N2);
    vector<long long> l1(N1), l2(N2);

    for (int i = 0; i < N1; i++)
    {
        cin >> v1[i] >> l1[i];
    }

    for (int i = 0; i < N2; i++)
    {
        cin >> v2[i] >> l2[i];
    }

    int n1_i = 0, n2_i = 0;
    while (n1_i < N1 && n2_i < N2)
    {
        if (v1[n1_i] == v2[n2_i])
        {
            res += min(l1[n1_i], l2[n2_i]);
        }

        if (l1[n1_i] == l2[n2_i])
        {
            n1_i++;
            n2_i++;
        }
        else if (l1[n1_i] < l2[n2_i])
        {
            l2[n2_i] -= l1[n1_i];
            n1_i++;
        }
        else
        {
            l1[n1_i] -= l2[n2_i];
            n2_i++;
        }
    }

    cout << res << endl;

    return 0;
}
