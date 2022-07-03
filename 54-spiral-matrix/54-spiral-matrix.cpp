class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_start = 0, row_end = matrix.size()-1, col_start =0 ,col_end = matrix[0].size()-1;
        int limit = matrix.size()*(matrix[0].size()) ;
        vector<int>ans(limit);
        int k = 0 ;
        while(k<limit){
            for(int j=col_start;j<=col_end;j++){
                int i = row_start ;
                ans[k++] = matrix[i][j];
            }
            if(k>=limit)break;
            for(int i=row_start+1;i<=row_end;i++){
                int j=col_end;
                ans[k++] = matrix[i][j];
            }
            col_end--;
            row_start++;
            if(k>=limit)break;
            cout<<row_start<<" "<<row_end<<" "<<col_start<<" "<<col_end<<" "<<k<<endl;
            for(int j=col_end;j>=col_start;j--){
                int i=row_end ;
                ans[k++] = matrix[i][j];
            }
            if(k>=limit)break;
            for(int i=row_end-1;i>=row_start;i--){
                int j = col_start ;
                ans[k++] = matrix[i][j];
            }
            row_end--;
            col_start++;
        }
        return ans;
    }
};