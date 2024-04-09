#include <string>
#include <vector>

using namespace std;

// 시간 초과
// long long solution(long long n){
//     long long answer = 0;
//     for (int i = 0; i < n; i++){
//         if (n == i*i){return (i+1)*(i+1);}
//     }
//     return -1;
// }

#include <cmath>
long long solution(long long n)
{
    long long answer = 0;
    long long a = sqrt(n);
    if (a*a == n){
        answer = pow((a+1), 2);
    } else{
        answer = -1;
    }

    return answer;
}