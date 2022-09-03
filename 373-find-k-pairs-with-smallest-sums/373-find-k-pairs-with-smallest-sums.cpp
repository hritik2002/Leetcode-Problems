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
        
        while(!q.empty())
        {
            auto top = q.top();
            ans.push_back({top.second.first, top.second.second});
            q.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};