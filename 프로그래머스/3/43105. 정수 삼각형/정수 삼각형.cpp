/// 프로그래머스 - 정수 삼각형

// 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 리턴
// 아래칸으로 이동할 때는 대각선 방향만 가능
// 삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최대값을 리턴하는 함수

// 삼각형의 높이는 1 이상 500 이하.
// 삼각형을 이루고 있는 숫자는 0 이상 9999 이하

// 그냥 DFS로 경로 탐색을 해도 될 것 같은데, 중간 경로의 값을 저장하고 동적 프로그래밍으로 수행하면 더 효율적일 것이라 생각됨
// DFS로 탐색하기 위해서는 간선 정보를 알아야 하는데,
// 최상단 노드는 idx=0 이고, 다음 층의 idx=0,1 로 갈 수 있음
// 즉, 현재 층에서 idx=n 이면, 다음 층의 n, n+1 노드와 연결됨
// DFS를 할 때, 최상단에서 출발해서 최하단까지 가는 매 순간의 값을 저장해두고, 이를 이용해서 조금씩 경로가 바뀌는 순간에 대처하도록 구성해야 할 듯
// 그리고 DFS를 할 때, visited 를 사용해서 방문한 노드를 재방문하지 않도록 하는데, 재방문이 필요한 순간도 존재함

// 트리 구조로 생각해서 다루면 될 것 같고, 전위 순회(Pre-Order Traverse)로 다루면서 각 경로의 값을 저장하면 될 것 같음

#include <bits/stdc++.h>
using namespace std;

// // 아래 코드는 재귀적으로 트리 탐색을 시도했는데, 시간 초과가 발생함
// int calculate(vector<vector<int>> &triangle, int &maxSum, int &curRow, int &curCol){
//     if(curRow >= triangle.size()){return 0;}    // 트리의 마지막(leaf node)까지 탐색 완료

//     int nextRow = curRow+1, nextCol = curCol+1;
//     int leftSum = calculate(triangle, maxSum, nextRow, curCol);
//     int rightSum = calculate(triangle, maxSum, nextRow, nextCol);

//     int currSum = triangle[curRow][curCol] + max(leftSum, rightSum);

//     maxSum = max(maxSum, currSum);
    
//     return currSum;
// }

// int calculateSum(vector<vector<int>> &triangle){
//     int maxSum = 0;
//     int initRow = 0, initCol = 0;
//     calculate(triangle, maxSum, initRow, initCol);
//     return maxSum;
// }

// 재귀를 이용한 풀이
int calculateSum(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp[n-1][i] = triangle[n-1][i];
    }

    for (int row = n - 2; row >= 0; --row) {
        for (int col = 0; col <= row; ++col) {
            dp[row][col] = triangle[row][col] + max(dp[row+1][col], dp[row+1][col+1]);
        }
    }

    return dp[0][0];
}

int solution(vector<vector<int>> triangle){
    int answer = 0;
    answer = calculateSum(triangle);
    return answer;
}