#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

/*
有两个有序数组，一个有n个数例如[2,4,6,7,8]，
另一个为范围区间例如[2,5,10]，输出一个bucket，
其中每个元素为范围内数的个数。上面例子输出[2,3]，其中有两个数（2、4）在范围[2, 5]内，有三个数（6、7、8）在范围[5, 10]内。
*/

vector<size_t> intervalCount(const vector<int> & nums, const vector<int> & intervals)
{
    vector<size_t> counts;
    
    size_t currentCount=0;
    size_t dataIndex = 0;
    size_t intervalIndex = 0;
    
    while(dataIndex<nums.size() && intervalIndex < intervals.size())
    {
        if(nums[dataIndex] < intervals[intervalIndex])
        {
            ++currentCount;
            ++dataIndex;
        }
        else
        {
            counts.push_back(currentCount);
            currentCount = 0;
            ++intervalIndex;
        }
    }
    counts.push_back(currentCount);
    
    
    
    
    return vector<size_t>(counts.begin()+1, counts.end());
}


int main(int argc, char *argv[])
{
   
    auto counts = intervalCount({1,1,2,4, 5,6,7,8,8}, {2,5,10});

    for(const auto & word : counts) cout<<word<<", ";
    cout<<endl;

    return 0;
}
