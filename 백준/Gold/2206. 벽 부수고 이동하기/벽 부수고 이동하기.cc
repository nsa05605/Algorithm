// 문제 정의
// N x M 행렬 맵에서 0은 이동할 수 있는 곳, 1은 이동할 수 없는 벽을 의미함
// (1,1)에서 (N,M)까지 최단 거리를 계산하려함(시작부터 1)
// 전체 경로 중에 벽을 하나까지 부술 수 있음

// 입력
// 첫째 줄에 N, M이 주어진다. (1 <= N, M <= 1000)
// 이후 각 위치에 해당하는 0, 1을 입력

// 문제 풀이
// 일반적인 BFS를 생각하면 될 것 같음
// 다만 벽을 부수는 경우의 수가 추가되므로, 이 부분을 고려해야 함
// BFS를 실행하면서, 모든 경우에 대해 벽을 부수는 경우와 아닌 경우를 계산하고,
// 최단 경로를 찾도록 설계해보자

#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int N, M;

int matrix[MAX][MAX][2];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int BFS(int N, int M)
{
    queue<pair<int, pair<int,int>>> q;
    q.push({0, {0,0}});
    while(!q.empty())
    {   
        int broken = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == N-1 && y == M-1){
            return matrix[N-1][M-1][broken] + 1;
        }

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (matrix[nx][ny][0] == 1)
                {
                    if (!broken){
                        matrix[nx][ny][broken+1] = matrix[x][y][broken] + 1;
                        q.push({1,{nx, ny}});
                    }
                }
                else if (matrix[nx][ny][0] == 0)
                {
                    if (broken == 1 && matrix[nx][ny][broken]) continue;
                    matrix[nx][ny][broken] = matrix[x][y][broken] + 1;
                    q.push({broken, {nx, ny}});
                }
            }
        }
    }
    return -1;
}

int main()
{
    // ios::usync_with_stdio(0);
    // cin.tie(0);

    cin >> N >> M;
    char x[M];
    for (int r = 0; r < N; r++){
        cin >> x;
        for (int c = 0; c < M; c++){
            matrix[r][c][0] = x[c]-'0';
        }
    }

    cout << BFS(N, M) << '\n';

    return 0;
}