#define MIN 1
#define MAX 300
#define LEN 5000000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    if(N >= 90){
        cout << "A";
    }
    else if(N >= 80){
        cout << "B";
    }
    else if(N >= 70){
        cout << "C";
    }
    else if(N >= 60){
        cout << "D";
    }
    else{
        cout << "F";
    }
    


	return 0;
}