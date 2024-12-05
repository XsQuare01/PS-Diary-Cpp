#include <bits/stdc++.h>
#define MAX 1000
#define INF 2100000000
#define MOD 998244353

using namespace std;

int N;
int arr[MAX];
int cnt[MAX+1];
int sum = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
        sum += arr[i];
    }

    int maximum = -1;
    int max_num = -1;
    for(int i = 1; i <= N; i++){
        if(i * cnt[i] > maximum * max_num){
            maximum = cnt[i];
            max_num = i;
        }
    }
    sum += (max_num * maximum);

    sort(arr, arr + N);

    cout << sum << "\n";
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
