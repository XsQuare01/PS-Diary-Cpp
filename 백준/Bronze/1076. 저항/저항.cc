#define MAX 1000000
#define MOD 9901
#define INF 200000

#include<bits/stdc++.h>

using namespace std;

string s1, s2, s3;
long long ret = 0;

enum color{
    black,
    brown,
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    grey,
    white
};

int SetColor(string s){
    if(s == "black"){
        return black;
    }
    if(s == "brown"){
        return brown;
    }
    if(s == "red"){
        return red;
    }
    if(s == "orange"){
        return orange;
    }
    if(s == "yellow"){
        return yellow;
    }
    if(s == "green"){
        return green;
    }
    if(s == "blue"){
        return blue;
    }
    if(s == "violet"){
        return violet;
    }
    if(s == "grey"){
        return grey;
    }
    if(s == "white"){
        return white;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2 >> s3;
    ret = (10 * SetColor(s1) + SetColor(s2)) * pow(10, SetColor(s3));
    cout << ret;


    return 0;
}