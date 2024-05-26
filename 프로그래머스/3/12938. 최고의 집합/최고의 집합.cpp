/// 프로그래머스 - 최고의 집합

// 문제 정의
// 자연수 n개로 이뤄진 집합 중 다음 두 조건을 만족하는 집합을 최고의 집합이라 한다.
// 1. 각 원소의 합이 S가 되는 수의 집합
// 2. 위 조건을 만족하면서 각 원소의 곱이 최대가 되는 집합
// 예를 들어 자연수 2개로 이뤄진 집합 중 합이 9가 되는 집합은 총 4개
// 그중 각 원소의 곱이 최대인 {4,5}가 최고의 집합이 된다.
// 집합의 원소 개수 n과 모든 원소들의 합 s가 매개변수로 주어질 때, 최고의 집합을 출력

// 제한 사항
// 최고의 집합은 오름차순으로 정렬된 1차원 배열(list, vector)로 return
// 만약 최고의 집합이 존재하지 않는 경우, 크기가 1인 1차원 배열에 -1을 채워서 return
// n은 1 이상 10,000 이하
// s는 1 이상 100,000,000 이하

// 문제 풀이
// 합이 s가 되는 자연수 n개를 찾는 것은 어떻게 할까
// 일반적으로 n개가 서로 비슷한 수일 때 가장 큰 값이 나오는 것으로 보임
// s % n 했을 때, 나머지의 수를 판단하고,
// (s/n + 1)이 (s%n)개, (s / n)이 (n- s%n)개
// 해가 없는 경우는 n > s 인 경우를 말하는 듯

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;

    if(n > s){
        answer.push_back(-1);
        return answer;
    }

    int remain = s % n, share = s / n;
    int result = 1;
    for (int i = 0; i < n; i++){
        if (i >= n-remain){
            result *= (share+1); answer.push_back(share+1);
        }
        else{result *= (share); answer.push_back(share);}
    }
    
    return answer;
}

int main()
{
    vector<int> answer = solution(2,8);
    for (int i=0; i < answer.size(); i++){
        cout << answer[i] << '\n';
    }
    return 0;
}