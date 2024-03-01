#include <iostream>
using namespace std;

class Queue
{
    private:
        int front;
        int rear;
        int data[100000];
    public:
        // 큐 초기화 생성자 
        Queue() : front(-1), rear(-1) {}

        // 큐에 요소 추가 함수
        void enqueue(int value)
        {
            if (rear >= 99999)
            {
                cout << "Queue is full" << "\n";
            }
            else
            {
                // 큐가 비어있으면 front를 0으로 설정한다
                if (front == -1 ) front = 0; 
                data[++rear] = value;
            }
        }

        // 큐에서 요소 제거
        int dequeue()
        {
            if (front == -1 || front > rear)
            {
                return -1;
            } 
            else
            {
                // 가장 앞에 있는 요소를 반환하고 front를 1증가
                return data[front++];
            }
        }

        // 큐의 내용 출력하는 함수
        void enqueue_print()
        {
            if (front == -1 || front > rear)
            {
                cout << "Queue is empty" << "\n";
            }
            else
            {
                for (int i=front; i<= rear; i++)
                {
                    cout << data[i] << " ";
                }
                cout << "\n";
            }
        }
        
        // front
        int __front()
        {
            if (front == -1 || front > rear)
            {
                return -1;
            }
            else
            {
                return data[front];
            }
        }

        // rear
        int __rear()
        {
            if (rear == -1 || front > rear)
            {
                return -1;
            }
            else
            {
                return data[rear];
            }
        }

        // size
        int size() 
        {
            if (isEmpty()) {
                return 0;
            } else {
                return rear - front + 1;
            }
        }
        bool isEmpty()
        {
            return front == -1 || front > rear;
        }
};

int n, m;
string inp;
int main()
{
// #ifdef KMC
	freopen("input.txt", "r", stdin);
// #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Queue q;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> inp;
        if  (inp == "push")
        {
            cin >> m;
            q.enqueue(m);
        }
        else if (inp == "pop")
        {
            cout << q.dequeue() << "\n";
        }
        else if (inp == "size")
        {
            cout << q.size() << "\n";
        }
        else if (inp == "front")
        {
            cout << q.__front() << "\n";
        }
        else if (inp == "back")
        {
            cout << q.__rear() << "\n";
        }
        else if (inp == "empty")
        {
            cout << q.isEmpty() << "\n";
        }

    }

    return 0;
}