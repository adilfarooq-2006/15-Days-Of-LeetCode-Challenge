class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // We add a 0 height at the end. 
        // This forces the stack to empty out at the end of the loop,
        // ensuring we process remaining bars.
        heights.push_back(0);
        
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            // While the stack is not empty AND the current bar is shorter 
            // than the bar at the top of the stack:
            // This means 'i' is the Right Boundary for the bar at st.top()
            while (!st.empty() && heights[st.top()] > heights[i]) {
                
                // 1. Get the height of the bar we are processing
                int h = heights[st.top()];
                st.pop();
                
                // 2. Determine the width
                // The Right Boundary is 'i'
                // The Left Boundary is the new st.top() (the index remaining in stack)
                int w;
                if (st.empty()) {
                    // If stack is empty, it means 'h' was the smallest so far.
                    // It extends all the way from index 0 to i.
                    w = i; 
                } else {
                    // Width = Right Boundary - Left Boundary - 1
                    w = i - st.top() - 1;
                }
                
                // 3. Update Max Area
                maxArea = max(maxArea, h * w);
            }
            
            // Push the current index onto the stack
            st.push(i);
        }

        return maxArea;
    }
};