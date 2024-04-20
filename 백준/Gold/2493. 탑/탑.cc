#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> heights(N);
    vector<int> result(N);

    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    stack<pair<int, int>> s;  // pair<탑의 높이, 탑의 인덱스>

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && s.top().first < heights[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = 0;  // 수신 가능한 탑이 없음
        } else {
            result[i] = s.top().second + 1;  // 0이 아닌 1부터 시작
        }

        s.push({heights[i], i});
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }

    cout << '\n';

    return 0;
}