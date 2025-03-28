// shm.hpp
// Layth Alabed
// Producer and consumer problem
// Shared memory header file

#ifndef SHM_HPP
#define SHM_HPP

#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>
#include <semaphore.h>
#include <pthread.h>

using std::cin; using std::cout; using std::endl; //Makes it convenient for me to write code quicker just a preference 
using std::string;

const char* SHARED_MEM_NAME = "/my_shared_memory"; // Shared memory segment name
const char* SEMAPHORE_NAME = "/my_semaphore"; // Semaphore name for critical section control
const static int BUFFER_CAPACITY = 6; // Buffer capacity made it 6 so we can see different numbers 

// Structure representing the shared buffer
struct SharedBuffer {
    int buffer[BUFFER_CAPACITY]; // An array that acts like a shared table 
};

#endif
