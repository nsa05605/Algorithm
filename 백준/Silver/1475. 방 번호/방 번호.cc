#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string room_number;
    cin >> room_number;

    int sets[10] = {0};       // 필요한 번호 개수 담을 배열
    for (int i = 0; i < room_number.length(); i++){
        sets[int(room_number[i])-'0']++;
    }
    
    sets[6] += sets[9]; sets[9] = 0;
    if (sets[6]%2 != 0){sets[6] = sets[6]/2 + 1;}
    else {sets[6] /= 2;}
    
    int max = 0;
    for (int i = 0; i < 10; i++){
        if (sets[i] > max) {max=sets[i];}
    }
    cout << max << '\n';
    return 0;
}