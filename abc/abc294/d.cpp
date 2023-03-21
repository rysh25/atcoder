#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> row(N + 1, 0);

    int curr = 1;
    int front = 1;
    for (int i = 0; i < Q; i++)
    {
        int e, x;
        cin >> e;
        if (e == 1)
        {
            // cout << "e=" << e << ", curr=" << curr << endl;
            row[curr] = 1;
            curr++;
        }
        else if (e == 2)
        {
            cin >> x;
            // cout << "e=" << e << ", x=" << x << ", curr=" << curr << endl;
            row[x] = 2;
        }
        else
        {
            // cout << "e=" << e << ", curr=" << curr << endl;
            for (int i = front; i <= N; i++)
            {
                if (row[i] == 1)
                {
                    cout << i << endl;
                    front = i;
                    break;
                }
            }
        }
    }

    return 0;
}
