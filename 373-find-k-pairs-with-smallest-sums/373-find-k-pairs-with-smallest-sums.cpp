class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int , pair<int , int>> >q;   // to store the pair of sum and pair of elemnts of nums1 and nums2
        
        long long int sum=0;
        
        vector<vector<int>>ans;
        
        for(auto n : nums1)
        {
            // sum=0;
            for(auto m : nums2)
            {
                sum = n+m;
                if(q.size() < k)q.push({sum , {n , m}});
                else if(sum < q.top().first)
                {
                    q.pop();
                    q.push({sum , {n , m}});
                }
                else break;
            }
        }
        
        vector<int>temp;
        
        while(!q.empty())
        {
            temp.push_back(q.top().second.first);
            temp.push_back(q.top().second.second);
            ans.push_back(temp);
            q.pop();
            temp.clear();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};