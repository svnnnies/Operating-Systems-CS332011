// producer.cpp 
// Layth Alabed
// Producer and consumer problem
// Producer implementation

#include "shm.hpp"

int main() {
    srand(time(nullptr)); // Initialize random seed for item production

    // Open shared memory
    int sharedMemFD = shm_open(SHARED_MEM_NAME, O_CREAT | O_RDWR, 0666);
    if (sharedMemFD == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    ftruncate(sharedMemFD, sizeof(SharedBuffer));
    SharedBuffer *sharedMem = (SharedBuffer*)mmap(NULL, sizeof(SharedBuffer), PROT_READ | PROT_WRITE, MAP_SHARED, sharedMemFD, 0);
    if (sharedMem == MAP_FAILED) { // Error handling for shared memory mapping
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Create semaphore
    sem_t *semaphore = sem_open(SEMAPHORE_NAME, O_CREAT, 0644, 1);
    if (semaphore == SEM_FAILED) { // Error handling for semaphore creation
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    // Produce items into shared memory
    for (int i = 0; i < BUFFER_CAPACITY; ++i) { //BUFFER_CAPACITY = 6 so it will only produce 6 times/items (is items the correct wording?)
        sem_wait(semaphore); // It will wait for the semaphore

        // Produce data
        int producedItem = rand() % 10 + 1; // This is where it will generate a random item from 1 to 10 
        sharedMem->buffer[i] = producedItem; // Takes the random item that it produced and stores it in the buffer
        cout << "Producer produced data: " << producedItem << endl;

        sem_post(semaphore); // Release the semaphore
    }

    // Close the semaphore
    sem_close(semaphore);
    return 0; // Exit successfully
}
