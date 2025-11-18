class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //to store the last seen value
        unordered_set<char>charSet;

        int maxLength = 0;
        int left = 0; //pointer pointing in left

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            //remove charcters from left until no duplicate remains
            while(charSet.find(c) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            //Add the current index into charSet (non-duplicate)
            charSet.insert(s[i]);

            maxLength = max(maxLength, i - left + 1 );
        }

        return maxLength;
    }
};