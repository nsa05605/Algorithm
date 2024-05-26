/// 프로그래머스 - 네트워크

// 문제 정의
// 네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미함
// A-B, B-C 연결이 있으면, A-C 도 간접적으로 연결되어 정보를 교환할 수 있음
// 컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때,
// 네트워크의 개수를 return 하도록 solution 함수를 작성하시오

// 조건
// n은 1 이상 200 이하인 자연수
// 각 컴퓨터는 0부터 n-1 인 정수로 표현함
// i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면, computers[i][j]=1
// computers[i][i]는 항상 1

// 예시
// n = 3
// computers = {{1,1,0}, {1,1,0}, {0,0,1}}
// return = 2

// 풀이
// 우선 주어진 vector를 이용해서 탐색을 시작
// computers[0][0] 부터 시작하고, 값이 1인 곳으로 방문하면서 해당 노드에 visited=true 주고 DFS로 구현
// computers[0][n] 에 더 이상 방문할 노드가 없으면, visited=false 인 가장 작은 n으로 이동해서 새로운 탐색

#include <bits/stdc++.h>
using namespace std;

#define MAX 200
int visited[MAX] = {false};

void DFS(vector<vector<int>> &computers, int curr, int n){
    visited[curr] = true;

    for (int i = 0; i < n; i++){
        if (!visited[i] && computers[curr][i] == 1){
            DFS(computers, i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers){
    int answer = 0;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            DFS(computers, i, n);
            answer++;
        }
    }
    return answer;
}