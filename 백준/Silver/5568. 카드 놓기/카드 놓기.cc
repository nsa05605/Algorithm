#include <bits/stdc++.h>
using namespace std;

unordered_set<string> result;
vector<int> result_vec;
bool visited[10] = {false};

void permutation(vector<int> &cards, int k, int n)
{
    int answer = 0;
    if (result_vec.size() == k){
        string s = "";
        for (int i = 0; i < result_vec.size(); i++){
            s += to_string(result_vec[i]);
        }
        result.insert(s);
        return;
    }
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        visited[i] = true;
        result_vec.push_back(cards[i]);
        permutation(cards, k, n);
        result_vec.pop_back();
        visited[i] = false;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> cards(n);
    for (int i=0; i<n; i++){
        cin >> cards[i];
    }

    permutation(cards, k, n);

    cout << result.size() << '\n';

    return 0;
}