class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int i = 0, n = intervals.size();

        // push every interval who's end < newInterval's start
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        //merge all relevant intervals with newInterval
        while(i < n && intervals[i][0] <= newInterval[1]){
            mergeInterval(newInterval,intervals[i]);
            i++;
        }
        ans.push_back(newInterval);

        // push all the intervals who's start > newInterval's end
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }

private:
    void mergeInterval(vector<int> &i1, vector<int>& i2){
        i1[0] = min(i1[0],i2[0]);
        i1[1] = max(i1[1],i2[1]);
    }
};