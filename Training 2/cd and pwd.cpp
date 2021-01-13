#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<char> pwd;
    string input;
    int valid = 0, n;
    cin >> n;
    pwd.push_back('/');
    while (valid != n)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "pwd")
        {
            for (int i = 0; i < pwd.size(); i++)
            {
                cout << pwd.at(i);
            }
            cout << endl;
        }
        if (cmd == "cd")
        {
            cin >> input;
            for (int i = 0; i < input.length(); i++)
            {
                if (input.at(i) == '/' && i == 0)
                {
                    pwd.clear();
                    pwd.push_back('/');
                    continue;
                }
                if (input.at(i) == '.' && input.at(i + 1) == '.')
                {
                    pwd.pop_back();
                    int j = pwd.size() - 1;
                    while (pwd.at(j) != '/')
                    {
                        pwd.pop_back();
                        j--;
                    }
                    pwd.pop_back();
                    i = i + 1;
                }
                else
                {
                    pwd.push_back(input.at(i));
                }
            }
            pwd.push_back('/');
        }
        valid++;
    }
}