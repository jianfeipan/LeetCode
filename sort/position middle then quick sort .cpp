#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
static void print(const std::vector<T> & v)
{
   std::cout << "[ ";
   for (const T & t : v)
      std::cout << t << ' ';
   std::cout << "]" << std::endl;;
}


template<typename T>
void swap(vector<T> & elements, int left, int right)
{
   T temp = elements[left];
   elements[left] = elements[right];
   elements[right] = temp;
}
//quick sort is from a problem : how to put all smaller element to left and bigger element to right ? givens "nums" and "mid"
template<typename T>
void positionMid(vector<T> & elements, int from, int to, const T & mid)
{
   if (from >= to) return;
   
   int smallZone = from - 1;
   for (int i = from; i <= to; ++i)
   {
      
      if (elements[i] <= mid)
      {
         swap(elements, smallZone + 1, i);
         ++smallZone;
      }
   }
}


/*
when we know how to move element with a middle value, the quick sort strategy is :
   divid and conquer : put a middle, then left do the same, right do the same
   a small detail is how to chose the middle : we can take the last number, positionMid on 0 - n-2, then swap the smallZon+1(the first larger element) and the last element
   so that we have a middle position from 0 to n-1

*/
static void process_quick_sort(std::vector<int> & elements, int from, int to)
{
   if (from >= to)
      return;

   int mid = elements[to];

   int smallZone = from - 1;
   for (int i = from; i <= to-1; ++i)
   {
      if (elements[i] <= mid)
      {
         swap(elements, smallZone + 1, i);
         ++smallZone;
      }
   }
   swap(elements, smallZone + 1, to);

   process_quick_sort(elements, from, smallZone);//smallZone +1 this position is already good
   process_quick_sort(elements, smallZone + 2, to);


}


void quick_sort(std::vector<int> & s)
{
   process_quick_sort(s, 0, s.size() - 1);
}


int main()
{
   std::vector<int> nums = { 8,5,2,7,3,1,4,0 };
   std::cout << "input: \n";
   print(nums);

   std::vector<int> toPositionMid = nums;

   std::cout << "positionMid : \n";

   positionMid(toPositionMid, 0, toPositionMid.size()- 1, 3);

   print(toPositionMid);

   auto toQuickSort = nums;

   std::cout << "sort : \n";

   quick_sort(toQuickSort);

   print(toQuickSort);

   return 0;

}
