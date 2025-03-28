// consumer.cpp
// Layth Alabed
// Producer and consumer problem
// Consumer implementation

#include "shm.hpp"

int main() {
    // Open the shared memory (shm)
    int sharedMemFD = shm_open(SHARED_MEM_NAME, O_CREAT | O_RDWR, 0666);
    if (sharedMemFD == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    ftruncate(sharedMemFD, sizeof(SharedBuffer));
    
    // Map shared memory (msm)
    SharedBuffer *sharedMem = (SharedBuffer *)mmap(NULL, sizeof(SharedBuffer), PROT_READ | PROT_WRITE, MAP_SHARED, sharedMemFD, 0);
    if (sharedMem == MAP_FAILED) { // Error handling for shared memory mapping
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Open the existing semaphore
    sem_t *semaphore = sem_open(SEMAPHORE_NAME, 0);
    if (semaphore == SEM_FAILED) { // Error handling for semaphore opening
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    // Consume items from shared memory
    for (int i = 0; i < BUFFER_CAPACITY; ++i) { //BUFFER_CAPACITY = 6 so it will only consume 6 times/items 
        sem_wait(semaphore); // Wait for the semaphore

        // Consume data
        cout << "Consumer is consuming data: " << sharedMem->buffer[i] << endl;

        sem_post(semaphore); // Release the semaphore
    }
    
    // Cleanup resources
    sem_close(semaphore); // Close the semaphore
    munmap(sharedMem, sizeof(SharedBuffer)); // Unmap shared memory
    close(sharedMemFD); // Close shared memory file descriptor
    return 0; // Exit successfully
}
