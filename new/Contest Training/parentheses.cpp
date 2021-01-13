#include <iostream>
#include <stack>
using namespace std;
int result[10000],count=0;
void parentheses()
{
    stack<char> a;
    string s;
    cin >> s;
    int flag = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            a.push(s[i]);
            flag = 1;
        }
        if (!a.empty()) {
            if (s[i] == '}') {
                if (a.top() == '{')
                {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ']') {
                if (a.top() == '[') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ')') {
                if (a.top() == '(') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }
    if ((a.empty()) && (flag == 1))
        result[count]=1;
    else
        result[count]=0;
}
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        parentheses();
        count ++;
    }
    for (int i = 0; i < t; i++) {
        cout<< result[i] << endl;
    }

    return 0;
}






