class Solution {
public:
    int countOperations(int num1, int num2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int cnt = 0;
        while(num1 != 0 && num2 != 0){
            if(num1 >= num2)
                num1 = num1 - num2;
            else
                num2 = num2 - num1;    
            cnt++;
        }

        return cnt;
    }
};