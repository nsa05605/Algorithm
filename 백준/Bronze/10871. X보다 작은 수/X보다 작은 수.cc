#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, num;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> num;
        if (num < x) {cout << num << '\n';}
    }
    return 0;
}