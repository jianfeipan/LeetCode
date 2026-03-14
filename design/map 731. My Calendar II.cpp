class MyCalendarTwo {
public:
    MyCalendarTwo() = default;
    
    bool book(int start, int end) 
    {
        ++timeLine[start];
        --timeLine[end];
        
        int eventsNumber = 0;
        for(const auto & [time, count] : timeLine)
        {
            eventsNumber+=count;
            if(eventsNumber>2)
            {
                --timeLine[start];
                ++timeLine[end];
                return false;
            }
        }
        return true;
    }
    
private:
    map<int, int> timeLine; 
    
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
