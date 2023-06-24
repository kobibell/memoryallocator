#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#include "memory.h"

Block* memory = NULL;

int allocate_mem(int process_id, int num_units) {
    // TODO: Implement the allocate_mem function
    // Traverse the linked list of free blocks
    // Find the first block that can accommodate the requested memory
    // Allocate the memory and adjust the linked list
    // Return the number of nodes traversed if successful, otherwise return -1
}

int deallocate_mem(int process_id) {
    // TODO: Implement the deallocate_mem function
    // Traverse the linked list of allocated blocks
    // Find the block with the given process ID
    // Deallocate the memory and adjust the linked list
    // Return 1 if successful, otherwise return -1
}

int fragment_count() {
    // TODO: Implement the fragment_count function
    // Traverse the linked list of free blocks
    // Count the number of holes (fragments of sizes 1 or 2 units)
    // Return the count
}

void print_statistics() {
    // TODO: Implement the print_statistics function
    // Calculate and print the statistics for each technique
    // Average number of external fragments
    // Average nodes traversed in allocation
    // Percentage of denied allocation requests
}
 