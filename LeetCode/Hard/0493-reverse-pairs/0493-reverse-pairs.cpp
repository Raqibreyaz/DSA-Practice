class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }

private:
    int merge(vector<int>& arr, int s, int m, int e) {
        vector<int> temp;
        temp.reserve(e - s + 1);

        int i = s, j = m + 1;
        while (i <= m && j <= e) {

            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);               
                j++;
            }
        }
        while (i <= m) {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= e) {
            temp.push_back(arr[j]);
            j++;
        }

        int revCount = countReversePairs(arr,s,m,e);

        for (i = s; i <= e; i++) {
            arr[i] = temp[i - s];
        }

        return revCount;
    }

    int mergeSort(vector<int>& arr, int s, int e) {
        if (s >= e)
            return 0;

        int m = s + (e - s) / 2;

        int leftRevCount = mergeSort(arr, s, m);
        int rightRevCount = mergeSort(arr, m + 1, e);

        // merging both the arrays after sorting
        int revCountMerge = merge(arr, s, m, e);

        return leftRevCount + rightRevCount + revCountMerge;
    }

    int countReversePairs(vector<int> & nums, int s,int m,int e){
        int count = 0;
        for(int  i=s,j=m+1; i <= m && j <= e;){
            if(static_cast<long long>(nums[i]) >static_cast<long long>(nums[j]) *2){
                count += m - i +1;
                j++;
            }
            else{
                i++;
            }
        }

        return count;
    }
};