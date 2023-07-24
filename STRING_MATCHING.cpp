#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string temp;
    string sentence;

    getline(cin, temp);
    getline(cin, sentence);

    int len = temp.length();
    int sentence_len = sentence.length();
    int j = 0;
    int count = 0;

    for (int i = 0; i < sentence_len; i++)
    {
        if (sentence[i] != temp[j])
            continue;
        // if (j == 0)
        // {
        //     if (isalpha(sentence[i - 1]) || isdigit(sentence[i - 1]))
        //     {
        //         continue;
        //     }
        // }
        j++;
        if (j == len)
        {

            j = 0;

            count++;
        }
    }
    cout << count;
}

int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}