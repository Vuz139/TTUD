#include <bits/stdc++.h>
using namespace std;

stack<double> sh;
stack<char> st;
int UT(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '(')
        return 0;

    return -1;
}
int HT(char x)
{
    if (x == '*' || x == '/' || x == '%' || x == '+' || x == '-' || x == '^')
        return 2;
    else
        return 1;
}
int check_num(char x)
{
    if (48 <= x && x <= 58)
    {
        return 1;
    }
    return 0;
}
double compute()
{
    double result = 0;
    double sh2 = sh.top();
    sh.pop();
    double sh1 = sh.top();
    sh.pop();
    char x = st.top();
    st.pop();
    if (x == '*')
    {
        result = sh1 * sh2;
    }
    else if (x == '/')
    {
        result = sh1 * 1.0 / sh2;
    }
    else if (x == '+')
    {
        result = sh1 + sh2;
    }
    else if (x == '-')
    {
        result = sh1 - sh2;
    }
    return result;
}
// (a+b*c)*c-d*e
void solve()
{
    string M;
    cin >> M;
    int len = M.size();
    for (int i = 0; i < len; i++)
    {
        if (!check_num(M[i]))
        {

            if (st.empty())
            {
                st.push(M[i]);
            }
            else
            {
                if (UT(M[i]) > UT(st.top()))
                {
                    st.push(M[i]);
                }
                else if (UT(M[i]) == -1)
                {
                    while (!st.empty() && st.top() != '(')
                    {
                        double res = compute();
                        sh.push(res);
                    }
                    if (st.empty())
                    {
                        cout << "NOT_ALLOWED";
                        exit(0);
                    }
                    else
                        st.pop();
                }
                else if (M[i] == '(')
                {
                    st.push(M[i]);
                }
                else
                {
                    double res = compute();
                    sh.push(res);
                    st.push(M[i]);
                }
            }
        }

        else
        {
            string number_ = "";
            while (check_num(M[i]))
            {
                number_ += M[i];
                i++;
            }
            int temp = stoi(number_);
            i--;
            sh.push(temp);
        }
    }
    while (!st.empty() && sh.size() > 1)
    {
        double res = compute();
        sh.push(res);
    }
    if (!st.empty())
    {
        cout << "NOT_ALLOWED";
    }
    else
    {
        cout << sh.top() << endl;
    }
    // while (!sh.empty())
    // {

    //     sh.pop();
    // }
}
int main()
{
    solve();
    return 1;
}