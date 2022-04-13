class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i =0 , j = 0 ;
        bool flag = true ;
        int count = 1 ;
        int tempI = n , tempJ = n ;
        vector<vector<int>>matrix(n,vector<int>(n,0));
        while(i<tempI && j<tempJ){
            // right
            for(  ; j < tempJ ; j++){
                matrix[i][j]=count;
                count++;
            }
            j--;
            i++;
            //down
            for(  ; i < tempI ; i++){
                matrix[i][j]=count;
                count++;
            }
            i--;
            j--;
            //left
            for(  ; j >= n-tempJ ; j--){
                matrix[i][j]=count;
                count++;
            }
            j++;
            i--;
            tempJ--;
            tempI--;
            //up
            for( ; i>=n-tempI ; i--){
                matrix[i][j]=count;
                count++;
            }
            i++;
            j++;
            
        }
        return matrix;
    }
};