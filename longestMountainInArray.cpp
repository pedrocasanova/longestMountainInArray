class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int currMountainSize = 0u, maxMountainSize = 0u;
        vector<int> maximaList;
        // first loop: identify local maxima
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if ((arr[i - 1] < arr[i]) && (arr[i] > arr[i+1]))
            {
                maximaList.insert(maximaList.begin(), i);    
            }
        }
        // second loop: for each local maxima identify largest mountain array
        while(!maximaList.empty())
        {
            currMountainSize = 3u;
            //traverse left slope
            for(int i = maximaList.back() - 1; i > 0; i--)
            {
                if(arr[i] > arr[i-1]) currMountainSize++;
                else break;
            }
            //traverse right slope
            for(int i = maximaList.back() + 1; i < arr.size() - 1; i++)
            {
                if(arr[i] > arr[i+1]) currMountainSize++;
                else break;
            }
            //update maximum
            if (currMountainSize > maxMountainSize) maxMountainSize = currMountainSize;
            //pop maxima list
            maximaList.pop_back();
        }
        return maxMountainSize;
    }
};