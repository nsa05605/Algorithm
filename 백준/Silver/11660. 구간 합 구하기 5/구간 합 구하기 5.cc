// N x N 개의 수가 N x N 크기의 표에 채워져있다.
// (X1, Y1)에서 (X2, Y2)까지의 합을 구하려한다.
// 예를 들어, (2,2)에서 (3,4)까지의 합을 구하면 (2,2), (2,3), (2,4), (3,2), (3,3), (3,4) 의 합을 계산하면 됨

// 입력
// 첫 줄에 표의 크기 N과 합을 구해야하는 횟수 M이 주어진다. (1 <= N <= 1024, 1 <= M <= 100000)
// 둘째 줄부터 N개의 줄에는 표에 채워진 수가 주어진다.

// 문제 풀이
// 먼저 행렬을 구성해놓고,
// 그냥 이중 for문으로 구성해서 계산하면 될 것 같음
// 너무 단순하게 생각했더니, 시간초과가 발생함
// 다이나믹 프로그래밍 방법으로 생각해서, 미리 구간의 합을 계산해두자
// 예를 들어서 (1,1)부터 (x1,y1)까지의 구간합을 미리 계산한 후에 (x1,y1)~(x2,y2)까지의 구간합을 출력하라하면,
// D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1]

#include <bits/stdc++.h>
using namespace std;

#define MAX 1025

int matrix[MAX][MAX];
int DP[MAX][MAX];
int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int r = 1; r <= N; r++){
        for (int c = 1; c <= N; c++){
            cin >> matrix[r][c];
            DP[r][c] = DP[r][c-1] + DP[r-1][c] - DP[r-1][c-1] + matrix[r][c];
        }
    }

    int x1, y1, x2, y2;
    for (int cnt = 0; cnt < M; cnt++){
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = DP[x2][y2] - DP[x1-1][y2] - DP[x2][y1-1] + DP[x1-1][y1-1];
        cout << sum << '\n';
    }

    return 0;
}