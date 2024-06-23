#define MAX 50
#define LEN 50

#include<bits/stdc++.h>

using namespace std;

int R, N;
int score = 0, b_score = 0;
string s_str;
string f_str[MAX];
int carr[MAX][3];

int RSP(char c1, char c2){
    if(c1 == c2){
        return 1;
    }
    if(c1 == 'S' && c2 == 'P'){
        return 2;
    }
    if(c1 == 'R' && c2 == 'S'){
        return 2;
    }
    if(c1 == 'P' && c2 == 'R'){
        return 2;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> s_str >> N;
    for(int i = 0; i < N; i++){
        cin >> f_str[i];
    }
    for(int i = 0; i < R; i++){
        char s_char = s_str[i];
        for(int j = 0; j < N; j++){
            char f_char = f_str[j][i];
            switch(f_char){
                case 'R':
                    carr[i][0]++;
                    break;
                case 'S':
                    carr[i][1]++;
                    break;
                case 'P':
                    carr[i][2]++;
                    break;
            }
            score += RSP(s_char, f_char);
        }
        int t_sum = max(carr[i][0]*2 + carr[i][2], max(carr[i][1]*2 + carr[i][0], carr[i][2]*2 + carr[i][1]));
        b_score += t_sum;
    }

    cout << score << "\n" << b_score;
    return 0;
}
 