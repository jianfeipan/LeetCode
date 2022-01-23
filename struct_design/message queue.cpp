#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <map>
#include <queue>

using namespace std;

/*
Given (1, “aaa”) (2, “bbb”) (3, “ccc”) (4, “ddd”) (5, “eee”),
1. pass in 1, 输出 “aaa"
2. pass in 3, 不输出任何str，因为跳过了2
3. pass in 2, 输出 “bbb”,“ ccc”
*/

class MessageQueue
{
public:
    void push(int id, const string & msg)    
    {
        _msgs.push({id, msg});
    }
    
    string read(int id)
    {
        _readRequests.insert(id);
        
        string repsonse;
        
        while(!_readRequests.empty() && !_msgs.empty() && _readRequests.count(_msgs.front().first))
        {
            repsonse+=" ";
            repsonse+=_msgs.front().second;
            _readRequests.erase(_msgs.front().first);_msgs.pop();
            
        }
        return repsonse;
    }
    
private:
    queue<pair<int, string>> _msgs;
    unordered_set<int> _readRequests;

};

int main(int argc, char *argv[])
{
    MessageQueue mq;
    mq.push(1,"aaa");
    mq.push(2,"bbb");
    mq.push(3,"ccc");
    mq.push(4,"ddd");
    mq.push(5,"eee");
    
    cout<<mq.read(1)<<endl;
    cout<<mq.read(3)<<endl;
    cout<<mq.read(4)<<endl;
    cout<<mq.read(2)<<endl;
    cout<<mq.read(5)<<endl;
    
    
    return 0;
}
