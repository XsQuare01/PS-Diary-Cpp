#define MAX 100000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int N;
int last = -1;
int first = INF;
int res = 0;
pair<int, int> arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        int s, e;
        cin >> s >> e;
        last = max(s, last);
        first = min(e, first);
    }
    res = last <= first ? 0 : last - first;
    cout << res;
    return 0;
}