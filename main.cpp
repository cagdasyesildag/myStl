#include <iostream>
#include "mVector.h"
#include <vector>

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
    std::vector<int> ops;
    ops.push_back(12);
    ops.push_back(15);
    ops.push_back(3);
    ops.pop_back();

    for(auto x : ops)
        std::cout<< x << ", ";
    std::cout<< std::endl;
}
void mVector(void)
{
    mStd::mVector mVec;
    mVec.pushBack(12);
    mVec.pushBack(15);
    mVec.pushBack(3);
    std::cout<< mVec.memAllocSize() << std::endl;
    mVec.pushBack(6);
    mVec.pushBack(1);
    mVec.pushBack(2);
    std::cout<< mVec.memAllocSize() << std::endl;
    mVec.popBack();
    mVec.popBack();
    mVec.popBack();
    std::cout<< mVec.memAllocSize() << std::endl;

    mVec.printData();
}