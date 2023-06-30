#ifndef MEMORY_H
#define MEMORY_H

// Define constants and data structures
#define MEMORY_SIZE 256
#define UNIT_SIZE 2
#define MIN_UNITS 3
#define MAX_UNITS 10

typedef struct Block {
    int process_id;
    int size;
    struct Block* next;
} Block;

// Function prototypes
void init_memory(int size);
int allocate_mem_first_fit(int process_id, int num_units);
int allocate_mem_best_fit(int process_id, int num_units);
int deallocate_mem_first_fit(int process_id);
int deallocate_mem_best_fit(int process_id);
int fragment_count();
void print_statistics();

#endif /* MEMORY_H */
