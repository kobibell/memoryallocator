#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main() {
    // Initialize statistics variables
    int total_external_fragments = 0;
    int total_nodes_traversed = 0;
    int total_allocation_requests = 0;
    int total_denied_requests = 0;

    init_memory(1000);

    // Generate 10,000 requests
    for (int i = 0; i < 10000; i++) {
        // Generate a random process ID and number of units
        int process_id = rand() % 1000 + 1;
        int num_units = rand() % (MAX_UNITS - MIN_UNITS + 1) + MIN_UNITS;

        // Allocate memory
        int nodes_traversed = allocate_mem(process_id, num_units);
        if (nodes_traversed == -1) {
            // Allocation request denied
            total_denied_requests++;
        } else {
            // Allocation request successful
            total_nodes_traversed += nodes_traversed;
            total_allocation_requests++;
        }

        // Calculate external fragments
        int fragments = fragment_count();
        total_external_fragments += fragments;
    }

    // Print statistics
    print_statistics();


    return 0;
}
