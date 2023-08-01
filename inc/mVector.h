#include <stdint.h>
#include <initializer_list>
#include <iterator>
#include <cstddef>
namespace mStd
{
    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using reference = int&;

        Iterator(pointer ptr):
            mPtr(ptr){}
        reference operator*()const{return *mPtr;}
        pointer operator->() {return mPtr;}
        Iterator& operator++() {mPtr++; return *this;}
        Iterator operator++(int) {Iterator tmp = *this; ++(*this); return tmp;}

        friend bool operator==(const Iterator& a, const Iterator& b) {return (a.mPtr == b.mPtr);}
        friend bool operator!=(const Iterator& a, const Iterator& b) {return (a.mPtr != b.mPtr);}
    private:
        pointer mPtr;
    };
    
    class mVector
    {
        const uint8_t BUFFER_STEP_SIZE = 3;
        int* mData[2];
        int mBufferNumber;
        uint32_t mSize;
        uint32_t mAllocatedMemSize;
    public:
        mVector();
        mVector(uint32_t size, int value);
        mVector(std::initializer_list<int> l);
        ~mVector();
        Iterator begin(){return Iterator(&mData[mBufferNumber][0]);}
        Iterator end(){return Iterator(&mData[mBufferNumber][mSize]);}
        void printData(void);
        void pushBack(int);
        void popBack(void);
        int capacity(void) const;
        int* data(void) const;
        void clear(void);
        int front(void) const;
        int back(void) const;
        int at(uint32_t) const;
        int operator[](int i);
        void operator=(const mVector vec);
        bool operator==(const mVector vec);
        bool operator!=(const mVector vec);
    private:
        void switchBuffer(void);
    };
}