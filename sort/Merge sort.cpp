#include "pch.h"
#include <iostream>
#include <vector>


template<typename T>
static void print(const std::vector<T> & v)
{
   std::cout << "[ ";
   for (const T & t : v)
      std::cout <<t << ' ';
   std::cout << "]" << std::endl;;
}


static void merge(std::vector<int> & s, int from, int mid, int to)
{
   std::vector<int> merged(to - from + 1, 0);
   int left = from;
   int right = mid + 1;
   int mergedIndex = 0;

   while (left <= mid  && right <= to)
   {
      if (s[left] <= s[right])
      {
         merged[mergedIndex] = s[left];
         ++left;
      }
      else
      {
         merged[mergedIndex] = s[right];
         right++;
      }
      ++mergedIndex;
   }
   //rest of left or right
   while (left <= mid)
   {
      merged[mergedIndex] = s[left];
      ++left;
      ++mergedIndex;
   }

   while (right <= to)
   {
      merged[mergedIndex] = s[right];
      ++right;
      ++mergedIndex;
   }

   //put merged into original
   for (int i = 0; i < merged.size(); ++i)
   {
      s[i + from] = merged[i];
   }
   std::cout << "merged : " << std::endl;
   print(merged);
}

static void process_merge_sort(std::vector<int> & s, int from, int to)
{
   if (from >= to)
      return;

   int mid = (from + to) / 2; //>>1
   process_merge_sort(s, from, mid);
   process_merge_sort(s, mid + 1, to);
   merge(s, from, mid, to);
}

void merge_sort(std::vector<int> & s)
{
   process_merge_sort(s, 0, s.size() - 1);
}


int main()
{
   std::vector<int> nums = {2,5,3,1,4};
   
   print(nums);

   std::cout << "sort : \n";

   merge_sort(nums);

   print(nums);

   return 0;

}
