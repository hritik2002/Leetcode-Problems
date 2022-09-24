class Solution {
public:
    vector<int>Parent;
    
    int find(int x){
        return Parent[x]==x?x:(Parent[x]=find(Parent[x]));      // O(1)
    }
    
    bool equationsPossible(vector<string>& equations) {
        Parent.resize(26,0);
        
        for(int i=0 ; i<26 ; i++)Parent[i] = i ;
        for(int i=0 ; i<equations.size() ; i++){
            int par1 = find(equations[i][0] - 'a' );
            int par2 = find(equations[i][3] - 'a') ;
            if(equations[i][1]=='=' && par1 != par2){
                Parent[par2] =  par1 ;
            }
        }
        for(auto e:equations){
            string k=e;
            auto x=find(k[0]-'a');
            auto y=find(k[3]-'a');
            
            if(k[1]=='!'){
                if(x==y) return false;
            }
        }

        return true ;
    }
};// saare equal pehle aajayenge