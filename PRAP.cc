#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int Ls[16][11];
int visited[16];
int reviewers[11];
int curr_min = INT_MAX;
int p_rvers[16][11];
int curr_max = -1;
void solution()
{
    // int max_ = -1;
    // for (int v : reviewers)
    // {
    //     max_ = max(max_, v);
    // }
    // curr_min = min(curr_min, max_);
    curr_min = min(curr_min, curr_max);
}
struct compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }
};
void pick_j(int j)
{

    int len = Ls[j][0];
    int count_ = 0;
    int chosed[len + 1];

    while (count_ < b)
    {
        int max_now = INT_MAX;
        int index_max = -1;
        for (int i = 1; i <= len; i++)
        {
            if (reviewers[Ls[j][i]] < max_now && !chosed[i])
            {
                max_now = reviewers[Ls[j][i]];
                index_max = i;
            }
        }
        chosed[index_max] = 1;
        p_rvers[j][count_] = Ls[j][index_max];
        reviewers[Ls[j][index_max]]++;
        curr_max = max(reviewers[Ls[j][index_max]], curr_max);
        count_++;
    }
}

void TRY(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            int temp = curr_max;
            visited[j] = 1;
            pick_j(j);
            if (i == n - 1)
            {
                solution();
            }
            else
            {
                if (curr_max < curr_min)
                    TRY(i + 1);
            }
            visited[j] = 0;
            for (int kkk = 0; kkk < b; kkk++)
            {
                reviewers[p_rvers[j][kkk]]--;
            }
            curr_max = temp;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin >> n >> m >> b;
    int k;
    int not_found = 0;
    for (int i = 1; i <= n; i++)
    {

        cin >> k;
        if (k < b)
            not_found++;
        Ls[i][0] = k;
        for (int j = 1; j <= k; j++)
        {
            cin >> Ls[i][j];
        }
    }
    if (not_found)
    {
        cout << -1;
    }
    else
    {
        TRY(0);
        cout << curr_min;
    }
}