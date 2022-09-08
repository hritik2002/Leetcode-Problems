class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int isLands = 0 ;
        vector<int> dir = {0, 1, 0, -1, 0};
        
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(grid[i][j]=='1'){
                    queue<pair<int, int>> nodes;
                    nodes.push({i, j});
                    grid[i][j] = '0';
                    isLands++;
                    
                    while(nodes.size()) {
                        auto front = nodes.front();
                        nodes.pop();
                        
                        for(int k = 0; k < 4; k++) {
                            int r = front.first + dir[k], c = front.second + dir[k + 1];
                            
                            if(r >= 0 && r < row && c >= 0 && c < col && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                nodes.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        
        return isLands ;
    }
    
};