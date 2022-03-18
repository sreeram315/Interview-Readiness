#include<bits/stdc++.h>
using namespace std;


int minReplacements(string str){
    int count = 0, len = str.length();
    for(int i = 0; i < str.length(); i++){
        if(i%2==0 && str[i]=='1') count++;
        if(i%2==1 && str[i]=='0') count++;
    }
    return min(count, len-count);
}


int main() {
    string str = "1100";
    cout << minReplacements(str) << endl;
    return 0;
}