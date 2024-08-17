#define MIN 1
#define MAX 1000000
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int W, H;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> W >> H;
    float res = 10.0 * W * H / 2;
    cout << (int)(res / 10) << "." << ((int)res % 10);

    return 0;
}
 