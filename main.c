#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main() {
    // Declare and initialize variables for statistics
    float avg_external_fragments_first_fit = 0.0;
    float avg_nodes_traversed_first_fit = 0.0;
    float allocation_denied_percent_first_fit = 0.0;

    float avg_external_fragments_best_fit = 0.0;
    float avg_nodes_traversed_best_fit = 0.0;
    float allocation_denied_percent_best_fit = 0.0;
    float avg_external_fragments = 0.0;


    // Initialize the memory linked list
    head = (Node*)malloc(sizeof(Node));
    head->process_id = -1; // Indicates a free block
    head->start_address = 0;
    head->size = 256; // 256 KB
    head->status = 0;
    head->next = NULL;

    // // Generate and process 10,000 requests for first fit allocation
    // for (int i = 0; i < 10000; i++) {
    //     int process_id = i + 1;
    //     int num_units = (rand() % 8) + 3; // Randomly generate between 3 and 10 units

    //     if (allocate_mem(process_id, num_units) == -1) {
    //         printf("Allocation failed for process %d\n", process_id);
    //     }

    //     // Deallocate memory for a random process
    //     int random_process_id = rand() % (i + 1) + 1;
    //     if (deallocate_mem(random_process_id) == -1) {
    //         printf("Deallocation failed for process %d\n", random_process_id);
    //     }
    // }

    // Calculate and print statistics for first fit allocation
    avg_external_fragments_first_fit = fragment_count() / 10000.0;
    avg_nodes_traversed_first_fit = (float)nodes_traversed_total / allocation_count;
    allocation_denied_percent_first_fit = (float)allocation_denied_count / 10000 * 100;

    printf("End of First Fit Allocation\n");
    printf("Average External Fragments Each Request: %.6f\n", avg_external_fragments_first_fit);
    printf("Average Nodes Transversed Each Allocation: %.6f\n", avg_nodes_traversed_first_fit);
    printf("Percentage Allocation Requests Denied Overall: %.6f%%\n", allocation_denied_percent_first_fit);

    // Reset necessary variables for best fit allocation
    avg_external_fragments = 0;
    allocation_count = 0;
    allocation_denied_count = 0;
    nodes_traversed_total = 0;

    // // Generate and process 10,000 requests again for best fit allocation
    // for (int i = 0; i < 10000; i++) {
    //     int process_id = i + 1;
    //     int num_units = (rand() % 8) + 3; // Randomly generate between 3 and 10 units

    //     if (allocate_mem_best_fit(process_id, num_units) == -1) {
    //         printf("Allocation failed for process %d\n", process_id);
    //     }

    //     // Deallocate memory for a random process
    //     int random_process_id = rand() % (i + 1) + 1;
    //     if (deallocate_mem(random_process_id) == -1) {
    //         printf("Deallocation failed for process %d\n", random_process_id);
    //     }
    // }

    // Calculate and print statistics for best fit allocation
    avg_external_fragments_best_fit = fragment_count() / 10000.0;
    avg_nodes_traversed_best_fit = (float)nodes_traversed_total / allocation_count;
    allocation_denied_percent_best_fit = (float)allocation_denied_count / 10000 * 100;

    printf("End of Best Fit Allocation\n");
    printf("Average External Fragments Each Request: %.6f\n", avg_external_fragments_best_fit);
    printf("Average Nodes Transversed Each Allocation: %.6f\n", avg_nodes_traversed_best_fit);
    printf("Percentage Allocation Requests Denied Overall: %.6f%%\n", allocation_denied_percent_best_fit);

    return 0;
}
