// // 연결 리스트

// // BOJ 1406
// // 한 줄로 된 간단한 에디터를 구현
// // 영어 소문자만 입력 가능하며, 최대 600,000 글자까지 입력 가능
// // 여기에 커서라는 것이 있는데, 이는 각 글자 사이 어디에든 존재할 수 있음
// // 커서의 기능은 다음과 같다.
// // L : 커서를 왼쪽으로 한 칸 옮김(커서가 문장의 맨 앞이면 무시됨)
// // D : 커서를 오른쪽으로 한 칸 옮김(커서가 문장의 맨 뒤이면 무시됨)
// // B : 커서 왼쪽의 문자를 삭제함(커서가 문장의 맨 앞이면 무시됨)
// //     삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
// // P $ : $라는 문자를 커서 왼쪽에 추가함
// // 초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는
// // 문자열을 구하는 프로그램을 작성하라. 이때 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치한다고 가정.

// // 입력
// // 첫 줄에는 초기 편집기에 입력되어 있는 문자열(길이는 100,000을 넘지 않음)
// // 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M (1 <= M <= 500,000)

// // 출력
// // 최종 결과 문자열을 출력한다.


// // 구현

// // 해야할 것은 우선 Linked list 형태를 구성하고
// // 이때 커서의 위치를 어떻게 표현할 지 생각해야 함.
// // 가장 좋은 것은 struct 등으로 Node를 구성한 후에 진행하는 것이라 생각됨
// // 다만 그거보다 arr 사용한 구현으로 주소값 등을 구성하는 것이 커서 표현 등도 더 쉽다고 생각됨

// // arr 사용한 구현
// // char Data[600001] : 데이터를 담고 있을 char arr
// // int Pred[600001]  : 이전 노드의 주소를 담고 있을 int arr
// // int Next[600001]  : 다음 노드의 주소를 담고 있을 int arr
// // int unused        : 다음에 사용할 메모리 위치를 담고 있는 int
// // int cursor        : 현재 커서 위치


#include <bits/stdc++.h>

using namespace std;

const int MAX = 600001;
char Data[MAX];
int Pred[MAX];
int Next[MAX];
int unused = 1; // 시작은 1부터
int cursor = 0; // 초기 커서 위치

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int nOrders;
    char order;

    cin >> str >> nOrders;

    // 각 주소를 -1로 초기화
    fill(Pred, Pred + MAX, -1);
    fill(Next, Next + MAX, -1);

    // 초기 입력된 str을 사용해서 Linked List 초기화
    for (int i = 0; i < str.length(); i++) {
        Data[unused] = str[i];
        Pred[unused] = cursor;
        Next[cursor] = unused;
        cursor = unused;
        unused++;
    }

    for (int i = 0; i < nOrders; i++) {
        cin >> order;

        // 각 케이스에 대한 구현

        // 먼저 커서 이동은 커서가 각 위치의 마지막 지점이 아니면 그냥 단순 이동
        if (order == 'L') {
            if (cursor != 0) cursor = Pred[cursor];
        } else if (order == 'D') {  
            if (Next[cursor] != -1) cursor = Next[cursor];
        }

        // 삭제는 중간 데이터는 처리하지 않고, 가리키는 주소만 바꿔줌
        else if (order == 'B') {
            if (cursor != 0) {
                Next[Pred[cursor]] = Next[cursor];
                if (Next[cursor] != -1) Pred[Next[cursor]] = Pred[cursor];
                cursor = Pred[cursor];
            }
        }

        // 추가는 unused에 해당하는 위치에 새로운 노드를 만들고, 그 위치는 cursor에 해당하는 위치로 설정함
        // 이후 앞, 뒤에 해당하는 애들도 주소 바꿔줌
        else if (order == 'P') {
            cin >> order;   // 입력이 P라면 i의 개수를 증가시키지 않고 새로 입력을 받아야 함
            Data[unused] = order;
            Pred[unused] = cursor;
            Next[unused] = Next[cursor];
            if (Next[cursor] != -1) Pred[Next[cursor]] = unused;
            Next[cursor] = unused;
            cursor = Next[cursor];
            unused++;
        }
    }

    int cur = Next[0];
    while (cur != -1) {
        cout << Data[cur];
        cur = Next[cur];
    }
    cout << '\n';

    return 0;
}