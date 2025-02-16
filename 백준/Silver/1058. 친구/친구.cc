// 1058 친구
// 연결된 친구의 수를 출력하는 프로그램
// 각 노드에 대해 BFS를 깊이 2만큼 해서 visited의 수를 계산하면 해결?
// 각 노드를 시작 노드로 하는 BFS를 구현하도록 하고, 현재 깊이가 2인지 확인이 필요함

#include <iostream>
#include <queue>
#include <string.h>

#define MAX 50

int g_N;
int g_MaxFriends = 0;
char g_RelationShip[MAX][MAX] = {'N'};
bool g_visited[MAX] = {false};

void BFS(int v) {
    memset(g_visited, 0, sizeof(g_visited));
    
    std::queue<std::pair<int, int>> q;

    q.push({v, 0});
    g_visited[v] = true;

    int friends = 0;
    while(!q.empty()) {
        int now_v = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (depth > 1) continue;

        for (int i = 0; i < g_N; i++) {
            if (g_RelationShip[now_v][i] == 'Y' && g_visited[i] == false) {
                g_visited[i] = true;
                friends++;
                q.push({i, depth+1});
            }
        }
    }
    if (friends > g_MaxFriends) g_MaxFriends = friends;
}

int main(int argc, char* argv[]) {
    std::cin >> g_N;
    for (int i = 0; i < g_N; i++) {
        for (int j = 0; j < g_N; j++) {
            std::cin >> g_RelationShip[i][j];
        }
    }

    for (int i = 0; i < g_N; i++) {
        BFS(i);
    }

    std::cout << g_MaxFriends << std::endl;

    return 0;
}