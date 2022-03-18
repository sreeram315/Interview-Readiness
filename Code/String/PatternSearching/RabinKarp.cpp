#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
bool search(string pat, string txt, int q)  { 
    long long n = txt.length(), m = pat.length();
    long long t = 0, p = 0;
    long long h=1;
    for(long long i=1;i<=m-1;i++)
        h=(h*d)%q;
    for(int i=0;i<m;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
    
    for(long long i = 0; i <= n-m; i++){
        // printf("--\n%d\n%d\n--\n", p, t);
        if(p==t){
            bool flag = true;
            for(long long k = 0; k < m; k++){
                if(pat[k] != txt[i+k]){
                    flag = false; break;
                }
            }
            if(flag) {
                // printf("got at %d\n", i);
                return true;
            }
        }
        
        if(i<n-m){
            t = ((d*(t-txt[i]*h))+txt[i+m])%q;
            // t = ((t*d + txt[i+m])%q - (txt[i]* ((int)pow(d, m))%q )%q )%q;
            if(t<0) t += q;
        }
        
    }
    return false;
} 