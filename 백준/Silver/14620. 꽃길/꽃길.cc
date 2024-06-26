// 문제 정의
// 꽃을 심으면 정확히 1년 후에 꽃이 핌
// 다른 꽃의 잎(혹은 꽃술)이 두 꽃 모두 죽어버린다.
// 진아가 총 3개의 꽃을 피우기 위한 가장 적은 비용을 계산하라

// 입력 & 출력
// 첫 줄에 한 변의 길이 N (6 <= N <= 10)
// 이후 N개의 줄에 N개씩 화단의 지점당 가격 (0 <= G <= 200)이 주어진다.
// 출력으로는 꽃을 심기 위한 최소 비용을 출력

// 문제 풀이
// 인접 행렬 형태로 탐색을 하는 문제
// 총 N개가 주어지면 가로, 세로로 1~(N-1)까지 중 3개의 점을 선정해야하고,
// 이때 3개의 점 자신과 상하좌우를 더한 값이 최소인 점으로 3개를 선정해야 함
// 5개의 합이 가장 작은 지점부터 찾아서 고정시키고 나머지를 찾아가면 될 것 같지만, 이러면 겹쳐서 최소를 찾지 못하는 경우가 생길 수 있음
// 5개의 합이 가장 작은 지점을 순서대로 vector 등에 모두 넣어놓고,
// 앞에서부터 조건 맞춰서 계산해보면 될 듯

#include <bits/stdc++.h>
using namespace std;

#define MAX 11

bool visited[MAX][MAX];
int price[MAX][MAX] = {0};
int N;
int minCost = INT_MAX;

// x, y 좌표에 해당하는 땅의 가격 계산
int getCost(int x, int y)
{
    int p = price[x][y];
    p += price[x-1][y] + price[x][y-1] + price[x+1][y] + price[x][y+1];
    return p;
}

// x, y 좌표가 범위를 벗어나지 않았는지 검사
bool is_valid(int x, int y)
{
    if (x >= 1 && x < N-1 && y >= 1 && y < N-1){return true;}
    else {return false;}
}

// 두 꽃의 영역이 겹치는지 검사
bool is_overlap(const vector<pair<int, int>>& flower1, const vector<pair<int, int>>& flower2) {
    for (const auto& pos1 : flower1) {
        for (const auto& pos2 : flower2) {
            if (pos1 == pos2) {
                return true;
            }
        }
    }
    return false;
}

vector<pair<int, int>> flower_positions(int x, int y) {
    vector<pair<int, int>> positions = {{x, y}, {x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
    return positions;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> price[i][j];
        }
    }

    // 가격과 그 위치(좌표)를 담을 벡터
    vector<pair<int, vector<pair<int, int>>>> flowers;
    
    // 아래에서는 이제 가격을 계산하고 해당하는 위치를 담아줌
    for (int i = 1; i < N-1; ++i) {
        for (int j = 1; j < N-1; ++j) {
            int cost = getCost(i, j);
            flowers.push_back({cost, flower_positions(i, j)});
        }
    }

    // 이를 가격을 기준으로 정렬
    sort(flowers.begin(), flowers.end());

    int num_flowers = flowers.size();

    // 현재 flowers 벡터는 가격이 낮은 순으로 정렬되어 있으므로,
    // flowers의 앞의 인덱스부터 불러와서 계산을 하다보면 최소값을 계산할 수 있음
    for (int i = 0; i < num_flowers; ++i) {
        for (int j = i + 1; j < num_flowers; ++j) {
            // 두 꽃의 영역이 겹치는지 검사
            if (is_overlap(flowers[i].second, flowers[j].second)) {
                continue;
            }
            // 새로운 영역 k에 대해서도 검사.
            for (int k = j + 1; k < num_flowers; ++k) {
                if (is_overlap(flowers[i].second, flowers[k].second) || 
                    is_overlap(flowers[j].second, flowers[k].second)) {
                    continue;
                }
                int cost = flowers[i].first + flowers[j].first + flowers[k].first;
                minCost = min(minCost, cost);
            }
        }
    }

    cout << minCost << endl;

    return 0;
}