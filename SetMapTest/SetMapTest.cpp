// SetMapTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

// map 활용
int main()
{
    //
    map<string, int> fruits;
    fruits.insert({ "apple", 1000 });
    fruits.insert({ "banana", 1500 });
    fruits["orange"] = 3000;
    fruits["grape"] = 4000;
    fruits["lemon"] = 5000;

    for(auto [name,price] : fruits)
    {
        cout << name << " is " << price << " won " << endl;
    }

}

//set 활용 예제'
/*
int main()
{
    set<int> adds{ 1,7,5,3,9, };            //재정렬

    for (auto n : adds)
    {
        cout << n << ",";
    }
    cout << endl;

    set<int, greater<>> evens{ 2,4,6,8, };          //내림차순 중복 허용안됨
    evens.insert(10);
    evens.insert(2);

    if (evens.find(4) != evens.end())
    {
        cout << "4 is even!" << endl;
    }
    else 
    {
        cout << "4 is not even!" << endl;
    }

    for (auto n : evens)
    {
        cout << n << ",";
    }
    cout << endl;

    using psi = pair<string, int>;
    set<psi> managers{ {"Amelia", 29},{"Noah", 25},{"olivaia",30},{"Sophia", 40} };
    managers.insert(make_pair("George", 35));

    psi person1 = { "Noah", 25 };
    if (managers.find(person1) != managers.end())
    {
        cout << person1.first << "is a managers!" << endl;
    }
    else
    {
        cout << person1.first << "is not a manager!" << endl;
    }
    managers.erase({ "Sophia",40 });
    managers.erase({ "Noah",25});

    for (auto m : managers)
    {
        cout << m.first << "(" << m.second << ")" << endl;
    }

}
*/

