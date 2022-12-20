// extern void create_heder_file();
char prgName[20];                                                                       // program name
char st_name[20] = "student";                                                           // structur name
char alias_name[10] = "SLL";                                                            // alias name
char st_member[200] = "";                                                               // structure members
int no_of_members;                                                                      // number of structure member
char lookup_tabele[10][10] = {"int", "char", "float", "double", "char", "Date", "int"}; // preDefined Datatype
char member[10][100];                                                                   // structure members name
int types_member[10];                                                                   // structure members data type
const char format_specifier[7][3] = {"d", "c", "g", "lg", "s", "d", "d"};               // predefined formate specifire
char main_path[80];                                                                     // path for main file
char header_path[100];                                                                  // path for header file
int date_flag = 0;                                                                      // set on date type variable
char auto_inc_flag = 0;                                                                 // set on auto increment data type
int baseValue = 1;                                                                      // staring value of AUTO_INC_VAR