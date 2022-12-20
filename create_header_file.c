#include "header.h"
// #include"variable.h"
char keywords[37][10] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "int",
    "long",
    "register",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while",
    "Date",
    "iidate",
    "iimonth",
    "iiyear",
};

void create_heder_file()
{
    FILE *header_fp;
    header_fp = fopen(header_path, "w");
    fprintf(header_fp, "%s", "#include<stdio.h>\n#include<string.h>\n#include<stdlib.h>\n");
    fclose(header_fp);
    create_struct();
    return;
}

void create_struct()
{
    char j;
    char str[200] = "", tempstr[100];
stname:
    // printf("\033[34mEnter Structure Name :- \033[0m%s\n", st_name);
    printf("\033[34mEnter Structure Name :- \033[0m");
    scanf(" %s", st_name);
    for (j = 0; j < 36; j++)
    {
        if (strcmp(st_name, keywords[j]) == 0)
        {
            printf("%s is reversed keyword plese enter some thing eles...\n", st_name);
            goto stname;
        }
    }
aliasname:
    // printf("\033[34mEnter Structure Alias Name :-\033[0m %s\n", alias_name);
    printf("\033[34mEnter Structure Alias Name :-\033[0m");
    scanf(" %s", alias_name);

    for (j = 0; j < 32; j++)
    {
        if (strcmp(alias_name, keywords[j]) == 0)
        {
            printf("%s is reversed keyword plese enter some thing eles...\n", alias_name);
            goto aliasname;
        }
    }
    create_struct_member(st_member);
    FILE *header_fp;
    header_fp = fopen(header_path, "a");
    fprintf(header_fp, "%s%s%s%s%s%s%s%s%s%s", "typedef struct ", st_name, "{\n", st_member, "struct ", st_name, " *next;\n", "\n}", alias_name, ";\n");
    // insert Data
    fprintf(header_fp, "void add_begin(%s **);\n", alias_name);
    fprintf(header_fp, "void add_end(%s **);\n", alias_name);

    // print data
    fprintf(header_fp, "void print_data(%s *);\n", alias_name);
    fprintf(header_fp, "void reverse_print(%s *);\n", alias_name);

    // read/write file
    fprintf(header_fp, "void save_file(%s *);\n", alias_name);
    fprintf(header_fp, "void read_file(%s **);\n", alias_name);

    // delete Data
    fprintf(header_fp, "void delete_all(%s **);\n", alias_name);

    // fprintf(header_fp,"void reverse_print(%s **);\n",alias_name);
    fprintf(header_fp, "void delete_pos(%s **);\n", alias_name);
    fprintf(header_fp, "void delete_node(%s **);\n", alias_name);

    // reverse Data
    fprintf(header_fp, "void reverse_data(%s **);\n", alias_name);

    // sort and swap Data
    fprintf(header_fp, "void sort_data(%s **);\n", alias_name);
    fprintf(header_fp, "void swapData(%s *p1, %s *p2);\n", alias_name, alias_name);

    // search data
    fprintf(header_fp, "void search_data(%s *);\n", alias_name);

    // Reverse Link
    fprintf(header_fp, "void reverse_link(%s **);\n", alias_name);

    // Count Nodeb
    fprintf(header_fp, "int count_node(%s *);\n", alias_name);

    fclose(header_fp);
}
void create_struct_member(char *str)
{
    int i, j, data_type;
    char status;
    // char spcial_char[][1]={'!','@','#','$','%','^','&','*','(','),'-','[',']',';',':',',','.','<','>','?','/','|','\'};
    char tempstr[200];
    char keywords[37][10] = {
        "auto",
        "break",
        "case",
        "char",
        "const",
        "continue",
        "default",
        "do",
        "double",
        "else",
        "enum",
        "extern",
        "float",
        "for",
        "goto",
        "if",
        "int",
        "long",
        "register",
        "return",
        "short",
        "signed",
        "sizeof",
        "static",
        "struct",
        "switch",
        "typedef",
        "union",
        "unsigned",
        "void",
        "volatile",
        "while",
        "Date",
        "iidate",
        "iimonth",
        "iiyear",
    };
L1:
    // selecting numbers of member required for structure
    printf("\n\033[34mHow many Data you rquired(Less then 10) :- \033[0m");
    scanf(" %d", &no_of_members);
    // no_of_members should be with in condition(1<=no_of_members<=10)
    if (no_of_members < 1 || no_of_members > 10)
    {
        printf("\n\033[31mInvalid Number\n");
        printf("You want to try again(y/n):- \033[0m");
        scanf("%*[^\n]"); // make flush out
        scanf(" %c", &status);

        if (status == 'Y' || status == 'y')
        {
            goto L1;
        }
        else
        {
            printf("\033[31mProgram Termineted\n\033[0m");
            exit(0);
        }
    }
    // scannning members name and datatypes
    for (i = 0; i < no_of_members; i++)
    {
    L3:
        printf("\n\033[33mEnter fileld-%d name :- \033[0m", i + 1);
        scanf("%s", member[i]);
        for (j = 0; j < 36; j++)
        {
            if (strcmp(member[i], keywords[j]) == 0)
            {
                printf("%s is reversed keyword plese enter some thing eles...\n", member[i]);
                goto L3;
            }
        }
        if ((member[i][0] >= 'a' && member[i][0] <= 'z') || (member[i][0] >= 'A' && member[i][0] <= 'Z') || member[i][0] == '_')
        {
        L2:
            // printf("\nSelect Data type: \n");

            int x;
            do
            {
                printf("\n\t\033[32m1) INTEGER\n\t2) CHARACTER\n\t3) FLOAT\n\t4) DOUBLE\n\t5) STRING\n\t6) DATE\n\t7) AUTO INC INT\n");
                printf("\nSelect Data type: \033[0m");
                x = scanf("%d", &data_type);
                if (x != 1)
                    printf("\033[31mWrong Input\033[0m\n");

                else if (data_type == 7 && auto_inc_flag == 1)
                {
                    printf("\033[31mYou can not use AUTO_INC_INT more then one time.\033[0m\n");
                    x = 0;
                }
                scanf("%*[^\n]");
            } while (x != 1);
            if (data_type == 6)
            {
                date_flag = 1;
            }
            if (data_type == 7)
            {
                x = 0;
                do
                {
                    printf("Enter Starting Value : ");
                    x = scanf("%d",&baseValue);
                    auto_inc_flag = 1;
                } while (x != 1);
            }
            if (data_type < 1 || data_type > 7)
            {
                printf("\033[31mInvalid Number\nPlease try again...\033[0m\n");
                goto L2;
            }
            if (data_type == 5)
                printf("\033[35mSTRING length should set 14 by default\n\033[0m");
            types_member[i] = data_type - 1;
            if (data_type == 5)
                // strcat(member[i], "[10]");
                sprintf(tempstr, "%s %s%s%c\n", lookup_tabele[data_type - 1], member[i], "[15]", ';');
            else
                sprintf(tempstr, "%s %s%c\n", lookup_tabele[data_type - 1], member[i], ';');
            printf("%s", tempstr);
            strcat(str, tempstr);
        }
        else
        {
            printf("1.Not a valid variable Name \n");
            printf("2.They must begin with a letter.\n");
            printf("3.Maximum length of variable is 31 characters in ANSI standard. But, first eight characters are significant by many compilers.\n");
            printf("4.Upper and lowercase characters are different. For example: total, TOTAL, Total are 3 different variables.\n");
            printf("5.The variable is not to be a keyword.\n");
            printf("6.White space is not allowed.\n");
            goto L3;
        }
    }
    if (date_flag == 1)
    {
        FILE *header_fp;
        header_fp = fopen(header_path, "a");
        fprintf(header_fp, "typedef struct Date\n{\nint iidate;\nint iimonth;\nint iiyear;\n}Date;\n");
        fclose(header_fp);
    }
    // printf("prgName = %s\n\n", prgName);
}
