#include <bits/stdc++.h>

using namespace std;

struct Birthday
{
    int year;
    int month;
    int day;
    Birthday(int year, int month, int day) : year(year), month(month), day(day) {}
};
int compare_birthdays(Birthday p1, Birthday p2)
{
    if (p1.year == p2.year)
    {
        if (p1.month == p2.month)
        {
            if (p1.day == p2.day)
            {
                return 0;
            }
            else
            {
                if (p1.day < p2.day)
                    return -1;
                else
                    return 1;
            }
        }
        else
        {
            if (p1.month < p2.month)
                return -1;
            else
                return 1;
        }
    }
    else
    {
        if (p1.year < p2.year)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}
struct Person
{
    string code;
    Birthday birthday;
    string farther_code;
    string mother_code;
    char is_valid;
    string region_code;
    Person(string code, Birthday birthday, string farther_code, string mother_code, char is_valid, string region_code) : code(code), birthday(birthday), farther_code(farther_code), mother_code(mother_code), is_valid(is_valid), region_code(region_code) {}
};

void print_person(const Person &p)
{
    cout << p.code << " " << p.birthday.year << " " << p.birthday.month << " " << p.birthday.day << " " << p.mother_code << " " << p.farther_code << " " << p.is_valid << " " << p.region_code << endl;
}

vector<Person> people;
map<string, int> related_person;
void NUMBER_PEOPLE()
{
    cout << people.size() << endl;
}
void NUMBER_PEOPLE_BORN_AT(Birthday bd)
{
    int count = 0;
    for (Person p : people)
    {
        if (compare_birthdays(bd, p.birthday) == 0)
        {
            count++;
        }
    }
    cout << count << endl;
}
void NUMBER_PEOPLE_BORN_IN(Birthday bd1, Birthday bd2)
{
    int count = 0;
    for (Person p : people)
    {
        if (compare_birthdays(bd1, p.birthday) == -1 && compare_birthdays(bd2, p.birthday) == 1)
        {
            count++;
        }
    }
    cout << count << endl;
}
void COMPUTE_RELATED_BORN()
{
    related_person["0000000"] = -1;
    queue<Person> q;

    for (Person p : people)
    {
        q.push(p);
    }
    while (!q.empty())
    {
        Person p = q.front();
        q.pop();
        if (related_person.find(p.farther_code) == related_person.end() || related_person.find(p.mother_code) == related_person.end())
        {
            q.push(p);
        }
        else
        {
            related_person[p.code] = 1 + max(related_person[p.farther_code], related_person[p.mother_code]);
        }
    }
}

void solve()
{
    string query;
    string farther_code, mother_code;
    int y, m, d;
    char is_valid;
    string region_code;

    while (1)
    {
        cin >> query;
        if (query != "*")
        {
            scanf("%d-%d-%d", &y, &m, &d);
            cin >> farther_code;
            cin >> mother_code;
            cin >> is_valid;
            cin >> region_code;

            people.push_back(Person(query, Birthday(y, m, d), farther_code, mother_code, is_valid, region_code));
        }
        else
        {
            break;
        }
    }
    COMPUTE_RELATED_BORN();
    // for (const Person p : people)
    // {
    //     print_person(p);
    // }

    while (1)
    {
        cin >> query;
        if (query != "***")
        {
            if (query == "NUMBER_PEOPLE")
            {
                NUMBER_PEOPLE();
            }
            else if (query == "NUMBER_PEOPLE_BORN_AT")
            {
                scanf("%d-%d-%d", &y, &m, &d);
                NUMBER_PEOPLE_BORN_AT(Birthday(y, m, d));
            }
            else if (query == "NUMBER_PEOPLE_BORN_IN")
            {
                int y1, m1, d1;
                int y2, m2, d2;
                scanf("%d-%d-%d", &y1, &m1, &d1);
                scanf("%d-%d-%d", &y2, &m2, &d2);
                NUMBER_PEOPLE_BORN_IN(Birthday(y1, m1, d1), Birthday(y2, m2, d2));
            }
            else if (query == "RELATED_BORN")
            {
                cin >> query;
                cout << related_person[query] << endl;
            }
        }
        else
        {
            break;
        }
    }
}

int main()
{
    freopen("../input.inp", "r", stdin);
    freopen("../output.outp", "w", stdout);
    solve();
    return 1;
}

/*

00001 f_code: 00002, m_code: 00003;
00003 f_code: 00000, m_code: 00000;


*/