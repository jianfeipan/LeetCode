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


/*
merge sort can be a solution for another problem : smaller sum :

given a vector, every elemnt 's  left has its elements smaller than this element, how to summ them all ?

example : 
{2,5,3,1,4}
2--> left smaler : null
5--> left smaller : 2
3--> 2
1--> null
4--> 2,3,1

result = 2 + 2 + 2+3+1

*/
static int mergeSmallerSum(std::vector<int> & s, int from, int mid, int to)
{
   int sum = 0;

   std::vector<int> merged(to - from + 1, 0);
   int left = from;
   int right = mid + 1;
   int mergedIndex = 0;

   while (left <= mid && right <= to)
   {
      if (s[left] < s[right])
      {
         merged[mergedIndex] = s[left];
         //left smaller than right, so this left element should be sumed N times where N is the number of element bigger than left, which is to-right+1
         sum += (to-right+1) * s[left];
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
   return sum;
}

static int processSmallerSum(std::vector<int> & nums, int from, int to)
{

   if (from >= to)
      return 0;

   const int mid = (from + to) / 2; //>>1
   int leftSum = processSmallerSum(nums, from, mid);
   int rightSum = processSmallerSum(nums, mid+1, to);
   int mergSum = mergeSmallerSum(nums, from, mid, to);

   return leftSum + rightSum + mergSum;
}

int smallerSum(std::vector<int> & nums)
{
   return processSmallerSum(nums, 0 , nums.size()-1);
}



int main()
{
   std::vector<int> nums = {2,5,3,1,4};
   
   print(nums);

   std::cout << "sort : \n";

   std::cout << smallerSum(nums) << std::endl;

   print(nums);

   return 0;

}
