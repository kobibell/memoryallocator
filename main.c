#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main() {
    // Generate 10,000 requests
    for (int i = 0; i < 10000; i++) {
        // Generate allocation/deallocation requests
        int process_id = generate_process_id(); // Replace with your own logic to generate process ID
        int num_units = generate_num_units(); // Replace with your own logic to generate number of units
        int allocated_nodes = allocate_mem(process_id, num_units);
        if (allocated_nodes != -1) {
            // Allocation successful, update performance parameters
            update_allocation_stats(allocated_nodes);
        } else {
            // Allocation denied, update performance parameters
            update_denied_stats();
        }

        // Invoke deallocate_mem function
        int deallocated = deallocate_mem(process_id);
        if (deallocated == 1) {
            // Deallocation successful, update performance parameters
            update_deallocation_stats();
        }
    }

    // Print statistics
    print_statistics();

    return 0;
}


