class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        // For each string, create a key and group by that key
        for (const string& str : strs) {
            string key = getKey(str);
            anagramGroups[key].push_back(str);
        }
        
        // Convert map to result vector
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
        
    }

    private: 
        string getKey(const string& str) {
        string key = str;
        sort(key.begin(), key.end());
        return key;
    }
};