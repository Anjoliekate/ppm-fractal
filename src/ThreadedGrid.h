#ifndef _THREADEDGRID_H_
#define _THREADEDGRID_H_
#include "NumberGrid.h"
#include <thread>
#include <mutex>

class ThreadedGrid: public NumberGrid{
    public:
    ThreadedGrid();
    ThreadedGrid(const int& height, const int& width);
    virtual ~ThreadedGrid();
    virtual void calculateAllNumbers(); 
    virtual void worker();

    protected:
        std::vector<int> tasks;
        std::mutex mutexLock;
};


#endif