class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        small.push(num);//pushed in small to swap have the middle one to see we wan to put into small or larg
        num = small.top(); small.pop();
        large.push(num);//pushed in large to swap have the middle one to see we wan to put into small or larg
        num = large.top(); large.pop();
        
        if(small.size() <= large.size()) small.push(num);
        else large.push(num);
    }
    
    double findMedian() 
    {
        if(small.size() > large.size()) return small.top();
        else return (small.top() + large.top()) * 0.5;
    }
    
private:
    priority_queue<int> small;//maxHeap
    priority_queue<int, vector<int>, greater<int>> large;//minHeap
    
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
