#define MIN 1
#define MAX 100000
#define LEN 5000000
#define INF LONG_LONG_MAX

#include<bits/stdc++.h>

using namespace std;

int N;
string str2;

void recursive(string& str, int st, int ed, int cnt, bool flag){
    if(cnt > N){
        return ;
    }

    if(flag){
        for(int i = st; i < ed; i++){
            str[i] = ' ';
        }
    }
    else{
        int gap = (ed - st)/3;
        int le = st + gap;
        int ri = le + gap;

        recursive(str, st, le, cnt+1, false);
        recursive(str, le, ri, cnt+1, true);
        recursive(str, ri, ed, cnt+1, false);
    }

    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(cin >> N){
        string str(pow(3, N), '-');
        recursive(str, 0, pow(3, N), 0, false);

        cout << str << "\n";
    }
	return 0;
}