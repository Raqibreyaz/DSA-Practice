// will return a boolean whether the number exists in the given interval or not
function isThirdExists(
  nums: number[],
  low: number,
  high: number,
  element: number
): boolean {
  let mid: number;

  while (low <= high) {
    mid = Math.floor((low + high) / 2);

    if (nums[mid] === element) {
      return true;
    } else if (nums[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}

function threeSum(nums: number[]): number[][] {
  nums.sort((a, b) => a - b);

  if (nums[0] > 0 || nums[nums.length - 1] < 0) return [];
  let ans: number[][] = [];

  //either 0 or a negative number should be present to create a triplet of sum to 0
  for (let i = 0; i < nums.length && nums[i] <= 0; i++) {
    // if you already computed value for this number then skip this
    if (i > 0 && nums[i - 1] === nums[i]) continue;

    for (let j = i + 1; j < nums.length; j++) {
      //skip the number if you have already used in previous iteration
      if (j - 1 !== i && nums[j] === nums[j - 1]) continue;

      let t = -nums[i] - nums[j];

      //   if you got a number < nums[j] means impossible to find a number after nums[j]
      if (t < nums[j]) break;

      if (isThirdExists(nums, j + 1, nums.length - 1, t)) {
        //         if the elemnt exists then take that array
        ans.push([nums[i], nums[j], t]);
      }
    }
  }
  return ans;
}

function threeSum1(nums: number[]): number[][] {
  let ans: number[][] = [];

  nums.sort((a, b) => a - b);

  //   when the array contains only negative or positive numbers then no answer possible
  if (nums[0] > 0 || nums[nums.length - 1] < 0) return [];

  for (let i = 0; i < nums.length - 2 && nums[i] <= 0; i++) {
    // when you got the same number again then skip it
    if (i > 0 && nums[i - 1] === nums[i]) continue;

    let left = i + 1,
      right = nums.length - 1;

    while (left < right) {
      const sum = nums[i] + nums[left] + nums[right];

      //   when you got answer<0 means left to be increased to increase the sum
      if (sum < 0 || (left - 1 !== i && nums[left - 1] === nums[left])) left++;
      
      // when you got an answer then take it
      else if (sum === 0) {
        ans.push([nums[i], nums[left], nums[right]]);
        left++;
      }

      //   when you got answer>0 means right to be decreased to decrease the sum
      else right--;
    }
  }

  return ans;
}
