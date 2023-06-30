Assignment 3

Memory Allocation Simulation

This assignment will simulate memory allocation and deallocation in an operating system. It implements the first fit and then
the best fit memory allocation/deallocation techniques using a linked list to keep track of memory usage. The simulation is able to generate
allocation and deallocation requests and is able to calculate revent statistics as well as provide performacne parameters for both of the
techniques. 

Team Members:
1. Kobi Bell [cssc1432]
2. Mark Duraid [cssc1412]

Files that are included in this project:
1. main.c - Contains the implementation of the memory allocation simulation program.
2. memory.c - Implements the memory component for different allocation/deallocation techniques.
3. memory.h - Header file for the memory component.
4. Makefile - Responsible for building and executing the program.

Compiling and Executing the program (follow in steps):
1. Open the terminal and go to the project directory as listed above.
2. Run the command (make) in order to compile the program.
3. Execute the program by running (./sim)

Components of the Program:
[Memory] implements specific memory allocation/deallocation techniques using a linked list with the following functions.

1.int allocate_mem_first_fit(int process_id, int num_units); This function allocates num_units units of memory to a process whose id is process_id using the first-fit allocation strategy. If successful, it returns the number of nodes traversed in the linked list. Otherwise, it returns -1.

2. int allocate_mem_best_fit(int process_id, int num_units); This function allocates num_units units of memory to a process whose id is process_id using the best-fit allocation strategy. If successful, it returns the number of nodes traversed in the linked list. Otherwise, it returns -1.

3. int deallocate_mem_first_fit(int process_id); This function deallocates the memory allocated to the process whose id is process_id using the first-fit deallocation strategy. It returns 1 if successful, otherwise –1.

4. int deallocate_mem_best_fit(int process_id); This function deallocates the memory allocated to the process whose id is process_id using the best-fit deallocation strategy. It returns 1 if successful, otherwise –1.

5. int fragment_count(); returns the number of holes (fragments of sizes 1 or 2 units).

Request Generation Component:
The request generation component is responsible for generating allocation and deallocation requests. It specifies the process ID and
the number of memory units requested for allocation. It generates the specific requests based on specific criteria such as a 
random sequence or hard coded sequence. 

Statistics Reporting Component:
The statistics reporting component calculates and prints the following for both allocation techniques..
1. The average number of external fragments
2. The average allocation time (average number of nodes traversed in allocation)
3. Percentage of times an allocation request is denied. 

Simulation:
The simulation will generate 10,000 requests using the request generation component. For each request the program will invoke the 
appropriate function of the memory component for each allocation/deallocation. After each request the parameters are then updated.

Conclusion:
In conclusion the following program will simulate memory allocation and deallocation using the first fit and best fit techniques. 
It will provide insight into the average number of external fragments as well as allocation time and percentage of denied requests.
By simulating the techniques listed above, the program helps evaluate and compare the performance of memory management efficiency.
