#include <iostream>
#include "mVector.h"
#include <vector>
#include <algorithm>

void realVector(void);
void mVector(void);

int main()
{
   realVector();
   mVector(); 
   exit(0);
}

void realVector(void)
{
    std::vector<int> vec1{2,4,3,4,5};
    std::vector<int>::iterator itr, itr1;

   itr = vec1.begin();
   itr1 = itr + 2;
   vec1.insert(itr, 7);

    int a= itr1 - itr;
    std::cout<< a << std::endl;

   for(auto x : vec1)
    std::cout<< x << ",";
   std::cout<< std::endl;
}
void mVector(void)
{
    mStd::mVector mVec{1,2,7,8};
    mVec.insert(mVec.end(), 4);
    mVec.printData();

    std::sort(mVec.begin(), mVec.end());
    mVec.printData();

}