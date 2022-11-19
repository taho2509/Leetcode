class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() < 3) return trees;
        // Find leftybottom point P0 O(n)
        int ip0 = -1;
        int mini = 1000;
        for(int i = 0; i < trees.size(); ++i) {
            if(trees[i][1] < mini) {
                ip0 = i;
                mini = trees[i][1];
            } else if(trees[i][1] == mini && trees[i][0] < trees[ip0][0]) {
                ip0 = i;
            }
        }
        
        vector<int> P0 = trees[ip0];
        
        // Sort by angle(the cotangente is enough) between segment P0Pi and P0POx
        sort(trees.begin(), trees.end(), [&P0, this](vector<int> &a, vector<int> &b) -> bool {
            int diff = orientation(P0, a, b) - orientation(P0, b, a);
            
            if(diff == 0) {
                return distance(P0, a) < distance(P0, b);
            }
            
            return diff <= 0;
        });
        
        int i = trees.size() - 1;
        int t = trees.size() - 1;
        while(i >= 0 && orientation(P0, trees[t], trees[i]) == 0) --i;
        
        for(int j = i + 1, h = t; j < h; ++j, --h) {
            swap(trees[j], trees[h]);
        }
        
        stack<vector<int>> s;
        s.push(trees[0]);
        s.push(trees[1]);
        
        for(int i = 2; i < trees.size(); ++i) {
            auto top = s.top();
            s.pop();
            
            while(orientation(s.top(), top, trees[i]) > 0) {
                top = s.top();
                s.pop();
            }
            
            s.push(top);
            s.push(trees[i]);
        }
        
        vector<vector<int>> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
    
    int orientation(vector<int> &P1, vector<int> &P2, vector<int> &P3) {
        return (P2[1] - P1[1])*(P3[0] - P2[0]) - (P2[0] - P1[0])*(P3[1] - P2[1]);
    }
    
    int distance(vector<int> &P1, vector<int> &P2) {
        return (P1[0] - P2[0])*(P1[0] - P2[0]) +  (P1[1] - P2[1])*(P1[1] - P2[1]);
    }
};