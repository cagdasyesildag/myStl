#include "mVector.h"
#include <iostream>

namespace mStd
{
    mVector::mVector():
        mSize(0),
        mAllocatedMemSize(0),
        mBufferNumber(0)
    {

    }

    mVector::~mVector()
    {
        if(mData[mBufferNumber] != nullptr)
            delete mData[mBufferNumber];
    }

    int 
    mVector:: memAllocSize(void) const
    {
        return mAllocatedMemSize;
    }

    void 
    mVector::printData(void)
    {
        for(int i = 0; i < mSize; i++)
            std::cout<< mData[mBufferNumber][i]<< ", ";
        std:: cout<< std:: endl;

    }
    
    void 
    mVector::pushBack(int data)
    {
       
        if((mSize + 1) > mAllocatedMemSize)
        {
            mAllocatedMemSize+= BUFFER_STEP_SIZE;
            try
            {
                switchBuffer();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        mData[mBufferNumber][mSize] = data;
        mSize++;        
    }

    void 
    mVector::popBack(void)
    {
        mSize--;
        mData[mBufferNumber][mSize]= 0;

        if((mSize) <= (mAllocatedMemSize-BUFFER_STEP_SIZE))
        {
            mAllocatedMemSize-= BUFFER_STEP_SIZE;
            try
            {
                switchBuffer();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
    }

    int 
    mVector::switchBuffer(void)
    {
       int* oldBuffer = mData[mBufferNumber];

       mBufferNumber= (mBufferNumber==0)? 1: 0;
       mData[mBufferNumber] = new int[mAllocatedMemSize];
       int* newBuffer = mData[mBufferNumber];
       if(!newBuffer)
        throw std::bad_alloc();

       if(mSize)
       {
            for(int i = 0; i < mSize; i++)
            {
                    newBuffer[i] = oldBuffer[i];
            }
            delete oldBuffer;
       }
       std:: cout<< "buffer switched"<< std::endl;
    }

}