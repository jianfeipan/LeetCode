#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <optional>
#include <utility>
#include <climits>
#include <cmath>
#include <sstream>
#include <stack>

using namespace std;

//1234
//1,234
  
// 104450 -> 104,450
// 123123123 -> 123,123,123
  
// 1000000 -> 10,00,000
// 00010100
  
string formatNum(int num) 
{
  if(num == 0 ) return "0";
  
  const int sign = num<0 ? -1 : 1;
  
  int count = 0;
  string numStr;
  while(num)
  {
      numStr+=(sign*num%10)+'0';num/=10;
      if(++count %3 == 0 && num) numStr+=',';
  }
  
  if(sign<0) numStr+='-';
  
  reverse(numStr.begin(), numStr.end());
  
  return numStr;
}
  
int main() 
{
    string res;
    int _num;
    while(cin >> _num)
    {
        res = formatNum(_num);
        cout << res<<endl;
    } 
    return 0;
}
