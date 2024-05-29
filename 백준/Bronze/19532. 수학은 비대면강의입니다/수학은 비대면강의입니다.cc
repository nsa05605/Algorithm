// 문제 정의
// 연립 방정식에서 x와 y의 값을 계산하시오
// ax + by = c
// dx + ey = f

// 입력
// 정수 a,b,c,d,e,f 가 공백으로 구분되어 차례로 주어진다. (-999 <= v <= 999)
// 문제에서 언급한 방정식을 만족하는 (x,y)가 유일하게 존재하고, 이때 x와 y는 각각 -999 ~ 999 사이의 정수임

// 문제 풀이
// a,b,c를 알고 있기 때문에, ax+by=c 를 만족하는 (x,y) 쌍을 찾고
// 이를 dx+ey=f 식에 넣어서 맞는 정답을 찾으면 될 것 같음

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    vector<pair<int,int>> xy;

    for (int x = -999; x <= 999; x++){
        for (int y = -999; y <= 999; y++){
            if (a*x + b*y == c){xy.push_back(make_pair(x,y));}
        }
    }

    for (int i = 0; i < xy.size(); i++){
        int x = xy[i].first, y = xy[i].second;
        if (d*x + e*y == f){cout << x << " " << y << '\n'; return 0;}
    }
    return 0;
}