#include "ThreadedGrid.h"
#include <string>
#include <thread>
#include <mutex>

ThreadedGrid::ThreadedGrid()
:NumberGrid(){}; //The default constructor. Leaves the task queue empty, and lets the parent class
// default constructor set values for its data members.

ThreadedGrid::ThreadedGrid(const int& height, const int& width)
: NumberGrid(height, width){} //Leaves the task queue empty, and passes the parameters on to the parent class constructor.

ThreadedGrid::~ThreadedGrid(){} //Empty, but required destructor.

void ThreadedGrid::calculateAllNumbers(){
std::vector<std::thread> threadedVector;
unsigned int cores = std::thread::hardware_concurrency();
for (int row = 0; row < getHeight(); row++){
    tasks.push_back(row);
}
for (unsigned int i = 0; i < cores; i++){
    threadedVector.push_back(std::thread(&ThreadedGrid::worker, this));
}
for (unsigned int i = 0; i < threadedVector.size(); i++ ){
    threadedVector[i].join();
}
}// Overrides the method of the parent class. Uses the worker method in several threads to do the work. 
//Be sure to manage the task queue, and clean up the threads when they have finished. Use the thread library 
//to decide how many threads to launch, based on the capacity of the computer. It may be useful to use try/catch 
//when creating threads to protect against limited resources.

void ThreadedGrid::worker(){

    while(tasks.size() != 0){
        mutexLock.lock();
        int row = tasks.back();
        tasks.pop_back();
        mutexLock.unlock();
            for (int column = 0; column < getWidth(); column++){
                int num = calculateNumber(row, column);
                setNumber(row, column, num);
            }
            }
    }
//As long as tasks are available in the task queue, get one, and complete it. Should use calculateNumber() and setNumber().