class TaskManager {
public:
    unordered_map<int, int> taskPriority;
    unordered_map<int, int> taskOwn;
    priority_queue<pair<int, int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto task : tasks){
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        taskPriority[taskId] = priority;
        taskOwn[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority, taskId});
        taskPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        taskPriority[taskId] = -1;
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [priority, taskId] = pq.top();
            pq.pop();

            if(priority == taskPriority[taskId]){
                taskPriority[taskId] = -1;
                return taskOwn[taskId];
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */