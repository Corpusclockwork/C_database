#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "data_structures.h"
/*
char * trim(char * string_to_trim) {
    // trim start 
    int i = 0;
    char * string_at_start = &string_to_trim[i];
    while(isspace(string_at_start)) {
        i++;
        char * string_at_start = &string_to_trim[i];
    }
    // trim end
    int end = string_to_trim + strlen(string_to_trim) - 1;
    while(end > string_at_start && isspace((unsigned char)*end)) {
        end--;
    }
    // Write new null terminator character
    end[1] = '\0';
    return str;
}
*/

struct TableMetadata * clear_table_space(int num_rows) {
    size_t table_size = 1000 * num_rows; // size or row times number of rows
    size_t total_size = sizeof(struct TableMetadata) + table_size;
    printf("Table Meta Data size: %zu\n", sizeof(struct TableMetadata));
    printf("Table size: %zu\n", table_size);
    printf("Total allocation size: %zu\n", total_size);

    // Allocate one contiguous block of memory.
    struct TableMetadata * meta_data_pointer = malloc(total_size);

    // ALWAYS check for allocation failure.
    if (my_data == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Set table initial size
    meta_data_pointer->table_size = table_size;
}

struct TableMetadata * set_table(char * filename) {
    int max_row_size = 1000;
    FILE * file_pointer = fopen(filename, "r");
    struct TableMetadata * table_metadata;
    int number_of_malloc_calls = 1; 
    if (file_pointer != NULL) {
        table_metadata->table_name = filename;
        int row_num = 0;
        char row[max_row_size];
        while (fgets(row, max_row_size, file_pointer) != NULL) {
            // if you have less than 5000 (5 rows) of space left, allocate more by calling 
            char * current_column = strtok(row, ",");
            int col_num = 0;
            while (current_column != NULL) {
                //current_column = trim(current_column);
                fflush("%s\n", current_column);
                (table_metadata->table_rows[row_num]).values[col_num] = current_column;
                current_column = strtok(NULL, ",");
                fflush("%d\n", col_num);
                col_num++;
            }
            if (row_num == 0){
                table_metadata->num_columns = col_num;
            }
            fflush("%d\n", row_num);
            row_num ++;
        }
    }
    else {
        printf("Unable to open file!");
    }
    fclose(file_pointer);
    return table_metadata;
}

void clear_table(struct TableMetadata * table_to_clear) {
     // Clean up after you are done
    free(my_data);
    my_data = NULL; // Good practice to prevent use-after-free.
}

int main(void) {
    printf("Starting:\n");
    struct TableMetadata * meta_data_pointer = clear_table_space(10);
    set_table("../csv_files/Route_List.csv", meta_data_pointer);
    clear_table(meta_data_pointer);
    
}
