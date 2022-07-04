class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        
        vector<bool> marks(n, false);
        vector<int> candies(n);

        int candy = 0;
        int oldDirection = 0, newDirection;

        for (int i = 1; i < n; ++i) {
            if(oldDirection == 1) candy++;
            else candy = 1;
            
            candies[i - 1] = candy;
            marks[i - 1] = true;
            
            if (arr[i - 1] < arr[i]) {
                newDirection = 1;
            } else if (arr[i - 1] > arr[i]) {
                newDirection = -1;
            } else {
                newDirection = 0;
            }
            
            if(oldDirection == -1 && newDirection == -1) {
                candies[i - 1] = 0;
                marks[i - 1] = false;
            }

            oldDirection = newDirection;
        }

        if (arr[n - 2] < arr[n - 1]) {
            candy++;
            candies[n - 1] = candy;
        } else candies[n - 1] = 1;
        
        marks[n - 1] = true;
        
        arr.push_back(0);
        candies.push_back(0);

        long sum = 0;
        candy = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (!marks[i]) {
                candies[i] = ++candy;
            }
            else
            {
                if((arr[i] > arr[i + 1]) && (candies[i] <= candies[i + 1])) candies[i] = candies[i + 1] + 1;
                candy = 1;
            }
            sum += candies[i];
        }

        return sum;
    }
};