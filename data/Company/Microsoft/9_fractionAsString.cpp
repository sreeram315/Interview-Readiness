/*
Given two integers representing the numerator and denominator of a fraction,
return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

https://leetcode.com/problems/fraction-to-recurring-decimal/
*/

class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        if(num==0) return "0"; 
        string ans = (num<0 ^ deno<0) ? "-" : "";
        long q, rem;
        num = abs(num); deno = abs(deno);
        q = num/deno; rem = num%deno;
        if(rem==0){
            ans += to_string(q);
            return ans;
        } 
        ans += to_string(q)+".";
        rem *= 10;
        unordered_map<int, int>mp;
        while(rem){
            if(mp.find(rem) != mp.end()){
                ans += ")";
                ans.insert(mp[rem], "(");
                break;
            }
            mp[rem] = ans.length();
            q = rem/deno; rem = rem%deno;
            ans += to_string(q);
            rem *= 10;
        }
        
        return ans;
    }
};