/// 프로그래머스 - 야근 지수
// 
// 야근 피로도는 야근을 시작한 시점에서 남은 일의 작업량을 제곱하여 더한 값이다.
// 1시간 동안 작업량 1만큼 처리할 수 있다고 할 때, 퇴근까지 남은 N 시간과 각 일에 대한 작업량 works에 대해 야근 피로도를 최소화한 값을 리턴하는 solution 작성

// works는 길이 1 이상 20,000 이하 배열
// wokrs의 원소는 50,000 이하 자연수
// n은 1,000,000 이하인 자연수

// 예시
// works = [4,3,3], n = 4, result = 2^2 + 2^2 + 2^2 = 12

// 생각 정리
// works의 최소값, 최대값을 찾고, 최대값부터 우선적으로 낮춰가면 되지 않을까?
// 최소값, 최대값을 찾는 것은 vector 내장 사용해도 되고, 20,000개 내에서 찾는 거라 그냥 찾아도 계산 복잡도에는 크게 영향 없을 듯

#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    sort(works.rbegin(), works.rend());

    int idx = 0;
    while(n > 0){
        // 가장 앞의 값이 가장 크면, 그 값만 1 감소
        if (works[idx] > works[idx+1]) {works[idx]--; n--; cout << "works[idx] decrease" << '\n';}
        // 가장 앞의 값이 가장 큰데 그 뒤의 값들도 같은 값이면, 모두 1 감소
        else if (works[idx] == works[idx+1]){
            if(works[idx]==0){break;}   // 값이 모두 0이 된 경우, 음수로 가는 것을 방지
            int i=0; works[idx]--; n--;
            while(works[idx+i] < works[idx+i+1]){
                if (n == 0) {break;}
                works[idx+i+1]--; n--; i++;
            }
        }
    }

    for (int i = 0; i < works.size(); i++){
        cout << "works[i] : " << works[i] << '\n';
        answer += pow(works[i],2);
    }
    return answer;
}