class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int>mp1;
        map<int,int>mp2;
        map<int,int>same;
        int count = 0;
        for(int i=0;i<tops.size();i++){
            if(mp1[tops[i]]){
                mp1[tops[i]]++;
            }else mp1[tops[i]] = 1;
            if(tops[i]==bottoms[i]){
                if(!same[tops[i]])
                    same[tops[i]] = 1 ;
                else
                    same[tops[i]]++;
            }
        }
        for(int i=0;i<tops.size();i++){
            if(mp2[bottoms[i]]){
                mp2[bottoms[i]]++;
            }else mp2[bottoms[i]] = 1;
        }
        for(auto val : mp1)
            if(val.second+mp2[val.first]-same[val.first]==tops.size())return tops.size()-max(val.second,mp2[val.first]);
        return -1 ;
    }
};