#define MAX 1000000

#include<bits/stdc++.h>

using namespace std;

long long N, A, B;

bool GCD(long long a, long long b){
    if(a < b){
        swap(a, b);
    }
    if(b == 1){
        return true;
    }
    if(a % b == 0){
        return false;
    }
    return GCD(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> N >> A >> B;
    if(!GCD(A, B)){
        cout << "No";
        return 0;
    }
    cout << "Yes" << "\n";
    for(int i = 0; i < N; i++){
        cout << A + 2 * i * B << " " << A + (2 * i + 1) * B << "\n";
    }

    return 0;
}