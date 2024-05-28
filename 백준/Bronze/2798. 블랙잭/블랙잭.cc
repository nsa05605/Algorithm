// 필수 문제
// 블랙잭 (백준 - 2798)

// 문제 정의
// 카드의 합이 21일 넘지 않는 한도 내에서, 카드의 합을 최대한 크게 만드는 게임
// N 장의 카드 중 3장을 뽑아 그 합이 M과 최대한 가깝게 만들어야 한다.
// N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가깝도록 만들 수 있는 3장의 합을 출력하라

// 입력
// 처음에 카드의 개수 N (3 <= N <= 100)과 M (10 <= M <= 300,000)
// 다음 줄에는 카드에 쓰여진 수가 주어짐

// 풀이
// 가장 간단하게 푸는 방법은 Brute-Force 검사를 거치는 방법이 있을 것 같음
// 뭔가 DP로도 가능할 것 같은데, 확실히 모르겠음
// BF 검사로 푸는 방법은 그냥 시작 전에 M과의 차이를 기억하는 residual 변수를 하나 만들고,
// for문 3개 만들어서 하나씩 검사하면서 합이 M보다 크거나, M과의 차이가 residual보다 크면 넘기는 방법으로 구현

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();

    int N, M;
    cin >> N >> M;

    int num; vector<int> cards; // 입력받을 변수 num과 해당 변수들을 담을 벡터 cards
    for (int i = 0; i < N; i++){
        cin >> num;
        cards.push_back(num);
    }

    int residual = 300001;   // 각 단계에서 3개의 합과 M 간의 최소 차이를 기억하기 위함
    int sum = 0;        // 각 단계에서 구할 합
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            for (int k = j+1; k < N; k++){
                int curr = cards[i] + cards[j] + cards[k];
                if (curr > M || (M - curr) > residual) {continue;}    // 합이 M보다 크거나, M과의 차이가 기존 residual 보다 크면 넘김
                residual = M - curr;
                sum = curr;
            }
        }
    }
    cout << sum << endl;
    return 0;
}