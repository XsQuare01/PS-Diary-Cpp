#define MIN 1
#define MAX 1000000
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int a = N / 10;
    int b = N % 10;

    if(a == b){
        cout << 1;
    }
    else{
        cout << 0;
    }

    return 0;
}
 