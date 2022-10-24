class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int currMountainSize = 0u, maxMountainSize = 0u;
        if (arr.size() < 3u)
        {
            return 0u;
        }
        else
        {
            for (int i = 0; i < arr.size() - 1; i++)
            {
                if (arr[i+1] > arr[i])
                {
                    currMountainSize++;
                }
                else
                {
                    if (currMountainSize > maxMountainSize)
                    {
                        maxMountainSize = currMountainSize;
                    }
                    currMountainSize = 0u;
                }
            }
        }
        return maxMountainSize;
    }
};