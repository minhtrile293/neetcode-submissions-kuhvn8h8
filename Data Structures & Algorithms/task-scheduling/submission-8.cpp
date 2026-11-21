class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int>mapped;
        for(char c : tasks){
            mapped[c]++;
        }
        priority_queue<pair<int, pair<char, int>>>q;
        for(auto it = mapped.begin(); it != mapped.end(); it++){
            q.push({it->second, {it->first, 0}});
        }
        string cycle = "";
        
        int time = 0;
        queue<pair<int, pair<char, int>>>waited; 
        while (!q.empty() || !waited.empty()){
            while(!waited.empty() && waited.front().second.second <= time){
                auto c = waited.front();
                waited.pop();
                q.push(c);
            } 
            if(!q.empty()){
                auto item = q.top(); 
                q.pop(); 

                cycle += item.second.first;


                item.first--;
                time++;
                int available = time + n;
                item.second.second = available;
                if(item.first){
                    waited.push(item);
                }
                
            } else {
                cycle += 'I';
                time++;
            }
        }
        return time;
    }
};

// A - B - C idle A idle idle idle A
// B - A - C idle idle A idle idle idle A
// B - C - A idle idle idle A idle idle idle A
