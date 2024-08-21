#define MIN 1
#define MAX 1000000
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

string S;
string res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    if(S == "SONGDO"){
        res = "HIGHSCHOOL";
    }
    else if(S == "CODE"){
        res = "MASTER";
    }
    else if(S == "2023"){
        res = "0611";
    }
    else{
        res = "CONTEST";
    }
    cout << res;

    return 0;
}
 