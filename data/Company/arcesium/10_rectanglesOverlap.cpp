/*     Return true if rectangles overlap.
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // false if one lying beside each other 
        if(rec1[2] <= rec2[0] || rec2[2] <= rec1[0]) return false;
        // flase if one lying on top of other
        if(rec1[1] >= rec2[3] || rec2[1] >= rec1[3]) return false;
        // otherwise they overlap
        return true;
    }
};