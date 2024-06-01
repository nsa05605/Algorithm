// 문제 정의
// 카펫의 중앙은 노란색으로 칠해져있고, 테두리 1줄은 갈색으로 칠해짐
// 갈색 격자의 수와 노란색 격자의 수가 주어질 때, 가로 세로 크기를 출력

// 제한 사항
// 8 <= brown <= 5000, 1 <= yellow <= 2000000
// 카펫의 가로는 세로보다 같거나 길다

// 문제 풀이
// 우선 yellow로 만들 수 있는 직사각형의 형태를 먼저 검사하고
// 이것을 기반으로 brown에도 적합한지 검사해서 출력하면 될 듯?
// yellow-brown 관계는
// brown = 2*(W_yellow+2) + 2*H_yellow

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow){
    vector<int> answer;

    for (int width = 1; width <= yellow; width++){
        if(yellow % width == 0 && yellow / width <= width){
            int height = yellow / width;
            if (2*(width+2)+2*height == brown){answer.push_back(width+2); answer.push_back(height+2); return answer;}
        }
    }
}