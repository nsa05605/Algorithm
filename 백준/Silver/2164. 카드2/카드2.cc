#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    deque<int> dq;
    for (int i = N; i > 0; i--){dq.push_back(i);}

    while(dq.size() > 1)
    {
        dq.pop_back();
        dq.push_front(dq.back());
        dq.pop_back();
    }
    cout << dq.back() << endl;

    return 0;
}