// 옥상 정원 꾸미기
// N개의 빌딩이 있는 도시에서 다른 빌딩의 옥상을 볼 수 있는 수를 모두 더한 값 출력
// 빌딩은 자신의 오른쪽만 볼 수 있고, 자신보다 같거나 높은 빌딩이 나오면 그 빌딩은 보지 못함

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, height;
    stack<int> building;
    long long answer = 0;
    cin >> N;

    while(N--){
        cin >> height;
        // 이전 building의 높이가 나보다 크지 않으면 제거(= 나를 보지 못하는 애들 제거)
        while(!building.empty() && building.top() <= height) { building.pop(); }
        // 나머지는 다 나를 볼 수 있으므로 더해줌
        answer += building.size();
        // 현재 빌딩을 스택에 추가
        building.push(height);
    }

    cout << answer << '\n';

    return 0;
}