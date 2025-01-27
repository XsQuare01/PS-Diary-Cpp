#define MIN 1
#define MAX 300
#define LEN 5000000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, W, H, L;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> W >> H >> L;
    int res = min((W / L) * (H / L), N);
    cout << res;


	return 0;
}