#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

// 가장 위에 x를 추가하는 함수
void push(int x){
    dat[pos] = x; pos++;
}

// 가장 위의 값을 제거하는 함수
void pop(){
    if(pos > 0){pos--; cout << dat[pos] << '\n';}
    else if (pos == 0){cout << -1 << '\n';}
}

int size(){
    return pos;
}

int empty(){
    if (pos == 0){return 1;}
    else {return 0;}
}

// 가장 위의 값을 출력하는 함수
int top(){
    if (pos > 0){return dat[pos-1];}
    else if (pos == 0){return -1;}
}

// BOJ 10828 스택
// 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
// 명령은 총 5개
// push X : 정수 X를 스택에 넣는 연산
// pop : 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력. 만약 스택에 들어있는 정수가 없으면 -1
// size : 스택에 들어있는 정수의 개수 출력
// empty : 스택이 비어있으면 1, 아니면 0 출력
// top : 스택의 가장 위에 있는 정수 출력. 만약 스택에 정수가 없으면 -1

// 입력은 첫째 줄에 명령의 수 N (1 <= N <= 10,000)

int main(void) {
    int nOrders;
    string order;

    cin >> nOrders;
    for (int i = 0; i < nOrders; i++){
        cin >> order;
        if (order == "push"){
            cin >> order;
            push(stoi(order));
        }
        else if (order == "pop"){pop();}
        else if (order == "size"){cout << size() << '\n';}
        else if (order == "empty"){cout << empty() << '\n';}
        else if (order == "top"){cout << top() << '\n';}
    }
}