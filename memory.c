#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#include "memory.h"

typedef struct Block {
    int process_id;
    int num_units;
    struct Block* next;
} Block;


Block* memory = NULL;

int allocate_mem(int process_id, int num_units) {
    Block* current = memory;
    Block* prev = NULL;
    int nodes_traversed = 0;

    while (current != NULL) {
        if (current->num_units >= num_units) {
            // Allocate memory
            Block* new_block = (Block*)malloc(sizeof(Block));
            new_block->process_id = process_id;
            new_block->num_units = num_units;
            new_block->next = current;

            if (prev == NULL) {
                memory = new_block;
            } else {
                prev->next = new_block;
            }

            current->num_units -= num_units;
            nodes_traversed++;
            return nodes_traversed;
        }

        prev = current;
        current = current->next;
        nodes_traversed++;
    }

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
        if (current->num_units <= 2) {
            count++;
        }

        current = current->next;
    }

    return count;
}

void print_statistics() {
    // TODO: Implement the print_statistics function
    // Calculate and print the statistics for each technique
    // Average number of external fragments
    // Average nodes traversed in allocation
    // Percentage of denied allocation requests
}