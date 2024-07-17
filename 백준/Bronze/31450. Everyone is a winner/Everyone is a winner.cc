#define MIN 1
#define MAX 1000000
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

int M, K;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> K;
    if(M%K == 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}
 