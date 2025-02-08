#define MIN 1
#define MAX 300
#define LEN 5000000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

string s1, s2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int a = stoi(s1);
    int b = stoi(s2);
    if(a > b){
        cout << a;
    }
    else{
        cout << b;
    }

    


	return 0;
}