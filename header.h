#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// variables
extern char prgName[20];                  // program name
extern char st_name[20];                  // structur name
extern char alias_name[10];               // alias name
extern char st_member[100];               // structure members
extern int no_of_members;                 // number of structure member
extern char lookup_tabele[10][10];        // preDefined Datatype
extern char member[10][100];              // structure members name
extern int types_member[10];              // structure members data type
extern const char format_specifier[7][3]; // predefined formate specifire
extern char main_path[80];                // main file path
extern char header_path[100];             // header file path
extern int date_flag;                     // set on date type variable
extern char auto_inc_flag;                // set on auto increment data type
extern int baseValue;                 // staring value of AUTO_INC_VAR

// functions
extern void create_main();
// insert.c
extern void add_begin();
extern void add_end();
extern void autoIncFun();
// print.c
extern void print_data();
extern void reverse_print();
// file.c
extern void save_file();
extern void read_file();
// delete.c
extern void delete_all();
extern void delete_pos();
extern void delete_node();
// reverse.c
extern void reverse_data();
extern void reverse_link();
// sort data
extern void sort_data();
extern void swapLogic();
//search Data
extern void  search_data();
// count_node.c
extern void count_node();

// valid Date Code
extern void validDateFun();
extern void sortByDate();

void create_sll();
void create_dll();
void create_heder_file();
void create_struct();
void create_struct_member();