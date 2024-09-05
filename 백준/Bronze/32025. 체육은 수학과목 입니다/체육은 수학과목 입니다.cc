#define MIN 1
#define MAX 1000000
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int A, B;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B;
    if(A >= B){
        cout << B * 50;
    }
    else{
        cout << A * 50;
    }

    return 0;
}
 