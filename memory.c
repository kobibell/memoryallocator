/*

Name of file: memory.c
Team: Kobi Bell and Mark Duraid
Class: CS 480
Assignment #3

*/

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

Block* memory = NULL;
int total_nodes_traversed_first_fit = 0;
int total_allocations_first_fit = 0;
int total_denied_allocations_first_fit = 0;

int total_nodes_traversed_best_fit = 0;
int total_allocations_best_fit = 0;
int total_denied_allocations_best_fit = 0;

void init_memory(int size) {
    memory = (Block*) malloc(sizeof(Block));
    memory->process_id = 0; // Set process_id to 0 for the initial block
    memory->size = size;
    memory->next = NULL;
}

int allocate_mem_first_fit(int process_id, int num_units) {
    Block* current = memory;
    Block* prev = NULL;

    while (current != NULL) {
        if (current->process_id == 0 && current->size >= num_units) {
            current->process_id = process_id;

            if (current->size > num_units) {
                Block* new_block = (Block*) malloc(sizeof(Block));
                new_block->process_id = 0;
                new_block->size = current->size - num_units;
                new_block->next = current->next;
                current->size = num_units;
                current->next = new_block;
            }

            total_nodes_traversed_first_fit++;
            total_allocations_first_fit++;
            return 0;
        }

        prev = current;
        current = current->next;
    }

    total_denied_allocations_first_fit++;
    return -1;
}

int allocate_mem_best_fit(int process_id, int num_units) {
    Block* current = memory;
    Block* best_fit = NULL;
    Block* prev = NULL;

    while (current != NULL) {
        if (current->process_id == 0 && current->size >= num_units) {
            if (best_fit == NULL || current->size < best_fit->size) {
                best_fit = current;
                prev = current;
            }
        }
        current = current->next;
    }

    if (best_fit != NULL) {
        best_fit->process_id = process_id;
        if (best_fit->size > num_units) {
            Block* new_block = (Block*) malloc(sizeof(Block));
            new_block->process_id = 0;
            new_block->size = best_fit->size - num_units;
            new_block->next = best_fit->next;
            best_fit->size = num_units;
            best_fit->next = new_block;
        }

        total_nodes_traversed_best_fit++;
        total_allocations_best_fit++;
        return 0;
    }

    total_denied_allocations_best_fit++;
    return -1;
}

int deallocate_mem_first_fit(int process_id) {
    Block* current = memory;
    Block* prev = NULL;

    while (current != NULL) {
        if (current->process_id == process_id) {
            current->process_id = 0; // Mark this block as free

            // Merge with next block if it's free
            if (current->next != NULL && current->next->process_id == 0) {
                current->size += current->next->size;
                Block* next_next = current->next->next;
                free(current->next);
                current->next = next_next;
            }

            // Merge with previous block if it's free
            if (prev != NULL && prev->process_id == 0) {
                prev->size += current->size;
                prev->next = current->next;
                free(current);
                current = prev;
            }

            return 0;
        }

        prev = current;
        current = current->next;
    }

    return -1; // Process not found
}

int deallocate_mem_best_fit(int process_id) {
    Block* current = memory;
    Block* prev = NULL;

    while (current != NULL) {
        if (current->process_id == process_id) {
            current->process_id = 0; // Mark this block as free

            // Merge with next block if it's free
            if (current->next != NULL && current->next->process_id == 0) {
                current->size += current->next->size;
                Block* next_next = current->next->next;
                free(current->next);
                current->next = next_next;
            }

            // Merge with previous block if it's free
            if (prev != NULL && prev->process_id == 0) {
                prev->size += current->size;
                prev->next = current->next;
                free(current);
                current = prev;
            }

            return 0;
        }

        prev = current;
        current = current->next;
    }

    return -1; // Process not found
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
    int total_requests_first_fit = total_allocations_first_fit + total_denied_allocations_first_fit;
    if (total_requests_first_fit == 0) {
        printf("No allocations for First Fit Allocation.\n");
    } else {
        printf("Average External Fragments Each Request: %.6f\n", (double)fragment_count() / total_requests_first_fit);
        printf("Average Nodes Transversed Each Allocation: %.6f\n", (double)total_nodes_traversed_first_fit / total_requests_first_fit);
        printf("Percentage Allocation Requests Denied Overall: %.6f%%\n", (double)total_denied_allocations_first_fit / total_requests_first_fit * 100);
    }

    printf("End of Best Fit Allocation\n");
    int total_requests_best_fit = total_allocations_best_fit + total_denied_allocations_best_fit;
    if (total_requests_best_fit == 0) {
        printf("No allocations for Best Fit Allocation.\n");
    } else {
        printf("Average External Fragments Each Request: %.6f\n", (double)fragment_count() / total_requests_best_fit);
        printf("Average Nodes Transversed Each Allocation: %.6f\n", (double)total_nodes_traversed_best_fit / total_requests_best_fit);
        printf("Percentage Allocation Requests Denied Overall: %.6f%%\n", (double)total_denied_allocations_best_fit / total_requests_best_fit * 100);
    }
}

