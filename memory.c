#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

// Global variables
Node* head;
int nodes_traversed_total = 0;
int allocation_count = 0;
int allocation_denied_count = 0;
float avg_external_fragments = 0.0; // Add the declaration of avg_external_fragments

int allocate_mem(int process_id, int num_units) {
    Node* current = head;
    Node* best_fit = NULL;
    int nodes_traversed = 0;

    while (current != NULL) {
        if (current->status == 0 && current->size >= num_units) {
            if (best_fit == NULL || current->size < best_fit->size) {
                best_fit = current;
            }
        }
        current = current->next;
        nodes_traversed++;
    }

    if (best_fit != NULL) {
        best_fit->process_id = process_id;
        best_fit->status = 1;
        if (best_fit->size > num_units) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->process_id = -1;
            new_node->start_address = best_fit->start_address + num_units;
            new_node->size = best_fit->size - num_units;
            new_node->status = 0;
            new_node->next = best_fit->next;
            best_fit->size = num_units;
            best_fit->next = new_node;
        }
        allocation_count++;
        nodes_traversed_total += nodes_traversed;
        return 0;
    } else {
        allocation_denied_count++;
        return -1;
    }
}

int allocate_mem_best_fit(int process_id, int num_units) {
    // Implementation of the allocate_mem_best_fit function
    // ...
    return 0; // or appropriate return value
}

int deallocate_mem(int process_id) {
    Node* current = head;

    while (current != NULL) {
        if (current->process_id == process_id) {
            current->process_id = -1;
            current->status = 0;
            if (current->next != NULL && current->next->status == 0) {
                current->size += current->next->size;
                Node* temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
            return 0;
        }
        current = current->next;
    }

    return -1;
}

int fragment_count() {
    int fragment_count = 0;
    Node* current = head;

    while (current != NULL) {
        if (current->status == 0) {
            fragment_count++;
        }
        current = current->next;
    }

    return fragment_count;
}

void print_memory() {
    Node* current = head;

    while (current != NULL) {
        printf("Process ID: %d | Start Address: %d | Size: %d | Status: %d\n", current->process_id, current->start_address, current->size, current->status);
        current = current->next;
    }
}
