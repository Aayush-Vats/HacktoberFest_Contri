class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {

    if (nums.size() == 0)
      return 0;

    int i, k = 1;
    for (i = 1; i < nums.size(); i++)
    {
      if (nums[i] != nums[k - 1])
      {
        nums[k] = nums[i];
        k += 1;
      }
    }
    return k;
  }
};