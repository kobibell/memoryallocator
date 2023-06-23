#ifndef MEMORY_H
#define MEMORY_H

typedef struct Node {
    int process_id;
    int start_address;
    int size;
    int status; // 0 for free, 1 for allocated
    struct Node* next;
} Node;

extern Node* head;
extern int nodes_traversed_total;
extern int allocation_count;
extern int allocation_denied_count;

// Function prototypes
int allocate_mem(int process_id, int num_units);
int allocate_mem_best_fit(int process_id, int num_units);
int deallocate_mem(int process_id);
int fragment_count();
void print_memory();

#endif
