class Solution {
public:
    vector<vector<int>> getFloodFill(vector<vector<int>>& image, int sr, int sc, int color,int prevColor) {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()){
            return image;
        }
        if(image[sr][sc]==color || image[sr][sc]!=prevColor)return image;
        image[sr][sc] = color;
        getFloodFill(image,sr-1,sc,color,prevColor);
        getFloodFill(image,sr,sc-1,color,prevColor);
        getFloodFill(image,sr+1,sc,color,prevColor);
        getFloodFill(image,sr,sc+1,color,prevColor);
        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()){
            return image;
        }
        if(image[sr][sc]==color)return image;
        getFloodFill(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};