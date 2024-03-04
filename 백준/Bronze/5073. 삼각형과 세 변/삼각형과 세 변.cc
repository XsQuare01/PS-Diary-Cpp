#define MAX 1000
#define HMAX 500000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int arr[3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        for(int i = 0; i < 3; i++){
            cin >> arr[i];
        }
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0){
            break;
        }
        sort(arr, arr+3);
        if(!arr[0] || !arr[1] || !arr[2]){
            cout << "Invalid" << "\n";
            continue;
        }
        if(arr[0] + arr[1] <= arr[2]){
            cout << "Invalid" << "\n";
            continue;
        }
        if(arr[0] == arr[1] && arr[1] == arr[2]){
            cout << "Equilateral" << "\n";
            continue;
        }
        if(arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[0]){
            cout << "Isosceles" << "\n";
            continue;
        }
        
        cout << "Scalene" << "\n";
    }

    return 0;
}
