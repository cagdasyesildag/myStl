#include <stdint.h>
#include <initializer_list>
namespace mStd
{
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