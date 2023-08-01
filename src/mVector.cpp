#include "mVector.h"
#include <cmath>
#include <iostream>
#include <algorithm>

namespace mStd
{
    mVector::mVector():
        mBufferNumber(0),
        mSize(0),
        mAllocatedMemSize(0)
    {

    }

    mVector::mVector(uint32_t size, int value):
        mBufferNumber(0),
        mSize(size)
    {
        mAllocatedMemSize = ceil((float)mSize / BUFFER_STEP_SIZE)*BUFFER_STEP_SIZE;
        mData[mBufferNumber] = new int[mAllocatedMemSize];
        std::fill_n(mData[mBufferNumber], mSize, value);
    }

    mVector::mVector(std::initializer_list<int> l):
        mVector()
    {
        for(int x : l)
            pushBack(x);
    }

    mVector::~mVector()
    {
        if(mData[mBufferNumber] != nullptr)
            delete mData[mBufferNumber];
    }

    int 
    mVector:: capacity(void) const
    {
        return mAllocatedMemSize;
    }

    void 
    mVector::clear(void)
    {
        delete  mData[mBufferNumber];
        mBufferNumber= 0;
        mSize = 0;
        mAllocatedMemSize = 0;
    }

    int 
    mVector::front(void) const
    {
        return mData[mBufferNumber][0];
    }
    
    int 
    mVector::back(void) const
    {
        return mData[mBufferNumber][mSize-1];
    }
        
    int 
    mVector::at(uint32_t index) const
    {   
        if(index > mSize)
            throw std::overflow_error("request bigger than data size");

        return mData[mBufferNumber][index];
    }

    void 
    mVector::printData(void)
    {
        for(uint32_t i = 0; i < mSize; i++)
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

    int* 
    mVector::data(void) const
    {
        return mData[mBufferNumber];
    }

    int 
    mVector::operator[](int i)
    {
        return mData[mBufferNumber][i];
    }

    void 
    mVector::operator=(const mVector vec)
    {
        mBufferNumber = vec.mBufferNumber;
        mAllocatedMemSize = vec.mAllocatedMemSize;
        mSize = vec.mSize;

        mData[mBufferNumber] = new int[mAllocatedMemSize];
        std::copy(vec.data(), vec.data()+vec.mSize, mData[mBufferNumber]);
    }

    bool
    mVector:: operator==(const mVector vec)
    {
        if(mSize!= vec.mSize)
            return false;
        int* buff = vec.data();
        
        for(uint32_t i= 0; i< mSize; i++)
        {
            if(mData[mBufferNumber][i]!= *(buff+i))
                return false;
        }
        return true;
    }

    bool 
    mVector::operator!=(const mVector vec)
    {
        return (*this==vec)? false:true;
    }

    void 
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
            for(uint32_t i = 0; i < mSize; i++)
            {
                    newBuffer[i] = oldBuffer[i];
            }
            delete oldBuffer;
       }
       std:: cout<< "buffer switched"<< std::endl;
    }

}