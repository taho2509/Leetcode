class Solution {
public:
    map<char,int>mp;
    string frequencySort(string s) {
        for(char c : s){
            mp[c]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto item : mp){
            q.push({item.second,item.first});
        }
        int i=0; pair<int,char> c;
        while(!q.empty()){
            c=q.top();
            q.pop();
            while(c.first>0){
                s[i]=c.second;
                c.first--;
                i++;
            }
        } return s;
        
    }
};