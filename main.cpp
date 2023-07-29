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
    std::vector<int> ops{1,2,3,4,5};
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

    mStd::mVector newVec = mVec;
    for(uint8_t i= 0; i< 2; i++)
        std::cout<< newVec[i] << ": ";
    std::cout<< std::endl;
    mStd::mVector vecc(9, 2);
    vecc.pushBack(3);
    vecc.printData();
    mStd::mVector nVec{1,2,3,4};
    nVec.printData();
    mStd::mVector copyVec(nVec);
    copyVec.printData();
    if(copyVec != nVec)
        std::cout<< "they are not equal"<< std::endl;
    else
        std::cout<< "they are equal"<< std::endl;
}