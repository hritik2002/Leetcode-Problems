// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
        vector<bool>prime(N+1,true);
        for(int i=2;i*i<=N;i++){
            if(prime[i]){
                for(int j=i*i;j<=N;j+=i){
                    prime[j] = false;
                }
            }
        }
        prime[1] = false;
        prime[0] = false;
        vector<int>ans;
        for(int i=M ; i<=N ; i++){
            if(prime[i])ans.push_back(i);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends