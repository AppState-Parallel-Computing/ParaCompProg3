#include <thread>
#include <vector>
#include <math.h>
#include <chrono>
#include "helpers.h"
#include "ThreadedScan.h"

/*
 * ThreadedScan
 * Initializes the private data members of the ThreadedScan object.
 */ 
ThreadedScan::ThreadedScan(std::vector<int> nums, long int numThreads)
{
  this->numThreads = numThreads;
  this->subarraySize = ceil(nums.size()/(double)numThreads);
  //Use std::move to prevent another copy of nums being made.
  //Moves the nums resources to this->nums.
  this->nums = std::move(nums);
}

/*
 * performScan
 * This function performs the parallel prefix scan that is
 * described in the textbook on pages 25 and 26 (Listing 2.2).
 * However, you may not assume that the size of the vector
 * is evenly divisible by the number of threads.  Thus, the last
 * thread may operate on fewer elements than the other threads.
 *
 * You should write some helper lambda functions.
 */
float ThreadedScan::performScan()
{ 
  TIMERSTART(threaded)

  //Step 1:
  //Create threads so that each thread performs the prefix
  //scan on the subarray

  //Step 2:
  //Main thread performs prefix scan of right most values in each subarray
  
  //Step 3:
  //Create more threads so that each thread adds the value computed
  //by thread i - 1 in the last step to each element of subarray i

  TIMERSTOP(threaded)

  return GETTIME(threaded);
}

/*
 * get
 * Returns a reference to the private vector.
 */
std::vector<int> & ThreadedScan::get()
{
  return nums;
}

