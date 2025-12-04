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

void clear_table_space(int num_rows, struct TableMetadata * table_metadata) {
    size_t table_size = 1000 * num_rows; // size or row times number of rows
    size_t total_size = sizeof(struct TableMetadata) + table_size;
    printf("Total allocation size: %zu\n", total_size);

    // Allocate one contiguous block of memory.
    table_metadata = calloc(total_size);

    // check for allocation failure.
    if (table_metadata == NULL) {
        perror("Failed to allocate memory");
    }

    // Set table initial size
    table_metadata->table_size = table_size;
    table_metadata->num_rows = num_rows;
}

struct TableMetadata * set_table(char * filename, struct TableMetadata * table_metadata) {
    int max_row_size = 1000;
    FILE * file_pointer = fopen(filename, "r");
    int number_of_malloc_calls = 1; 
    if (file_pointer != NULL) {
        table_metadata->table_name = filename;
        int row_num = 0;
        char row[max_row_size];
        while (fgets(row, max_row_size, file_pointer) != NULL) {
            // if you have no more rows of space left, allocate more by calling realloc
            if (table_metadata->num_rows == row_num - 1) {
                struct TableMetadata * realloc(struct TableMetadata * table_metadata, sizeof(struct TableMetadata) + (1000 * num_rows * 2));
                table_metadata->num_rows = table_metadata->num_rows * 2;
                printf("Allocated more rows")
                printf("%d\n", num_rows * 2);
            }
            char * current_column = strtok(row, ",");
            int col_num = 0;
            while (current_column != NULL) {
                //current_column = trim(current_column);
                printf("%s\n", current_column);
                (table_metadata->table_rows[row_num]).values[col_num] = current_column;
                current_column = strtok(NULL, ",");
                printf("%d\n", col_num);
                col_num++;
            }
            if (row_num == 0){
                table_metadata->num_columns = col_num;
            }
            printf("%d\n", row_num);
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
    free(table_to_clear);
    table_to_clear = NULL; 
    printf("Clearing table memory");
}

int main(void) {
    printf("Starting:\n");

    struct TableMetadata * table_metadata_pointer;
    clear_table_space(10, table_metadata_pointer);
    //set_table("../csv_files/Route_List.csv", table_metadata);
    clear_table(table_metadata_pointer);
}
