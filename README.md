Layth Alabed's work for Operating Systems (producer and consumer problem)

# Operating-Systems-CS332011
Contains code for Producer and Consumer problem for Operating System at Kent State 

# Overview 
This project/assignment reguires use to use C++/C to implement the producer consumer relationship in the shared memory buffer.
The project contains three main files: 
1- consumer.cpp 2- producer.cpp 3-shm.hpp
The producer will generate items and put them on a table. The consumer will  consume/pick up items from a table. 
The consumer will wait if there are no any items on the table, if the there items on the table then the producer will wait. (The table can hold only two items). 

In the pdf files we were told to use semaphpres. Semaphores help us to synchronize the producer and the consumer. 

# Compilation 

In this project I used wasp on vscode as it already has all the packages that we need to use already preinstalled (only did so because I had experience with it because of CS2). So in order to compile this project I can go through a quick rundown on how I did it on my vscode.
1- cd OS //open the OS folder 
2- cd Assignment1 //opens the subfolder that's inside the OS folder 

Assingnment1 contains all the files and code necessaery for the producer consumer problem. Now in order to compile and run the program you open up the terminal and use these pthread commands. 

```
g++ producer.cpp -pthread -lrt -o producer
g++ consumer.cpp -pthread -lrt -o consumer
./producer & ./consumer &
```

To see the output, checkout the example.txt file 
PS: the output will be different eachtime



