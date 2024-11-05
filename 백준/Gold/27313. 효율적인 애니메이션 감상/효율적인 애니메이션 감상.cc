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

    vector<int> list; // M 이하의 애니메이션을 저장할 리스트

    // 애니메이션 시간 입력 및 M 이하의 시간만 저장
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        if (t <= M)
            list.push_back(t);
    }

    // 오름차순 정렬
    sort(list.begin(), list.end());

    if (list.empty()) {
        cout << "0\n"; // 애니메이션이 존재하지 않을 때
    } else {
        // 우선순위 큐 (최소 힙)로 현재 시청 중인 애니메이션 저장
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(list[0]); // 첫 번째 애니메이션 추가
        int answer = 1;

        // 2번째 애니메이션부터 시청 시작
        for (size_t i = 1; i < list.size(); i++) {
            if (pq.size() == K) { // 우선순위 큐 크기 == K
                if (pq.top() + list[i] > M) // M을 초과하면 시청 불가
                    break;
                else {
                    pq.push(pq.top() + list[i]); // M 이하이면 시청
                    pq.pop();
                }
            } else { // 우선순위 큐 크기 < K
                pq.push(list[i]); // 애니메이션 시청
            }
            answer++;
        }

        cout << answer << "\n"; // 시청한 애니메이션 출력
    }

    return 0;
}