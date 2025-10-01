#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct route_struct {
    char * route_name;
    char * grade;
};

//typedef struct route_struct;

struct route_struct * get_routes(char *filename){
    FILE * file_pointer = fopen(filename, "r");

    int max_field_length = 64; // max length of a field is 64 characters
    int route_row_length = 2; // we have two fields at the moment

    char route[max_field_length * route_row_length];
    char route_name[max_field_length];
    char grade[max_field_length];

    struct route_struct * route_list;
    int row_num = 0;
    if (file_pointer != NULL) {
        while (fgets(route, sizeof route, file_pointer) != NULL) {
            const char * column_names[]  = {"route_name", "grade"};
            char * current_column = strtok(route, ",");

            int i = 0;
            while (current_column != NULL) {
                if (column_names[i] == "route_name"){
                    route_list[row_num].route_name = current_column;
                } else if (column_names[i] == "grade") {
                    route_list[row_num].grade = current_column;
                }
                current_column = strtok(NULL, ",");
                i++;
            }
        }
        row_num ++;
    }
    else {
        printf("Unable to open file!");
    }
    fclose(file_pointer);
    return route_list;
}

struct route_struct * linear_search(struct route_struct* routes, size_t size, const char* route_to_find) {
    for (size_t i=0; i<size; i++) {
        if (strcmp(routes[i].route_name, route_to_find) == 0) {
            return &routes[i];
        }
    }
    return NULL;
}

int main(void)
{
    struct route_struct * route_list_final = get_routes("route_list.txt");
    size_t num_items = 64/ sizeof(route_list_final);
    printf("%d", sizeof(route_list_final));
    printf("%d", num_items);
    //struct route_struct * found = linear_search( route_list_final, num_items, "Integrity");
    //if (!found) {
     //   printf("Search failed");
    //    return 1;
    //}
    //printf("linear_search: value of 'Integrity' is %s\n", *found->route_name);
    //return 0;
}
