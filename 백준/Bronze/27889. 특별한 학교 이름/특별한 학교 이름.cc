#define MIN 1
#define MAX 1000000
#define LEN 5000000

#include<bits/stdc++.h>

using namespace std;

string s;
string res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    switch(s[0]){
        case 'N':
            res = "North London Collegiate School";
            break;
        case 'B':
            res = "Branksome Hall Asia";
            break;
        case 'K':
            res = "Korea International School";
            break;
        case 'S':
            res = "St. Johnsbury Academy";
            break;
    }

    cout << res;
    return 0;
}
 