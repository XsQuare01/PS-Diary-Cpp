#define MIN 1
#define MAX 1000000
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int A, X;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A;
    for(int i = 0; i < A / 5; i++){
        cout << "V";
    }
    for(int i = 0; i < A % 5; i++){
        cout << "I";
    }

    return 0;
}
 