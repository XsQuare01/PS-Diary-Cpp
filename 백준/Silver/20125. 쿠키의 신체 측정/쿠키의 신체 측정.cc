#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n;
char arr[MAX][MAX];
pair<int, int> heart;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            arr[i][j] = s[j];
        }
    }

    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == '*'){
                heart = {i+1, j};
                cout << i + 2 << " " << j + 1 << "\n";
                flag = true;
                break;
            }
        }

        if(flag){
            break;
        }
    }


    int left = 0;
    for(int i = heart.second - 1; i >= 0; i--){
        if(arr[heart.first][i] != '*'){
            break;
        }
        left++;
    }
    cout << left << " ";

    int right = 0;
    for(int i = heart.second + 1; i < n; i++){
        if(arr[heart.first][i] != '*'){
            break;
        }
        right++;
    }
    cout << right << " ";

    pair<int, int> waist;
    int height = 0;
    for(int i = heart.first + 1; i < n; i++){
        if(arr[i][heart.second] != '*'){
            break;
        }
        height++;
    }
    waist = {heart.first + height, heart.second};
    cout << height << " ";

    int lleg = 0;
    for(int i = waist.first + 1; i < n; i++){
        if(arr[i][waist.second - 1] != '*'){
            break;
        }
        lleg++;
    }
    cout << lleg << " ";

    int rleg = 0;
    for(int i = waist.first + 1; i < n; i++){
        if(arr[i][waist.second + 1] != '*'){
            break;
        }
        rleg++;
    }
    cout << rleg;
    return 0;
}