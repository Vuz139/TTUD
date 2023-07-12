#include <bits/stdc++.h>

using namespace std;

struct quiz
{
    string date;
    string time;
    string user_id;
    string question_id;
};

vector<quiz> quizList;
map<string, int> frequency;

void input()
{
    quiz student;
    while (1)
    {
        cin >> student.date;
        if (student.date == "*")
            break;
        cin >> student.time >> student.user_id >> student.question_id;
        frequency[student.date] += 1;
        quizList.push_back(student);
    }

    for (auto v : frequency)
    {
        cout << v.first << " " << v.second << endl;
    }
}

int main()
{
    input();
}