#define MIN 1
#define MAX 26
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int N, X;
int current;
char ret[LEN + 1];
int arr[LEN + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    current = N;
    if(X < N * MIN || X > N * MAX){
        cout << '!';
        return 0;
    }
    for(int i = 1; i <= N; i++){
        ret[i] = 'A';
        arr[i] = MIN;
    }
    for(int i = N; i > 0; i--){
        int gap = X - current;
        if(gap < MAX){
            ret[i] += gap;
            break;
        }
        if(gap >= MAX){
            arr[i] = MAX;
            ret[i] = 'Z';
            current += (MAX - MIN);
        }
    }

    for(int i = 1; i <= N; i++){
        cout << ret[i];
    }

    return 0;
}
 