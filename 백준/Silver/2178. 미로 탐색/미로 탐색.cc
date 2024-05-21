// 백준 - 2178번 미로 탐색

// N x M 크기의 배열로 표현되는 미로
// 1은 이동할 수 있는 칸을 의미하고, 0은 이동할 수 없는 칸을 의미함
// (1,1)에서 출발하여 (N,M)까지 가는 최단 거리를 출력하는 문제

// 입력
// 첫째 줄에 두 정수 N, M (2 <= N, M <= 100)이 주어지고,
// 다음 N개의 줄에는 M개의 정수가 주어진다.

// 출력
// 지나야 하는 최소의 칸 수를 출력한다.

// 구현 방법
// 우선 (1,1)에서부터 탐색을 시작하도록 하는 코드 작성
// BFS로 전체 탐색을 하며 지나가다가 (N,M) 노드 발견하면 탐색 종료
// DFS로 구현하지 않는 이유는, 최단 경로를 찾아야 하므로 BFS의 계산 비용이 더 적을 것으로 생각됨

#include <bits/stdc++.h>
using namespace std;

#define MAX 101

vector<vector<int>> matrix;
int dist[MAX][MAX];
bool visited[MAX][MAX] = {false};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int N, int M) {
    queue<pair<int, int>> Q;
    Q.push({0, 0});  // 시작 지점 넣어줌
    visited[0][0] = true;
    dist[0][0] = 1;  // 시작 지점의 거리 초기화

    while (!Q.empty()) {
        int cy = Q.front().first, cx = Q.front().second; Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;  // 범위를 벗어나면 넘기고
            if (visited[ny][nx] || matrix[ny][nx] != 1) continue;  // 이미 방문했거나 벽이면 넘기기
            dist[ny][nx] = dist[cy][cx] + 1;
            visited[ny][nx] = true;
            Q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    matrix.resize(N, vector<int>(M));

    for (int row = 0; row < N; row++) {
        string Row;
        cin >> Row;
        for (int col = 0; col < M; col++) {
            int value = Row[col] - '0';  // char를 int로 변환
            matrix[row][col] = value;
        }
    }

    BFS(N, M);

    cout << dist[N-1][M-1] << endl;

    return 0;
}