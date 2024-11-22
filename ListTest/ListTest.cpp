// ListTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;


struct Node
{
    int data;                   //저장할 데이터
    Node* next;             //다음에 오는 노드 
};

class LinkedList
{
private :
    Node* head;           //맨 앞에 있는 노드              

public:
    //생성자
    LinkedList() : head(NULL)   //해드는 Null로 기준 
    {
    }
    //소멸자
    ~LinkedList() 
    {
        //생성한 node의 메모리 해제
        while(!empty())
        {
            pop_front();
        }
    }

    //매개변수롤 데이터 (value)를 입력받아 리스트 맨 앞에 삽입하기 //노드형태
    void push_front(int value) 
    {
        //데이터(value)를 가진 노드 생성 
        Node* new_node = new Node{ value, NULL };
        
        if (head != NULL)
        {
            new_node->next = head;      //현재 head 가 가르키는 자리 
        }

        head = new_node;
    }

    //리스트 맨 앞에 있는 데이터 삭제하기
    void pop_front()
    {
        if (head == NULL)           //맨앞에있는 데이터 삭제 
            return;     

        Node* first = head;
        head = head->next;      //원래 첫번째에 있던 넥스트에 덮어씌우기 
        delete first;               //첫번째 메모리 삭제
    }

    //리스트들 출력 
    void print_all()
    {
        Node* curr = head;

        //curr가 null이 될때까지 반복
        while (curr != NULL)
        {
            //현재 curr 노드의 데이터를 출력
            cout << curr->data << ", ";

            //curr 노드를 다음 노드로 이동한다
            curr = curr->next;
        }
        cout << endl;
    }
    //데이터 유무
    bool empty()                            //비어있을때 true
    {
        return head == NULL;
    }

};

int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();

    ll.pop_front();
    ll.print_all();

    ll.push_front(40);
    ll.print_all();
}

