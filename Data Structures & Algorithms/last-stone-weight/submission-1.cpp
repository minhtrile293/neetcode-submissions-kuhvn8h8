class Solution {
public:
    priority_queue<int> q;
    int lastStoneWeight(vector<int>& stones) {
        for(int stone : stones){
            q.push(stone);
        }
        while(!q.empty()){
            int y = q.top();
            q.pop();
            if(q.empty())
                return y;
            int x = q.top();
            q.pop();
            int r = y - x;
            if(r){
                q.push(r);
            }
        }
        return 0;
    }
};
