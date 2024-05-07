#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

class Queue
{
private:
    int data[MAX];
    int head=0, tail=0;
public:
    void push(int n);
    void pop();
    void size();
    void empty();
    void front();
    void back();
};

void Queue::push(int n){
    this->data[this->tail] = n;
    this->tail++;
}
void Queue::pop(){
    if (this->head == this->tail){cout << -1 << '\n';}
    else {cout << this->data[this->head] << '\n'; this->head++;}
}
void Queue::size(){
    cout << this->tail - this->head << '\n';
}
void Queue::empty(){
    if (this->head == this->tail){cout << 1 << '\n';}
    else {cout << 0 << '\n';}
}
void Queue::front(){
    if (this->head == this->tail){cout << -1 << '\n';}
    else {cout << this->data[this->head] << '\n';}
}
void Queue::back(){
    if (this->head == this->tail){cout << -1 << '\n';}
    else {cout << this->data[this->tail - 1] << '\n';}
}

int main()
{
    Queue my_queue;

    int N, push_number;
    string order;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> order;
        if (order == "push"){cin >> push_number; my_queue.push(push_number);}
        else if (order == "front") {my_queue.front();}
        else if (order == "back") {my_queue.back();}
        else if (order == "empty") {my_queue.empty();}
        else if (order == "size") {my_queue.size();}
        else if (order == "pop") {my_queue.pop();}
    }
    return 0;
}