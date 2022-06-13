// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	set<string>st;
	void helper(string s,vector<string>&ans,int index){
	    if(index==s.length()-1){
	        if(st.count(s))return;
	        st.insert(s);
	        ans.push_back(s);
	        return;
	    }
	    for(int i=index ; i<s.length(); i++){
	        string temp = s;
	        if(i>index && s[i]==s[index])continue;
	        char t = temp[index];
	        temp[index] = temp[i];
	        temp[i] = t;
	        s= temp;
	       // swap(s[index],s[i]);
	       // cout<<temp<<" "<<i<<" "<<index<<endl;
	        helper(temp,ans,index+1);
	    }
	     
	}
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string>ans;
		    helper(s,ans,0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends