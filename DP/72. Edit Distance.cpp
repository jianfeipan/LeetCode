class Solution {

/*
    Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

i = Insert a character
d = Delete a character
r = Replace a character


Facts:
1- 3 options, 
2- transform from one to another2
3- transformation is bi-direction, both works

ideas
1- find the longest sub sequence of word2 in word1
    1.1- double pointer, recursive to try replace or remove
    1.2- use fact 3, we can only do the transform from longer one to shorter or equals one.
    1.3 recursive works!!, but time limit exceeded --> cache
    1.4can we cut some branch:
        --> idea: logic level  we need to cut some branches 
        1.4.1 does it makes sense to do insert operation if longer is alread longer than shoter?
             --> delete or replace makes more sense, casue when you add one, you will defnitly need to delete one
             -- > not working on case "teacher", "tenace"
        

base cases
equals
empty
*/

private:
    int minStepToTransoformFrom(const string & longer, const string & shorter, int  indexLong, int indexShort)
    {   
        
        if(d_minSteps[indexLong][indexShort] != -1) return d_minSteps[indexLong][indexShort];

        
        int minCount = INT_MAX;

        if(indexLong == longer.size()) minCount = shorter.size() - indexShort; //longer used up, insert all short needed

        else if(indexShort == shorter.size()) minCount =  longer.size() - indexLong; // shorter waord all covered, remove the rest in long

        else if(longer[indexLong] == shorter[indexShort]) minCount = minStepToTransoformFrom(longer, shorter, indexLong+1, indexShort+1); //match, nothing to do
        else
        {
            //not equals, three options: r, i, d, and take the min one

            int restShort = shorter.size() - indexShort;
            int restLong =  longer.size() - indexLong;

            //Replace is always worthy
            minCount = std::min(minCount, 1+ minStepToTransoformFrom(longer, shorter, indexLong+1, indexShort+1));//Replace current one
            
            //if(restLong >= restShort) // try to cut branches
                minCount = std::min(minCount, 1+ minStepToTransoformFrom(longer, shorter, indexLong+1, indexShort));//Delete the current one in longer
            //if(restLong <= restShort)
                minCount = std::min(minCount, 1+ minStepToTransoformFrom(longer, shorter, indexLong, indexShort+1));//Insert the current one in longer
        }

        d_minSteps[indexLong][indexShort] = minCount;

        return minCount;
    }

    std::vector<std::vector<int>> d_minSteps;

public:
    int minDistance(string word1, string word2) {
        
        

        string longer;
        string shorter;

        if(word1.size() >= word2.size()) 
        {
            longer = std::move(word1);
            shorter = std::move(word2);

        }
        else
        {
            longer = std::move(word2);
            shorter = std::move(word1);
        }
        d_minSteps = std::vector<std::vector<int>>(longer.size()+1, std::vector<int>(shorter.size()+1, -1));

        return minStepToTransoformFrom(longer, shorter, 0, 0);

    }
};
