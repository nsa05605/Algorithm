// 문제 정의
// N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 좋다고 한다.
// N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라
// 수의 위치가 다르면 값이 같아도 다른 수이다.

// 입력
// 첫째 줄에는 수의 개수 N (1 <= N <= 2000)
// 둘째 줄에는 i번째 수를 나타내는 A_i가 N개 주어진다. (|A_i| <= 1,000,000,000)

// 문제 풀이
// 투 포인터로 문제 풀이를 하면 될 것 같은데, 수의 범위가 10억이므로 시간 제한을 생각해야함
// DP 방법을 사용해야 하나? 생각해보자


#include <bits/stdc++.h>
using namespace std;

#define MAX 2001

int N;
vector<int> Nums;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int input;
    for (int i = 0; i < N; i++){
        cin >> input; Nums.push_back(input);
    }
    sort(Nums.begin(), Nums.end());

    int start = 0, end = 1;
    int cnt = 0, answer = 0;
    for (int k = 0; k < N; k++)
    {
        long long find = Nums[k];
        int i = 0;
        int j = N - 1;
        
        while(i < j){
            if (Nums[i] + Nums[j] == find){
                if (i != k && j != k){
                    answer++; break;
                }
                else if (i == k){
                    i++;
                }
                else if (j == k){
                    j--;
                }
            }
            else if (Nums[i] + Nums[j] < find){
                i++;
            }
            else {
                j--;
            }
        }
    }
    
    cout << answer << '\n';

    return 0;
}