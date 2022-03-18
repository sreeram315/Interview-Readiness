char nonrepeatingCharacter(string S) {
   vector<int>h(256, 0);
   for(char ch: S) h[ch]++;
   for(char ch: S){
       if(h[ch]==1) return ch;
   }
   return '$';
}