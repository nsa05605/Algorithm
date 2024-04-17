#include <string>
#include <vector>

using namespace std;

// 재귀 함수를 통해 피보나치 수를 계산하는 함수
// 단순하게 작성하면 시간 초과가 발생함
// 그래서 계산한 결과를 저장하는 int Fibo[100001] 만들어주자
// 아래와 같이 작성했지만, 여전히 overflow가 발생함. 그 이유로 100000번째 피보나치 수는 자릿수가 20000이 넘어감
// 그래서 나머지 연산의 특성을 고려해서 작성해야 할 듯

int Fibo[100001];
bool visited[100001] = {false};

int F(int n){
    if (visited[n] == true) { return Fibo[n]; }
    if (n > 1) {
        visited[n] = true;
        Fibo[n] = (F(n-2) + F(n-1)) % 1234567;
        return Fibo[n];
    }
    else if (n <= 1){
        return n;
    }
}

int solution(int n)
{
    int fibo = F(n);
    return fibo % 1234567;
}