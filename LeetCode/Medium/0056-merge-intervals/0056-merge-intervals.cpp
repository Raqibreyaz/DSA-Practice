class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(),
             [](const auto& i1, const auto i2) { return i1[0] < i2[0]; });

        int i = 1;
        int n = intervals.size();

        ans.push_back(intervals[0]);

        while (i < n) {

            // non-overlapping < case
            while ((i < n) && ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
                i++;
            }

            // overlapping case
            while (i < n && ans.back()[1] >= intervals[i][0]) {
                ans.back()[0] = min(ans.back()[0], intervals[i][0]);
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                i++;
            }
        }

        return ans;
    }
};