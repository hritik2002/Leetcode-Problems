class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1 ;
        if(grid[0][0]!=grid[n][n] || grid[0][0]!=0){
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1 ;
        int count = 0 ;
        while(!q.empty()){
            int size = q.size();
            int arr[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
            count++;
            
            while(size--){
                pair<int,int>front = q.front() ; q.pop() ;
                int i = front.first , j = front.second ;
                for(auto temp : arr){
                    int xdir = i + temp[0] ;
                    int ydir = j + temp[1] ;
                    if(xdir<0 || ydir<0 || xdir>n || ydir>n )
                        continue;
                    if(grid[xdir][ydir]==1)
                        continue;
                    q.push({xdir,ydir});
                    grid[xdir][ydir]=1 ;
                    if(xdir==n && ydir==n)
                        return count+1;
                    
                }
            }
        }
        
        if(grid[n][n]==0)
            return -1;
        
        return count ;
        
    }
};