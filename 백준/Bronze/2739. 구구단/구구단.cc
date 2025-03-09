#define MIN 1
#define MAX 1000001
#define LEN 5000000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= 9; i++){
        cout << N << " * " << i << " = " << N * i << "\n";
    }


	return 0;
}