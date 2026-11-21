class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int>mapped;
        for(char c : tasks){
            mapped[c]++;
        }
        priority_queue<pair<int, char>>q;
        for(auto it = mapped.begin(); it != mapped.end(); it++){
            q.push({it->second, it->first});
            it->second = -1;
        }
        string cycle = "";
        
        queue<pair<int, char>>waited; 
        while (!q.empty() || !waited.empty()){
            if(!waited.empty()){
                auto c = waited.front();
                waited.pop();
                int range = cycle.length() - mapped[c.second]; 
                if(range < n){
                    while(range < n){
                        if(!q.empty()){
                            auto c = q.top(); 
                            q.pop(); 

                            cycle += c.second;
                            c.first--;

                            mapped[c.second] = cycle.length(); 
                            if(c.first){
                                waited.push(c);
                            }
                        } else {
                            cycle += 'I';
                        }
                        range++;
                    }
                }
                q.push(c);
            } else {
                auto item = q.top(); 
                q.pop(); 

                cycle += item.second;
                item.first--;

                mapped[item.second] = cycle.length(); 
                if(item.first){
                    waited.push(item);
                }
            }
        }
        // cout << cycle << endl;
        return cycle.length();
    }
};

// A - B - C idle A idle idle idle A
// B - A - C idle idle A idle idle idle A
// B - C - A idle idle idle A idle idle idle A
