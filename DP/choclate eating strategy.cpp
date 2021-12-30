#include "pch.h"


#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
/*
You’ve just got a tube of delicious chocolates and plan to eat one piece a day – either by picking the one on the left or the right.

Each piece has a positive integer that indicates how tasty it is. Since taste is subjective, there is also an expectancy factor. A piece will taste better if you eat it later: if the taste is m (as in hmm) on the first day, it will be km on day number k.

Your task is to design an efficient algorithm that computes an optimal chocolate eating strategy and tells you how much pleasure to expect.

*/
static int maxChoclateUtility_greedy(std::deque<int> choclates) 
{
   /*
      greedy : eat from small, keep bigger ones for later to be more happy
   */
   int maxUtility = 0;
   int dayCount = 1;
   while (!choclates.empty())
   {
      int left = choclates.front();
      int right = choclates.back();

      if (left <= right)
      {
         std::cout << "left : " << left << std::endl;
         choclates.pop_front();
         maxUtility += dayCount * left;
      }
      else
      {
         std::cout << "right : " << left << std::endl;
         choclates.pop_back();
         maxUtility += dayCount * right;
      }
      ++dayCount;

   }

   std::cout << std::endl << "max utility: " << maxUtility << std::endl;
   return maxUtility;
}




static int maxChoclateUtility(const std::deque<int> & choclates) 
{
   int maxGreedy = maxChoclateUtility_greedy(choclates);
   return maxGreedy;
}

int main()
{
   maxChoclateUtility({1,2,3,1,4,5,2,6});
   return 0;
}
