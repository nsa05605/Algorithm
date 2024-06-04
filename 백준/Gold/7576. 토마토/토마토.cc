// 문제 정의
// 격자 모양의 상자의 칸에 토마토가 담겨 있음
// 익은 토마토 주변(상하좌우)의 토마토들은 하루가 지나면 익게 됨
// 토마토가 익는 최소 일수를 출력하라

// 입력
// 첫 줄에는 상자의 크기를 나타내는 두 정수 M(가로), N(세로) (2 <= M, N <= 1000)
// 둘째 줄부터는 상자에 담긴 토마토의 정보
// 1은 익은 토마토, 0은 익지 않은 토마토, -1은 빈 칸

// 문제 풀이
// 일단 주변으로 한 칸씩 이동하는데 최소 일수를 찾아야 하므로, BFS로 찾는 것이 맞을 듯한데,
// 또 결국 하나씩 이동하면서 가장 멀리 있는 칸까지 가야하므로 DFS로 해도 될 것 같기도 하고
// DFS로 생각해보니 어디가 마지막인지 검사하기가 어려울 듯 싶음. 그래서 BFS로 구현
// 하나의 섬이 아닌 경우에는 그냥 -1 출력하면 될 듯 하고

// 풀이하다보니 계속 오류가 발생해서 구글 참고해서 진행함

#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int M, N;
int answer = 0;
int box[MAX][MAX];
queue<pair<int,int>> q;

void BFS()
{
    while(!q.empty()){
        int cur_x = q.front().second, cur_y = q.front().first; q.pop();
        for (int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i], next_y = cur_y + dy[i];
            if(next_x >= 0 && next_y >= 0 && next_x < M && next_y < N && box[next_y][next_x] == 0)
            {
                box[next_y][next_x] = box[cur_y][cur_x] + 1;
                q.push({next_y, next_x});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> box[i][j];
            if (box[i][j] == 1) q.push({i,j});  // 토마토가 익은 상태이면, 큐에 넣어놓음
        }
    }

    BFS();

    int max = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            //안 익은 토마토가 존재할 경우
            if(box[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            //최댓값 계산
            if(max < box[i][j]) max = box[i][j];
        }
    }

    //최댓값-1 출력
    cout << max-1 << "\n";

    return 0;
}