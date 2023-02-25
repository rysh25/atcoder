#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<string, string> name;

    for (int i = 0; i < N; i++)
    {
        string s, t;
        cin >> s >> t;
        name[s] = t;
    }

    unordered_map<string, bool> used;

    auto iter = name.begin();
    while (iter != name.end())
    {
        cout << "[" << iter->first << ","
             << iter->second << "]\n";

        if (used[iter->first])
        {
            ++iter;
            continue;
        }

        string next = iter->second;
        while (true)
        {
            auto i = name.find(next);
            if (i == name.end())
            {
                used[iter->first] = true;
                continue;
            }

            next = i->second;
        }

        ++iter;
    }

    return 0;
}
