#define MAX 9

#include<bits/stdc++.h>

using namespace std;

int n;
int darr[][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        string s;
        cin >> s;
        if(s == "end"){
            break;
        }

        int count_x = 0; int count_o = 0;
        bool line_x = false; bool line_o = false;

        for(int j = 0; j < MAX; j++){
            if(s[j] == 'X'){
                count_x++;
            }

            if(s[j] == 'O'){
                count_o++;
            }

        }

        for(auto [dx, dy, dz]: darr){
            if(s[dx] == s[dy] && s[dy] == s[dz] && s[dx] == 'X'){
                line_x = true;
            }

            if(s[dx] == s[dy] && s[dy] == s[dz] && s[dx] == 'O'){
                line_o = true;
            }
        }

        if(count_x == 5 && count_o == 4 && !line_o){
            cout << "valid" << "\n";
            continue;
        }

        if(count_x == count_o + 1 && !line_o && line_x){
            cout << "valid" << "\n";
            continue;
        }

        if(count_x == count_o && line_o){
            cout << "valid" << "\n";
            continue;
        }

        cout << "invalid" << "\n";
        continue;
    }

    return 0;
}