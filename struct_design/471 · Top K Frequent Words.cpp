class Solution {
public:
    /**
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    vector<string> topKFrequentWords(vector<string> &words, int k) {
        //heap : priority_queue

        unordered_map<string, size_t> counts;
        for(const auto & word : words)
        {
            ++counts[word];
        }
        
        auto countLess = [](const pair<string, size_t> & left, const pair<string, size_t> & right)
        {
            if(left.second==right.second)
                return left.first>right.first;
            return left.second<right.second;
        };
        
        priority_queue<pair<string,size_t>,
            vector<pair<string, size_t>>,
            decltype(countLess)> maxHeap(countLess);//bydefault maxheap : with less = true cmp

        for(const auto & wordCount : counts)
        {
            cout<<wordCount.first<<wordCount.second<<endl;
            maxHeap.push(wordCount);
        }

        cout<<maxHeap.empty()<<endl;

        vector<string> topK; topK.reserve(k);
        for(int i = 0; i<k && !maxHeap.empty(); ++i)
        {
            cout<<maxHeap.top().first<<maxHeap.top().second<<endl;

            topK.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return topK;
    }
};
