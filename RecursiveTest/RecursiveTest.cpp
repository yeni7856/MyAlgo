// RecursiveTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

//순열
//n개의 원소로 구성된 집합이 있을 경우, 모든 원소를 서로 다른 순서로 나열하는 순열 방법을 모두출력
//순열 재귀 함수 구현 방법
// 1. 첫 번째 원소를 모든 원소와 각각 맞바꾸기 (swap)
// 2. 첫 번째 원소를 제외한 나머지 원소들의 집합으로 순열 구하기
template<typename T>
void print_vector(vector<T>& vec)
{
    for (auto& e : vec)
    {
        cout << e << ",";
    }
    cout << endl;
}
//순열 구해 출력
void permutation(vector<int>& vec, int k)       //k=자리
{
    //기저조건
    if (k == vec.size() - 1)
    {
        //바꾼 자리 출력
        print_vector(vec);
        return;
    }
    for (int i = k; i < vec.size(); i++)
    {
        swap(vec[k], vec[i]);               //처음에는 0과 0이 바뀜 //자리 바꾸기 - 앞자리 고정
        permutation(vec, k + 1);        //재귀 호출
        swap(vec[k], vec[i]);               //제자리 돌리기
    }
}

//std::next_permutation(0 사용예제
template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last);



//최대 공약수와 최소 공배수 //유클리드 알고리즘
//최대공약수 18,24
//gcd(24,18) -> gcd(18, 24%18) -> gcd(18,6) ->  gcd(6,18%6) -> gcd(6,0) -> 6
//int gcd(int a, int b)
//{
//    if (b == 0)
//        return a;
//    else
//        return gcd(b, a % b);
//}
////최소공배수
//int lcm(int a, int b)
//{
//    return a * b / gcd(a, b);
//}


//문자열 뒤집기
//문자열의 각 문자 순서를 역순으로 변경
//string reverse(const string& str)
//{
//    if (str.length() == 0)
//        return "";
//    else
//        return reverse(str.substr(1)) + str[0];
//}


//피보나치 수
//첫번째 및 둘째 항이 1이며 그뒤의 모든항은 바로 앞 두 항의 합인 수열 
//중복되는 부분 문제로 인해 계산 효율이 떨어짐
//캐시를 사용하여 문제를 해결할수 있음
//long long fibo(int n)
//{
//    if (n <= 1)
//        return n;
//    else
//        return fibo(n - 1) + fibo(n - 2);
//}


//팩토리얼
//20보다 같거나 작은 자연수 N이 입력으로 주어질 경우, 1* 2* 3* ...* (n-1)*n을 계산하는 팩토리얼 함수를 작성하시오
//int factorial(int n)
//{
//    if (n == 0)
//        return 1;
//    else
//        return n * factorial(n - 1);
//}


//재귀 알고리즘
//int sum(int n)
//{
//    int s = 0;
//    for (int i = 0; i <= n; i++)          //for 형태if return 바꿀숭있음
//        s += i;
//    return s;
//}
//int sum(int n)
//{
//    if (n == 1)
//        return 1;        
//    else
//        return n + sum(n - 1);
//}

int main()
{
    //팩토리얼
    //cout << factorial(5) << endl;           //120
    //cout << factorial(10) << endl;          //3628800    
    //cout << factorial(20) << endl;          //2432902008176640000
    
    //피보나치 수
    //for (int i = 1; i <= 10; i++)
    //    cout << fibo(i) << ",";
    //cout << endl;

    //문자열 뒤집기
    //cout << reverse("Hello") << endl;

    //최대공약수
    //int a = gcd(24, 18);
    //최소공배수
    //int b = lcm(3, 4);
    //cout << "최대공약수 : " << a << endl;
    //cout << "최소공배수 : " << b << endl;
    //cout << std::gcd(24, 18) << endl;   //17버전 이상만 가능 

    //재귀 알고리즘 사용 예제
    //vector<int> vec{ 1,2,3,4 };
    //permutation(vec, 0);
    //print_vector(vec);

    //std::next_permutation(0 사용예제 //C++ 순열 구하기 함수
    vector<int> vec{ 1,2,3,4 };
    std::sort(vec.begin(), vec.end());
    do {
        print_vector(vec);
    } while (std::next_permutation(vec.begin(), vec.end()));
}

