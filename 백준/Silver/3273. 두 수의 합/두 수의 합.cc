#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, arr[100001];
    bool checked[2000001];

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;

    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (x-arr[i] > 0 && checked[x-arr[i]]) cnt++;
        checked[arr[i]] = true;
    }

    cout << cnt << '\n';

    return 0;
}