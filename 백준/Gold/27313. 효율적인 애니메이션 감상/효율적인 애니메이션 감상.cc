#define MAX 1000000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M, K;
int arr[MAX];
int res = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> list;

    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        if (t <= M)
            list.push_back(t);
    }

    sort(list.begin(), list.end());

    if (list.empty()) {
        cout << "0\n";
    } else {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(list[0]);
        int answer = 1;

        for (size_t i = 1; i < list.size(); i++) {
            if (pq.size() == K) {
                if (pq.top() + list[i] > M)
                    break;
                else {
                    pq.push(pq.top() + list[i]);
                    pq.pop();
                }
            } else {
                pq.push(list[i]);
            }
            answer++;
        }

        cout << answer << "\n";
    }

    return 0;
}