
void computeLPSArray(string pat, vector<int>& lps) { 
    lps[0] = 0;
    int len = 0, i = 1;
    while(i<pat.length()){
        if(pat[i] == pat[len])
            lps[i++] = ++len;
        else{
            if(len == 0){
                lps[i++] = 0;
                continue;
            }
            len = lps[len-1];
        }
    }
}


bool KMPSearch(string pat, string txt) 
{
    int P = pat.length(), n = txt.length();
    vector<int>lps(P);
    computeLPSArray(pat, lps);
    int t = 0, p = 0;
    while(t < n){
        if(pat[p]==txt[t]){
            p++; t++;
        } 
        if(p==P) return true;
        else if(t<n && pat[p]!=txt[t]){
            if(p==0) t++;
            else p = lps[p-1];
        }
    }
    return false;
    
}