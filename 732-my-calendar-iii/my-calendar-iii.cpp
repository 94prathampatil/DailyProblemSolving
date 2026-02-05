class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int s, int e) {
        mp[s] += 1;
        mp[e] -= 1;

        int ans = 0, count = 0;
        for(auto &i : mp){
            count += i.second;
            ans = max(ans, count);
        }

        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */