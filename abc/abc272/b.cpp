// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template <typename T>
bool next_combination(const T first, const T last, int k)
{
    const T subset = first + k;
    // empty container | k = 0 | k == n
    if (first == last || first == subset || last == subset)
    {
        return false;
    }
    T src = subset;
    while (first != src)
    {
        src--;
        if (*src < *(last - 1))
        {
            T dest = subset;
            while (*src >= *dest)
            {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;

    map<pair<int, int>, bool> res;

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        v.push_back(i);
    }

    do
    {
        pair<int, int> p = make_pair(v[0], v[1]);
        res[p] = false;

    } while (next_combination(v.begin(), v.end(), 2));

    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;

        vector<int> x(N);
        for (int j = 0; j < k; j++)
        {
            cin >> x[j];
            x[j]--;
        }

        for (int j = 0; j < k - 1; j++)
        {
            for (int l = j + 1; l < k; l++)
            {
                pair<int, int> p = make_pair(x[j], x[l]);
                res[p] = true;
            }
        }
    }

    for (int j = 0; j < N - 1; j++)
    {
        for (int k = j + 1; k < N; k++)
        {
            pair<int, int> p = make_pair(j, k);
            if (!res[p])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
