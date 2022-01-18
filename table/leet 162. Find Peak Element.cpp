class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return binarySearch(num, 0, num.size()-1);
    }
private:
    int binarySearch(const vector<int> &num, int low, int high)
    {
        if(low == high)
            return low;
        else
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] > num[mid2])
            // pick is that you are looking for a direction, going up or going down, from middle you know go to which direction, then you focus on the go up direction part, because the -1 and  infini will be INT_MIN, sure it's a down.
                return binarySearch(num, low, mid1);
            else
                return binarySearch(num, mid2, high);
        }
    }
};
