#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum grade_enum {
    V0,
    V1,
    V2,
    V3,
    5,
    6a,
    6a+,
    6b,
    6b+,
    E3,
    E4,
    E6
};

enum route_type_enum {
    bouldering,
    sport,
    trad
};

enum crag_faces{
    N,
    S,
    E,
    W
}

// no duplicate ids
// climber will be indexable, so you can use B trees on it, just to copy Psotgres, the other tables will just be arrays of structs
// 'When you create an index on a table, PostgreSQL creates a separate B-tree data structure that allows for faster data retrieval based on the indexed columns''
//
struct climber {
    int id // primary key 
    char * name
    char * email // check using regex before processing further
}

struct route_struct {
    char * route_name;
    char * crag_name
    double latitude 
    double longitude
    enum type type_of_route //enums are the size of ints
    enum grade grade_of_route //enums are the size of ints
    //climber * list_of_climbers
};

struct crag_struct {
    char * crag_name // primary key
    double latitude 
    double longitude
    enum crag_faces crag_face //enums are the size of ints
};

//-------------------------------------
//FIRST CLIMBERS AND ROUTES. LEAVE CRAGS TILL LATER 

struct climber_struct * set_climbers(char *filename){
    FILE * file_pointer = fopen(filename, "r");

    int max_str_field_length = 64; // max length of a string field is 64 characters

    int number_of_string_fields = 2;
    int number_of_int_or_enum_fields = 2;
    int number_of_double_fields = 2;

    int total_number_of_fields = 6
    
    char route[
        (max_str_field_length * number_of_string_fields) + 
        (sizeof int * number_of_int_or_enum_fields) +
        (sizeof double * number_of_double_fields)
    ];
    char route_name[max_str_field_length];
    char crag_name[max_str_field_length];

    struct route_struct * route_list;
    // B tree initialed here
    int row_num = 0;
    if (file_pointer != NULL) {
    }
}

struct route_struct * set_routes(char *filename){
    FILE * file_pointer = fopen(filename, "r");

    int max_str_field_length = 64; // max length of a string field is 64 characters

    int number_of_string_fields = 2;
    int number_of_int_or_enum_fields = 2;
    int number_of_double_fields = 2;

    int total_number_of_fields = 6;

    struct route_struct * route_list;
    // B tree initialed here
    int row_num = 0;
    if (file_pointer != NULL) {
        // ok, we are gonna malloc every 10 lines, I don't think mallocing every line is sensible 
        // allocate memory chunk for the route here to use the heap 
        char route[
            (max_str_field_length * number_of_string_fields) + 
            (sizeof int * number_of_int_or_enum_fields) +
            (sizeof double * number_of_double_fields)
        ];
        char route_name[max_str_field_length];
        char crag_name[max_str_field_length];

        while (fgets(route, sizeof route, file_pointer) != NULL) {
            
            // remove white space from line here ?
            const char * column_names[]  = {"route_name", "crag_name", "latitude", "longitude", "type_of_route", "grade_of_route"};
            char * current_column = strtok(route, ",");

            int i = 0;
            while (current_column != NULL) {
                // if (i > total_number_of_fields){
                //      ConsoleLog.Error("too many values in the row %d", row_num)
                //}
                if (column_names[i] == "route_name"){
                    route_list[row_num].route_name = current_column;
                } else if (column_names[i] == "crag_name") {
                    route_list[row_num].crag_name = current_column;
                } else if (column_names[i] == "latitude") {
                    route_list[row_num].latitude = current_column;
                } else if (column_names[i] == "longitude") {
                    route_list[row_num].longitude = current_column;
                } else if (column_names[i] == "type_of_route") {
                    route_list[row_num].type_of_route = current_column;
                } else if (column_names[i] == "grade_of_route") {
                    route_list[row_num].grade_of_route = current_column;
                }
                printf(current_column);
                printf(",");
                current_column = strtok(NULL, ",");
                i++;
            }
            printf("\n");
            row_num ++;
        }
        
    }
    else {
        printf("Unable to open file!");
    }
    fclose(file_pointer);
    return route_list;
}

char * trim(char * string_to_trim){
    // trim start 
    while(isspace(char * string_at_start)) {
        string_at_start++;
    }
    // trim end
    end = string_to_trim + strlen(string_to_trim) - 1;
    while(end > string_at_start && isspace((unsigned char)*end)) {
        end--;
    }
    // Write new null terminator character
    end[1] = '\0';
    return str
}

int main(void)
{
    struct route_struct * route_list_final = set_routes("route_list.txt");
    size_t num_items = 64/ sizeof(route_list_final);
    printf("%d", sizeof(route_list_final));
    printf("%d", num_items);

    //struct climber_struct * climber_list_final = set_routes("climbing_list.txt");
   
}
