#include <stdint.h>

// Structure to represent a row of data in a table
typedef struct TableRow {
    char ** values; // Array of values for each column
} TableRow;

// Structure to represent metadata for a table
typedef struct TableMetadata {
    uint32_t num_columns; 
    uint32_t num_rows; 
    size_t table_size;
    char * table_name;  
    struct TableRow table_rows[]; // has to be at the end of the struct                 
} TableMetadata;



