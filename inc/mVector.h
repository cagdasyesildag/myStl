#include <stdint.h>

namespace mStd
{
    class mVector
    {
        const uint8_t BUFFER_STEP_SIZE = 3;
        int* mData[2];
        int mBufferNumber;
        int mSize;
        int mAllocatedMemSize;
    public:
        mVector();
        ~mVector();
        void printData(void);
        void pushBack(int);
        void popBack(void);
        int memAllocSize(void) const;
    private:

        int switchBuffer(void);
    };
}