#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

Block* memory = NULL;
int total_nodes_traversed = 0;
int total_allocations = 0;
int total_denied_allocations = 0;

void init_memory(int size) {
    memory = (Block*) malloc(sizeof(Block));
    memory->process_id = 0; // Set process_id to 0 for the initial block
    memory->size = size;
    memory->next = NULL;
}

int allocate_mem(int process_id, int num_units) {
    Block* current = memory;
    Block* prev = NULL;
    int nodes_traversed = 0;

    while (current != NULL) {
        if (current->size >= num_units) {
            // Allocate memory
            Block* new_block = (Block*)malloc(sizeof(Block));
            new_block->process_id = process_id;
            new_block->size = num_units;
            new_block->next = current;

            if (prev == NULL) {
                memory = new_block;
            } else {
                prev->next = new_block;
            }

            current->size -= num_units;
            nodes_traversed++;

            // Update statistics variables
            total_nodes_traversed += nodes_traversed;
            total_allocations++;

            return nodes_traversed;
        }

        prev = current;
        current = current->next;
        nodes_traversed++;
    }

    // Update statistics variables for denied allocation
    total_denied_allocations++;
    
    return -1;
}


int deallocate_mem(int process_id) {
    Block* current = memory;
    Block* prev = NULL;

    while (current != NULL) {
        if (current->process_id == process_id) {
            if (prev == NULL) {
                memory = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return 1;
        }

        prev = current;
        current = current->next;
    }

    return -1;
}

int fragment_count() {
    Block* current = memory;
    int count = 0;

    while (current != NULL) {
        if (current->size <= 2) {
            count++;
        }

        current = current->next;
    }

    return count;
}

void print_statistics() {
    printf("End of First Fit Allocation\n");
    printf("Average External Fragments Each Request: %.6f\n", (double)fragment_count() / 10000);
    printf("Average Nodes Transversed Each Allocation: %.6f\n", (double)total_nodes_traversed / total_allocations);
    printf("Percentage Allocation Requests Denied Overall: %.6f%%\n", (double)total_denied_allocations / total_allocations * 100);
    printf("End of Best Fit Allocation\n");
    // Print the values of the variables


    // Repeat the above printf statements for Best Fit Allocation
}
