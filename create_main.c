#include "header.h"
void create_main()
{
    // printf(" \n\n main file = %s\n\n", prgName);
    FILE *fp = fopen(main_path, "w");
    fprintf(fp, "%s", "#include\"/home/sp/DS_Project/new_program/header.h\"\n");
    //---------------------------------------------------------------------------------------
    if (date_flag == 1)
    {
        fprintf(fp, "char isValidDate(int d, int m, int y);\n");
        fprintf(fp, "char shortByDate(Date d1, Date d2);\n\n");
    }
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    if (auto_inc_flag == 1)
        fprintf(fp, "int autoIncValue(%s **ptr);\n", alias_name);
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fprintf(fp, "\nint baseValue = %d;\n", baseValue);
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fprintf(fp, "void main(){\n system(\"clear\");\nint op, c = 0,x=0;\n");
    fprintf(fp, "%s *headptr = 0;\n\nwhile (1){\n", alias_name);
    fprintf(fp, "%s", "printf(\"\\033[32m---------------------------------------------------\\033[0m\\n\");\n");
    fprintf(fp, "%s", "printf(\"\\t\\t\\033[32mEnter your option\\n\");\n");
    fprintf(fp, "%s", "printf(\"---------------------------------------------------\\n\");\n");
    // fprintf(fp, "%s", "printf(\"1)Add_begin\\t2)Add_end\\t3)Print_Data\\n4)Reverse_print\\t5)Save_file\\t6)Read_file\\n7)Delete_all\\t8)Delete_node\\t9)Delete_pos\\n10)Reverse_data\\t11)Sort_data\\t12)Search_data\\n13)Reverse_link\\t14)Count_node\\t15)Exit\\n\");");
    fprintf(fp, "%s", "printf(\"1)Add_begin\\t2)Add_end\\t3)Print_Data\\n4)Reverse_print\\t5)Save_file\\t6)Read_file\\n7)Delete_all\\t8)Delete_node\\t9)Delete_pos\\n10)Sort_data\\t11)Search_data\\t12)Reverse_link\\n13)Count_node\\t14)Exit\\n\");");
    fprintf(fp, "%s", "\nprintf(\"---------------------------------------------------\\n\");");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    //scan option
    fprintf(fp, "%s", "\n	do{printf(\"Input : \");x = scanf(\"%d\", &op);scanf(\"%*[^\\n]\");if (x != 1)printf(\"\\033[31mWrong Input\\033[0m\\n\");} while (x != 1);\nsystem(\"clear\");\n");
    // fprintf(fp, "%s", "\nswitch (op)\n{\ncase 1:add_begin(&headptr);\nbreak;\ncase 2:add_end(&headptr);\nbreak;\ncase 3:print_data(headptr);\nbreak;\ncase 4:reverse_print(headptr);\nbreak;\ncase 5:save_file(headptr);\nbreak;\ncase 6:read_file(&headptr);\nbreak;\ncase 7:delete_all(&headptr);\nbreak;\n/*\ncase 8:delete_node(&headptr);\nbreak;\n*/\ncase 9:delete_pos(&headptr);\nbreak;\ncase 10:reverse_data(&headptr);\nbreak;\ncase 11:sort_data(&headptr);\nbreak;\n/*\ncase 12:search_data(headptr);\nbreak;\n*/\ncase 13:reverse_link(&headptr);\nbreak;\ncase 14:c = count_node(headptr);printf(\"\\033[33mTotal node is %d\\033[0m\\n\", c);\nbreak;\ncase 15:exit(0);\ndefault:printf(\"Unknown Option\\n\");\n}");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // switch case
    fprintf(fp, "%s", "\nswitch (op)\n{\ncase 1:add_begin(&headptr);\nbreak;\ncase 2:add_end(&headptr);\nbreak;\ncase 3:print_data(headptr);\nbreak;\ncase 4:reverse_print(headptr);\nbreak;\ncase 5:save_file(headptr);\nbreak;\ncase 6:read_file(&headptr);\nbreak;\ncase 7:delete_all(&headptr);\nbreak;\ncase 8:delete_node(&headptr);\nbreak;\ncase 9:delete_pos(&headptr);\nbreak;\ncase 10:sort_data(&headptr);\nbreak;\ncase 11:search_data(headptr);\nbreak;\ncase 12:reverse_link(&headptr);\nbreak;\ncase 13:c = count_node(headptr);printf(\"\\033[33mTotal node is %d\\033[0m\\n\", c);\nbreak;\ncase 14:exit(0);\ndefault:printf(\"Unknown Option\\n\");\n}");
    fprintf(fp, "%s", "\n}\n}");
    //---------------------------------------------------------------------------------------
    fclose(fp);

    //---------------------------------------------------------------------------------------
    printf("\nGenerating program for Insert Data...");
    add_begin();
    add_end();
    if (auto_inc_flag == 1)
        autoIncFun();
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    printf("Generating program to Print Data...");
    print_data();
    reverse_print();
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    printf("Generating program to Save Data...");
    save_file();
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    printf("Generating program for Read Data...");
    read_file();
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    printf("Generating program to Delete Data...");
    delete_all();
    delete_pos();
    delete_node(); //yet to implement
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // no need to implement
    //  printf("Generating program to Reverse Data...");
    //  reverse_data();
    //  sleep(1);
    //  printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    printf("Generating program to Reverse Link...");
    reverse_link();
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    printf("Generating program to Sort Data...");
    sort_data();
    swapLogic();
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    printf("Generating program to Search Data...");
    search_data(); // yet to implement
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    printf("Generating program to Count Node...");
    count_node();
    if (date_flag == 1)
    {
        validDateFun();
        sortByDate();
    }
    sleep(1);
    printf("\033[32mSuccess\033[0m\n");
    //---------------------------------------------------------------------------------------
}