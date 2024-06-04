#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1001

vector<int> graph[MAX];		// 각 node에 연결된 node를 넣는 vector의 array
vector<bool> visited_DFS(MAX, false);		// 방문 여부를 기록하는 vector
vector<bool> visited_BFS(MAX, false);		// 방문 여부를 기록하는 vector

void DFS(int start) {
	visited_DFS[start] = true;		// 시작 node에 방문 표식
	cout << start << " ";
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited_DFS[next]) {
			DFS(next);
		}
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited_BFS[start] = true;
	
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		cout << vertex << " ";
		for (int i = 0; i < graph[vertex].size(); i++) {
			int next = graph[vertex][i];
			if (!visited_BFS[next]) {
				q.push(next);
				visited_BFS[next] = true;
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;
	
	graph->resize(N+1);			// 0번 node는 사용하지 않기 때문에 N+1개로 resize

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);	// node a와 node b의 연결을 나타냄
		graph[b].push_back(a);
	}

	for (int i = 0; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(V);
	cout << endl;
	BFS(V);

	return 0;
}