#define MIN 1
#define MAX 100000
#define LEN 5000000
#define INF LONG_LONG_MAX

#include<bits/stdc++.h>

using namespace std;

int N;
vector<bool> vec;

void recursive(int st, int ed, int cnt, bool flag){
    if(cnt > N){
        return ;
    }

    if(flag){
        for(int i = st; i < ed; i++){
            vec[i] = true;
        }
    }
    else{
        int gap = (ed - st)/3;
        int le = st + gap;
        int ri = le + gap;

        recursive(st, le, cnt+1, false);
        recursive(le, ri, cnt+1, true);
        recursive(ri, ed, cnt+1, false);
    }

    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(cin >> N){
        vec = vector<bool>();
        vec.resize(pow(3, N));

        recursive(0, pow(3, N), 0, false);

        for(int i = 0; i < pow(3, N); i++){
            if(!vec[i]){
                cout << "-";
            }
            else{
                cout << " ";
            }
        }
        cout << "\n";
    }
	return 0;
}