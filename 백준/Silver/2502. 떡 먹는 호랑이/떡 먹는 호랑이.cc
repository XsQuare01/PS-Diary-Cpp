#define MAX 30
#define INF 100000

#include<bits/stdc++.h>

using namespace std;

int D, K, F1, F2;
int farr[MAX + 1] = 
{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55,
89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 
10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};

int A, B = 0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> D >> K;
    F1 = farr[D-1];
    F2 = farr[D-2];

    for(int i = 1; i <= INF; i++){
        int t1 = F1 * i;
        if(t1 > K){
            break;
        }
        int t2 = (K - t1) / F2;
        if((t1 + t2 * F2) == K && i > t2){
            cout << t2 << "\n" << i;
            return 0;
        }
    }

    return 0;
}