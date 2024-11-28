// SortTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

//버블 정렬
void bubble_sort(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (data[j] < data[j - 1])
            {
                swap(data[j], data[j - 1]);         //swap 자리바꿔..
            }
        }
    }
}

//선택 정렬
void selection_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = n - 1; j > i; j--)
        {
            if (data[j] < data[idx])
            {
                idx = j;            //최소 값보다 더작은 값이나오면 j로 자리다시지정
            }
        }
        swap(data[i], data[idx]);
    }
}

//삽입 정렬
void insertion_sort(int data[], int n)
{
    for (int i = 1; i < n; i++)                     //1부터 n까지 돌려야함
    {
        int key = data[i];      //정렬되지 않은 데이터의 맨 왼쪽 값
        int j = i - 1;              //정렬되지 않은 데이터의 바로 앞자리
        while (j >= 0 && data[j] > key)         //가진 데이터가 key보다 작으면 멈춤
        {
            data[j + 1] = data[j];                     //옆에 자리로
            j--;
        }
        data[j + 1] = key;
    }                                               
}


//병합정렬 구현
int buff[256];
void merge(int data[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (data[i] <= data[j])
        {
            buff[k++] = data[i++];
        }
        else
        {
            buff[k++] = data[j++];
        }
    }
    //왼쪽에 데이터가 남아있으면
    while (i <= mid)
    {
        buff[k++] = data[i++];
    }
    //오른쪽에 데이터가 남아이으면
    while (j <= right)
    {
        buff[k++] = data[j++];     
    }
    //임시변수에 저장된 데이터를 다시 옮기기.
    for (int x = left; x <= right; x++)
    {
        data[x] = buff[x];
    }
}

//병합정렬
void merge_sort(int data[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(data, left, mid);
        merge_sort(data, mid + 1, right);
        merge(data, left, mid, right);

    }
}

//퀵정렬 구현
int partition(int data[], int left, int right)
{
    int pivot = data[left];
    int i = left + 1, j = right;
    while (true)
    {
        while (data[i] <= pivot && i <= right)      //i의 위치를 pivot 보다 큰값 까지 이동
            i++;
        while (data[j] > pivot && j > left)             //j의 위치를 pivot보다 작은값까지 이동
            j--;
        if (i < j)
            swap(data[i], data[j]);
        else
            break;
    }
    swap(data[left], data[j]);
    return j;
}

//퀵 정렬
void quick_sort(int data[], int left, int right)
{
    if (left < right)
    {
        int p = partition(data, left, right);
            quick_sort(data, left, p - 1);
            quick_sort(data, p + 1, right);
    }
}


int main()
{
    int data[] = { 1,4,5,2,3,6, };
    //bubble_sort(data, 5);
    //selection_sort(data, 5);
    //insertion_sort(data, 5);
    //merge_sort(data, 0, 7);
    //quick_sort(data, 0, size(data) - 1);
    //sort(begin(data), end(data));     //퀵 정렬 함수사용 
    for (auto n : data)
    {
        cout << n << ",";
    }
    cout << endl;

}

