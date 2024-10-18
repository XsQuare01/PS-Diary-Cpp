#include <bits/stdc++.h>
using namespace std;
#define TEST int tt; cin >> tt; while (tt--)
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tii tuple<int, int, int>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
const int MAX = 200'005;
const int INF = 1e9 + 1;
const ll MOD = 1'000'003;

int num[50];
int sum[50][50];
int dp[40][40];


int main() {
    FASTIO
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> num[i];
    }
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j++)dp[i][j] = -INF;
    }
    vector<int> v;
    for(int i=0; i<N; i++){
        for(int j=1; j<=N; j++){
            if(j+i>N)break;
            sum[j][j+i] = sum[j][j+i-1] + num[j+i];
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j++){
            for(int a=i; a<=j; a++){
                for(int b=a; b<=j; b++){
                    dp[i][j] = max(dp[i][j], sum[a][b]);
                }
            }
        }
    }
    vector<int> a;
    vector<int> b;
    int cnt = 0;
    for(int i=1; i<=N; i++){
        a.emplace_back(i);
        if(cnt<M-1){
            b.emplace_back(1);
            cnt++;
        }
        else b.emplace_back(0);
    }
    int before;
    int ans = -INF;
    do {
        int sum =0;
        before = 1;
        for (int i = 0; i < a.size(); ++i) {
            if (b[i] == 1){
                sum += dp[before][a[i]];
                before = a[i]+1;
            }
        }
        if(before<=N){
            sum+=dp[before][N];
            ans = max(ans, sum);
        }
    } while (prev_permutation(b.begin(), b.end()));
    cout << ans;
}