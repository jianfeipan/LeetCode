class MedianFinder {
public:
    MedianFinder() :data(),mid(),left(0), right(0)
    {
        
    }
    
    void addNum(int num) {
        data.insert(num);
        
        if(data.size()==1) 
        {
            mid = data.begin();
        }    
        else
        {
            if(num<*mid) ++left;
            else ++right; 
            
            if(left>right && left - right==1)  --mid,--left,++right;
            else if(right>left && right - left==2) ++mid, --right,++left;
        }
        //cout<<*mid<<endl;
    }
    
    double findMedian() {
        if(data.size()%2 ==1)
            return *mid;
        else
            return (*mid + *next(mid)) * 0.5;
    }
    
    multiset<int> data;
    multiset<int>::iterator mid;
    int left;
    int right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
