#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> &dist, vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int d = dist[curr];
        for (int i=0; i<graph[curr].size(); i++){
            int next = graph[curr][i];
            if (dist[next] != -1) continue; // 이미 방문한 경우
            dist[next] = d+1;
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    int from, to;
    vector<vector<int>> graph(n+1); // 전체 그래프 수는 n개(n+1로 초기화 해야 함)
    vector<int> dist(n+1, -1);      // 각 노드까지의 거리는 -1로 초기화
    for(int i=0; i<edge.size(); i++){   // edge 정보를 사용해서 양방향 그래프 생성. 이를 연결 리스트 그래프 라고 부름
        from = edge[i][0];
        to = edge[i][1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    BFS(dist, graph);

    sort(dist.begin(), dist.end(), greater<int>());

    int pos = 0;
    while(dist[pos++] == dist[0]) answer++;

    return answer;
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = {{3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2}};
    cout << solution(n, edge) << '\n';

    return 0;
}