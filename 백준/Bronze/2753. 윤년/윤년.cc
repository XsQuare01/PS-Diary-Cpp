#define MIN 1
#define MAX 26
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int A;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A;
    if((!(A%4) && (A%100)) || !(A%400)){
        cout << 1;
        return 0;
    }
    cout << 0;

    return 0;
}
 