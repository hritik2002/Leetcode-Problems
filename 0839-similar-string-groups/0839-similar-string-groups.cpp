class disjoint_set {
    public: 
        vector<int> parent;
        int size;
    
        disjoint_set(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            size = n;
        }
        int find(int node) {
            if(parent[node] != node) {
                parent[node] = find(parent[node]);
            }
            
            return parent[node];
        }
        void join(int i, int j) {
            int xi = find(i), xj = find(j);
            
            if(xi != xj) {
                parent[xi] = parent[xj];
                size--;
            }
        }
        int getSize() {
            return this->size;
        }
};
class Solution {
public:
    bool similar(string& A, string& B) {
        int cnt = 0;
        for(int i = 0; i < A.length(); i++) {
            if(A[i] != B[i]) {
                cnt++;
            }
            if(cnt > 2) {
                return false;
            }
        }
        
        return true;
    }
    int numSimilarGroups(vector<string>& A) {
        disjoint_set ds(A.size());
        
        for(int i = 0; i < A.size(); i++) {
            for(int j = i + 1; j < A.size(); j++) {
                if(similar(A[i], A[j])) {
                    ds.join(i, j);
                }
            }
        }
        
        return ds.getSize();
    }

};

