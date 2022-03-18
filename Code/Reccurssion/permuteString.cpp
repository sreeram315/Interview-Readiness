

vector<string>arr;
vector<string> permute(string s, int k = 0){
   if(k==s.length())arr.push_back(s);
   for(int i = k; i < s.length(); i++){
       swap(s[i], s[k]);
       permute(s, k+1, false);
       swap(s[i], s[k]);
   }
   return arr;
}