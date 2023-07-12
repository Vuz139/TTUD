#include <bits/stdc++.h>

using namespace std;

struct Birthday
{
    int year;
    int month;
    int day;
    Birthday(int year, int month, int day) : year(year), month(month), day(day) {}
};
bool compare_birthdays(Birthday p1, Birthday p2)
{
    if (p1.year == p2.year)
    {
        if (p1.month == p2.month)
        {
            if (p1.day == p2.day)
            {
                return true;
            }
        }
    }
    return false;
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

void NUMBER_PEOPLE()
{
    cout << people.size() << endl;
}
void NUMBER_PEOPLE_BORN_AT(Birthday bd)
{
    int count = 0;
    for (Person p : people)
    {
        if (compare_birthdays(bd, p.birthday))
        {
            count++;
        }
    }
    cout << count << endl;
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