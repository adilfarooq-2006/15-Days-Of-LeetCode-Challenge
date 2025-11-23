class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        // This handles cases where no warmer day is found (the elements remain 0).
        vector<int> result(n, 0);
        
        // Stack to store indices of days we haven't resolved yet.
        stack<int> s;

        for (int i = 0; i < n; i++) {
            int currTemp = temperatures[i];

            while(!s.empty() && currTemp > temperatures[s.top()]) {
                int prevIndex = s.top();
                s.pop();

                //calculate days past then today and push them at the index
                result[prevIndex] = i - prevIndex;
            }
            // Push the current index to the stack
            s.push(i);
        }

        return result;
        
    }
};