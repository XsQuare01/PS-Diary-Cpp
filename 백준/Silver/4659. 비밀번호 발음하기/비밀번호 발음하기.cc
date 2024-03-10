    #define MAX 1000
    #define WMAX 30
    #define INF 2000000000

    #include<bits/stdc++.h>

    using namespace std;

    bool IsVowel(char c){
        if(c== 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }

    bool CheckString(string s){
        int cnt = 1;
        bool vflag = IsVowel(s[0]);
        bool eflag = false;
        bool oflag = false;
        char prev = s[0];
        for(int i = 1; i < s.length(); i++){
            if(s[i] == prev && s[i] != 'e' && s[i] != 'o'){
                return false;
            }
            if(s[i] == prev && s[i] == 'e'){
                if(eflag){
                    return false;
                }
                eflag = true;
            }
            if(s[i] == prev && s[i] == 'o'){
                if(oflag){
                    return false;
                }
                oflag = true;
            }
            if(IsVowel(s[i])){
                vflag = true;
            }
            
            if(IsVowel(s[i]) && IsVowel(prev)){
                cnt++;
            }
            if(!IsVowel(s[i]) && IsVowel(prev)){
                cnt = 1;
            }
            if(IsVowel(s[i]) && !IsVowel(prev)){
                cnt = 1;
            }
            if(!IsVowel(s[i]) && !IsVowel(prev)){
                cnt++;
            }

            if(cnt >= 3){
                return false;
            }
            prev = s[i];
        }
        return vflag && true;
    }


    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        while(true){
            string s;
            cin >> s;
            if(s == "end"){
                return 0;
            }

            if(CheckString(s)){
                cout << "<" << s << "> is acceptable." << "\n";
            }
            if(!CheckString(s)){
                cout << "<" << s << "> is not acceptable." << "\n";
            }

        }

        return 0;   
    }
