// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void getPaths(int i,int j,vector<vector<int>>&m,int n,string path,vector<string>&res){
        if(i==n || j==n || i<0 || j<0 || m[i][j]!=1)return ;
        if(i==n-1 && j==n-1){
            res.push_back(path);
            return ;
        }
        path.push_back('D');
        m[i][j] = 0 ;
        getPaths(i+1,j,m,n,path,res);
        path.pop_back();
        path.push_back('U');
        getPaths(i-1,j,m,n,path,res);
        path.pop_back();
        path.push_back('R');
        getPaths(i,j+1,m,n,path,res);
        path.pop_back();
        path.push_back('L');
        getPaths(i,j-1,m,n,path,res);
        path.pop_back();
        m[i][j] = 1 ;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        string path = "";
        getPaths(0,0,m,n,path,res);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends