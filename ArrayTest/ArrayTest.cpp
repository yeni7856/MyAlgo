// ArrayTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>

using namespace std;

//동적 메모리 할당예제
int main()
{
	//동적 메모리 할당
	int* ptr = new int[3] {};
	ptr[0] = 10;
	ptr[1] = 20;

	for (int i = 0; i < 3; i++)
	{
		cout << ptr[i] << endl;
	}
	//동적 메모리 해제
	delete[] ptr;
	ptr = nullptr;
}

//C++언어 배열 구현 - 점수들의 평균을 구하라
//int main()
//{
//	array<int, 5> scores = { 50, 60, 70, 80, 90 };
//
//	//합계
//	int sum = 0;
//	for (int i = 0; i < scores.size(); i++)
//	{
//		sum += scores[i];
//	}
//	//평균
//	float avg = (float)sum / scores.size();
//
//	//출력
//	cout << "Average Score : " << avg << endl;
//}

//C언어 배열 구현 - 점수들의 평균을 구하라
//int main()
//{
//    //배열 선언
//    int scores[5] = { 50, 60, 70, 80, 90 };
//
//    //int length = sizeof(scores) / sizeof(scores[0]);
//    int length = size(scores);
//
//    //
//    int sum = 0;
//    for (int i = 0; i < length; i++) 
//    {
//        sum += scores[i];
//    }
//    //평균
//    float avg = (float)sum / length;
//
//    //출력
//    cout << "Average Score : " << avg << endl;
//}
