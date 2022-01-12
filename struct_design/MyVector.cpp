

#include "pch.h"
#include <iostream>
#include <stack>


#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

/*

*/
template<class T>
class MyVector {
   //Implement a vector in C++ 
public:
   MyVector(): _size(0), _capacity(0), _data(nullptr){};

   void push_back(const T & t)
   {
      ++_size;
      if (_data == nullptr)
      {
         _data = new T[1];
         _capacity = 1;
      }
      else
      {
         if (_capacity <= _size)
         {
            T* copy = new T[_capacity*2];
            for (size_t index = 0; index < _size-1; index++)
            {
               copy[index] = _data[index];
            }
            delete _data;
            _data = copy;
            _capacity = _capacity * 2;
         }
      }
      _data[_size - 1] = t;
   }

   T& operator[](size_t index)
   {
      if (_size <= index)
         cout << "outof boundry";//throw new invalid_argument("outof boundry");
      return _data[index];
   }

   size_t size() const
   {
      return _size;
   }
private:
   size_t _size;
   size_t _capacity;
   T* _data;
};

int main()
{
   MyVector<int> v;

   cout << v.size() << endl;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);
   cout << v.size() << endl;
   cout << v[0] << endl;
   cout << v[1] << endl;
   cout << v[2] << endl;
   cout << v[3] << endl;
  // cout << v[4] << endl;


   return 0;
}
