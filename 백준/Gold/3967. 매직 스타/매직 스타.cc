#define MAX 12
#define MOD 1000000007
#define INF 22

#include<bits/stdc++.h>

using namespace std;
int arr[MAX];
int darr[][4] = {
    {0, 2, 5, 7},
    {0, 3, 6, 10},
    {1, 2, 3, 4},
    {1, 5, 8, 11},
    {4, 6, 9, 11},
    {7, 8, 9, 10}
};
vector<int> sorted;
vector<int> permutation;

void fillArray(char c, int idx){
    if(c == 'x'){
        arr[idx] = -1;
    }
    else{
        arr[idx] = c - 'A';
        sorted.push_back(arr[idx]);
    }
}

void input(){
    string str;
    cin >> str;
    fillArray(str[4], 0);

    cin >> str;
    fillArray(str[1], 1);
    fillArray(str[3], 2);
    fillArray(str[5], 3);
    fillArray(str[7], 4);

    cin >> str;
    fillArray(str[2], 5);
    fillArray(str[6], 6);

    cin >> str;
    fillArray(str[1], 7);
    fillArray(str[3], 8);
    fillArray(str[5], 9);
    fillArray(str[7], 10);

    cin >> str;
    fillArray(str[4], 11);
}

void output(int tarr[MAX]){
    cout << "...." << char(tarr[0] + 'A') << "....\n";
    cout << "." << char(tarr[1] + 'A') << "." << char(tarr[2] + 'A') << "." << char(tarr[3] + 'A') << "." << char(tarr[4] + 'A') << ".\n";
    cout << ".." << char(tarr[5] + 'A') << "..." <<char(tarr[6] + 'A') << "..\n";
    cout << "." << char(tarr[7] + 'A') << "." << char(tarr[8] + 'A') << "." << char(tarr[9] + 'A') << "." << char(tarr[10] + 'A') << ".\n";
    cout << "...." << char(tarr[11] + 'A') << "....\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    if(!sorted.empty()){
        sort(sorted.begin(), sorted.end());
    }
    else{
        sorted.push_back(INF);
    }
    
    int idx = 0;
    for(int i = 0; i < MAX; i++){
        if(i != sorted[idx]){
            permutation.push_back(i);
        }
        else{
            idx++;
        }
    }

    do{
        int tarr[MAX];
        int idx = 0;
        for(int i = 0; i < MAX; i++){
            if(arr[i] == -1){
                tarr[i] = permutation[idx++];
            }
            else{
                tarr[i] = arr[i];
            }
            
        }

        // for(auto a: tarr){
        //     cout << a << " ";
        // }
        // cout << "\n";

        bool flag = true;
        for(auto [idx1, idx2, idx3, idx4]: darr){
            if(tarr[idx1] + tarr[idx2] + tarr[idx3] + tarr[idx4] != INF){
                flag = false;
                break;
            }
        }

        if(flag){
            output(tarr);
            break;
        }

    }while(next_permutation(permutation.begin(), permutation.end()));

    return 0;
}