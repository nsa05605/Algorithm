// 행성계 간의 이동을 최대한 피해서 이동하는 루트 계산
// 은하수 지도, 출발점, 도착점이 주어졌을 때 필요한 행성계 진입/이탈 횟수 계산

// 입력의 첫 줄에는 테스트 케이스
// 그 다음 줄부터 (출발점(x1, y1), 도착점(x2, y2)), (행성계의 개수 n), (행성계의 중점과 반지름(cx, cy, r) x n)

// 풀이
// 시작점과 도착점을 포함하는 원의 개수를 세면 될 것 같음.
// 다만 하나의 원에 포함된다면 계산에서 제외해도 됨

#include <iostream>
#include <cmath>

#define MAX 1001

int main()
{
    int test_num;
    int x1, y1, x2, y2, n, cx, cy, r;

    std::cin >> test_num;
    for (int i = 0; i < test_num; i++) {
        int count = 0;
        std::cin >> x1 >> y1 >> x2 >> y2 >> n;
        for (int j = 0; j < n; j++) {
            bool in_circle_start=false, in_circle_end=false;
            std::cin >> cx >> cy >> r;
            if ((pow(abs(x1-cx), 2) + pow(abs(y1-cy), 2)) <= pow(r, 2)) in_circle_start = true;
            if ((pow(abs(x2-cx), 2) + pow(abs(y2-cy), 2)) <= pow(r, 2)) in_circle_end = true;
            if ((!in_circle_start && in_circle_end) || (in_circle_start && !in_circle_end)) count++; 
        }
        std::cout << count << std::endl;
    }
    return 0;
}