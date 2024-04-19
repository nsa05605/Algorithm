#include <bits/stdc++.h>
using namespace std;

// N개의 최소공배수
// 두 수의 최소공배수란 입력된 두 수의 배수 중 공통이 되는 가장 작은 수를 의미함.
// n개의 수가 담긴 arr가 입력되었을 때 최소공배수를 반환하는 함수를 작성하라


// 혼자 풀고 기존 풀이 참고해서 작성 //
// GCD, LCM 사용한 풀이
// Greatest Common Divisor(GCD), Lowest Common Multiple(LCM)는 유클리드 호재법에 의해 간단히 구현 가능함
int GCD(int a, int b)
{
    while (b != 0){
        int c = a % b;

        a = b;
        b = c;
    }
    return a;
}

// 두 수의 곱(a*b)은 두 수의 최대공약수(GCD)와 최소공배수(LCM)의 곱과 같다는 성질을 이용
int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int solution(vector<int> arr){
    int curr = 1;
    for (int i = 0; i < arr.size(); i++){
        curr = LCM(arr[i], curr);
    }
    return curr;
}

// 기존 풀이
// 최소공배수를 구하는 방법은 각 수를 소수 단위로 구성하고, 해당 소수가 사용된 최대 개수만큼씩 곱해주면 됨
// 예시로 [2, 6, 8, 14]는 [2, 2x3, 2^3, 2x7]이므로 2^3 x 3 x 7 이 최소공배수임.
// 그럼 이제 각 숫자를 이루고 있는 수를 어떻게 알 수 있는지 생각해봐야 함
// 단순하게 for, while 돌면서 계산할 수 있지만, 그러면 시간이 오래 걸릴 수도
// 소수만 담고 있는 arr를 만들어서 해당 수들만 사용하는 방법도 존재함. 이게 그나마 덜 걸릴 듯

vector<int> vPrime;
bool aPrime[101];

int solution2(vector<int> arr){
    int answer = 1;

    // calculate primes
    aPrime[0] = aPrime[1] = true;
    for (int i=2; i<=100; i++){
        if (aPrime[i]) continue;   // 소수가 아니면 continue
        vPrime.push_back(i);    // 소수이면 리스트에 넣음
        for (int j=i*2; j<=100; j += i) aPrime[j] = true;
    }


    // 각 수를 구성하고 있는 소수의 수 계산
    int num[101];
    fill_n(num, 101, 0);

    for (int prime = 0; prime < vPrime.size(); prime++){
        for (int i = 0; i < arr.size(); i++){
            if (vPrime[prime] <= arr[i]){   // 주어진 수가 소수보다 큰 경우만 검사
                int cnt = 0;    // 해당 소수가 몇 번 나왔는지 검사
                int curr = arr[i];
                while(curr % vPrime[prime] == 0){cnt++; curr /= vPrime[prime];}  // 이전 수보다 더 많이 나눠졌으면 ++
                if(num[prime] < cnt) {num[prime] = cnt;}
            }
        }
    }


    for (int i=0; i<vPrime.size(); i++){
        answer *= pow(vPrime[i],num[i]);
    }

    return answer;
}