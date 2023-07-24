#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
#define N 1000002
struct Node
{
    ull index;
    ull length;
    ull left;
    ull right;
};
Node c[N];
ull n;
stack<Node> s;
void clear()
{
    while (!s.empty())
        s.pop();
}
int main()
{
    Node temp;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i].length;
            c[i].index = i;
            while (!s.empty())
            {
                temp = s.top();
                if (temp.length >= c[i].length)
                    s.pop();
                else
                {
                    c[i].left = temp.index;
                    s.push(c[i]);
                    break;
                }
            }
            if (s.empty())
            {
                c[i].left = 0;
                s.push(c[i]);
            }
        }
        clear();
        for (int i = n; i >= 1; i--)
        {
            while (!s.empty())
            {
                temp = s.top();
                if (temp.length >= c[i].length)
                    s.pop();
                else
                {
                    c[i].right = temp.index;
                    s.push(c[i]);
                    break;
                }
            }
            if (s.empty())
            {
                c[i].right = 0;
                s.push(c[i]);
            }
        }
        ull res = 0;
        ull tmp;
        for (int i = 1; i <= n; i++)
        {
            if (c[i].left != 0 && c[i].right != 0)
            {
                tmp = (c[i].right - c[i].left - 1) * c[i].length;
            }
            else if (c[i].left != 0 && c[i].right == 0)
            {
                tmp = (n - c[i].left) * c[i].length;
            }
            else if (c[i].left == 0 && c[i].right != 0)
            {
                tmp = (c[i].right - 1) * c[i].length;
            }
            else
            {
                tmp = c[i].length * n;
            }
            if (res < tmp)
                res = tmp;
        }

        cout << res << endl;
        clear();
    };

    return 0;
}