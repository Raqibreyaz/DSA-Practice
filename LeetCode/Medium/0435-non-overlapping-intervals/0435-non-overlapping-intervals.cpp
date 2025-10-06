/*

1. according to question, [1,2] and [2,3] are non-overlapping
2. if an interval overlaps with previous then skip the min range one
ex: [2,3] and [1,5] are overlapping
- if i skip [2,3] then there are more chances that [1,5] overlaps with others because 5 - 1 = 4
- while [2,3] has less chances than [1,5] as 3 - 2 = 1 < 5 - 1 = 4

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& i1, const auto& i2){
            return i1[0] < i2[0];
        });

        int count = 0;
        int prev = 0;
        int curr = 1;
        int n = intervals.size();

        while(curr < n){

            // when overlapping then skip one smaller interval
            if(intervals[prev][1] > intervals[curr][0]){
                count++;

                if(intervals[prev][1] > intervals[curr][1])
                    prev = curr;
            }

            // when no overlapping then just move further
            else{
                prev = curr;
            }

            curr++;
        }

        return count;
    }
};