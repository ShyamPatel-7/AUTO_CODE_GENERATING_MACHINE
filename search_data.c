#include "header.h"
void search_data()
{
    int i, j, k;
    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//--------------------------------- SEARCH DATA -------------------------------\n");
    fprintf(fp, "void search_data(%s *ptr)\n{\n", alias_name);
    //---------------------------------------------------------------------------------------
    // if condition for null data
    fprintf(fp, "if (ptr == NULL)\n{\nprintf(\"\\033[33mNo Record found\\n\\033[0m\");\nreturn;\n}\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, " int flag = 0,x=0;\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // body
    // select searching data field
    fprintf(fp, "printf(\"\\033[33mAccroding to which data field you want Search your Data\\033[0m\\n\");");
    fprintf(fp, "printf(\"");
    for (i = 0; i < no_of_members; i++)
    {
        fprintf(fp, "%d) %s\\n", i + 1, member[i]);
    }
    fprintf(fp, "\");\n");

    fprintf(fp, "do	\n{\nprintf(\"\\033[34mEnter your choice: \\033[0m\");\nx = scanf(\"%%d\", &flag);\nif (x != 1)\nprintf(\"\\033[31mInvalid Data\\033[0m\\n\");\nscanf(\"%%*[^\\n]\");\n} while (x != 1);\n");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // check option is in range or not
    fprintf(fp, "if(flag<1||flag>%d)\n{printf(\"\\033[31mWrong Input\\033[0m\\n\");\nreturn;\n}\n", no_of_members);
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // delcare variable for comparation
    int temp = 0;
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] == 0 || types_member[i] == 1 || types_member[i] == 2 || types_member[i] == 3 || types_member[i] == 6)
            fprintf(fp, "%s %s;\n", lookup_tabele[types_member[i]], member[i]);
        else if (types_member[i] == 4)
        {
            fprintf(fp, "%s %s[15] = {0};\n", lookup_tabele[types_member[i]], member[i]);
        }
        else if (types_member[i] == 5 && temp == 0)
        {
            fprintf(fp, "int date, month, year;\n");
            temp = 1;
        }
    }
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------

    // Search logic
    for (i = 0; i < no_of_members; i++)
    {
        if (i == 0)
        {
            if (types_member[i] == 5) // Date scanning
            {
                fprintf(fp, "if(flag == 1)\n{\n");
                fprintf(fp, "char temp = 0;\n");

                //---------------------------------------------------------------------------------------
                // printing
                // do while start
                fprintf(fp, "do\n{\nprintf(\"\\033[35mEnter the  %s%s", member[i], "(DD/MM/YYYY):- \\033[0m\");\n");
                fprintf(fp, "x = ");
                // scanning Date
                fprintf(fp, "%s%s%s", "scanf(\" ", "%2d/%2d/%4d", "\",");

                fprintf(fp, " &date, &month, &year");
                fprintf(fp, ");\n");

                // check for valid input
                fprintf(fp, "if (x != 3)\nprintf(\"\\033[31mWrong Input\\033[0m\\n\");\n");

                // check for valid date
                fprintf(fp, "\nelse if(isValidDate(date, month, year) == 0)\n{\nprintf(\"\\033[31mInvalid Date\\033[0m\\n\");\nx = 0;\n}\n");
                fprintf(fp, "scanf(\"%%*[^\\n]\");\n} while (x != 3);\nflag = 0;\n");
                // do while end
                //---------------------------------------------------------------------------------------

                //---------------------------------------------------------------------------------------
                // while loop to print data
                fprintf(fp, "while(ptr)\n{\nif(ptr->%s.iiyear == year && ptr->%s.iimonth == month && ptr->%s.iidate == date)\n{", member[i], member[i], member[i]);
                fprintf(fp, "if(temp == 0){");

                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");

                // print %-15s
                fprintf(fp, "printf(\"");

                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "%s", "%-15s");
                fprintf(fp, "%s", "\\n\"");

                // variable name
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, ",\"%s\"", member[j]);
                fprintf(fp, "%s", " );\n");

                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");

                fprintf(fp, "temp = 1;\n}\n");

                //---------------------------------------------------------------------------------------
                // printing Data
                fprintf(fp, "%s", "\nprintf(\"\\033[33m");
                // forma t_specifiers
                for (j = 0; j < no_of_members; j++)
                {
                    if (types_member[j] != 5)
                    {
                        if (strcmp(format_specifier[types_member[j]], "s") == 0)
                            fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
                        else
                            fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
                    }
                    else
                    {
                        fprintf(fp, "%%02d/%%02d/%%-9d");
                    }
                }
                fprintf(fp, "%s", "\\n\"");
                // variable name
                for (j = 0; j < no_of_members; j++)
                {
                    // if (format_specifier[types_member[i]] == 's')
                    if (types_member[j] != 5)
                        fprintf(fp, "%s%s", ",ptr->", member[j]);
                    else
                        fprintf(fp, "%s%s%s%s%s%s%s%s%s", ",ptr->", member[j], ".iidate", ",ptr->", member[j], ".iimonth", ",ptr->", member[j], ".iiyear");
                }
                fprintf(fp, "%s", " );}ptr = ptr->next;\n}\n");

                fprintf(fp, "if(temp == 1)\n");
                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");
                fprintf(fp, "else\n");
                fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

                fprintf(fp, "}\n");
            }
            else
            {
                fprintf(fp, "if(flag==%d)\n{\n", i + 1);
                fprintf(fp, "char temp = 0;\n");
                fprintf(fp, "do\n{\nprintf(\"\\033[35mEnter the  %s%s", member[i], ":- \\033[0m\");\n");
                fprintf(fp, "x = ");
                // printing
                // do while start

                if (strcmp(format_specifier[types_member[i]], "s") == 0)
                    fprintf(fp, "%s%s%s", "scanf(\" ", "%14[^\\n]", "\",");
                else // else all other type data
                    fprintf(fp, "%s%c%s%s", "scanf(\" ", '%', format_specifier[types_member[i]], "\",");

                // if datatype is string
                if (strcmp(format_specifier[types_member[i]], "s") == 0)
                    fprintf(fp, "%s", member[i]);
                else
                    fprintf(fp, "%s%s", "&", member[i]);
                fprintf(fp, ");\n");
                fprintf(fp, "if (x != 1)\nprintf(\"\\033[31mInvalid DATA\\033[0m\\n\");\nscanf(\"%%*[^\\n]\");\n} while (x != 1);\n");
                // do while end

                //---------------------------------------------------------------------------------------
                if (strcmp(format_specifier[types_member[i]], "s") == 0)
                    fprintf(fp, "while(ptr)\n{\nif(strcmp(ptr->%s,%s)==0)\n{", member[i], member[i]);
                else
                    fprintf(fp, "while(ptr)\n{\nif(ptr->%s==%s)\n{", member[i], member[i]);

                fprintf(fp, "if(temp == 0){");

                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");

                // print %-15s
                fprintf(fp, "printf(\"");

                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "%s", "%-15s");
                fprintf(fp, "%s", "\\n\"");

                // variable name
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, ",\"%s\"", member[j]);
                fprintf(fp, "%s", " );\n");

                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");

                fprintf(fp, "temp = 1;\n}\n");

                //---------------------------------------------------------------------------------------
                // printing Data
                fprintf(fp, "%s", "\nprintf(\"\\033[33m");
                // forma t_specifiers
                for (j = 0; j < no_of_members; j++)
                {
                    if (types_member[j] != 5)
                    {
                        if (strcmp(format_specifier[types_member[j]], "s") == 0)
                            fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
                        else
                            fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
                    }
                    else
                    {
                        fprintf(fp, "%%2d/%%2d/%%-9d");
                    }
                }
                fprintf(fp, "%s", "\\n\"");
                // variable name
                for (j = 0; j < no_of_members; j++)
                {
                    // if (format_specifier[types_member[i]] == 's')
                    if (types_member[j] != 5)
                        fprintf(fp, "%s%s", ",ptr->", member[j]);
                    else
                        fprintf(fp, "%s%s%s%s%s%s%s%s%s", ",ptr->", member[j], ".iidate", ",ptr->", member[j], ".iimonth", ",ptr->", member[j], ".iiyear");
                }
                fprintf(fp, "%s", " );}ptr = ptr->next;\n}\n");

                fprintf(fp, "if(temp == 1)\n");
                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");
                fprintf(fp, "else\n");
                fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

                fprintf(fp, "}\n");
            }
        }

        else
        {
            if (types_member[i] == 5) // Date scanning
            {
                fprintf(fp, "else if(flag==%d)\n{\n", i + 1);
                fprintf(fp, "char temp = 0;\n");

                //---------------------------------------------------------------------------------------
                // printing
                // do while start
                fprintf(fp, "do\n{\nprintf(\"\\033[35mEnter the  %s%s", member[i], "(DD/MM/YYYY):- \\033[0m\");\n");
                fprintf(fp, "x = ");
                // scanning Date
                fprintf(fp, "%s%s%s", "scanf(\" ", "%2d/%2d/%4d", "\",");

                fprintf(fp, " &date, &month, &year");
                fprintf(fp, ");\n");

                // check for valid input
                fprintf(fp, "if (x != 3)\nprintf(\"\\033[31mWrong Input\\033[0m\\n\");\n");

                // check for valid date
                fprintf(fp, "\nelse if(isValidDate(date, month, year) == 0)\n{\nprintf(\"\\033[31mInvalid Date\\033[0m\\n\");\nx = 0;\n}\n");
                fprintf(fp, "scanf(\"%%*[^\\n]\");\n} while (x != 3);\nflag = 0;\n");
                // do while end
                //---------------------------------------------------------------------------------------

                //---------------------------------------------------------------------------------------
                // while loop to print data
                fprintf(fp, "while(ptr)\n{\nif(ptr->%s.iiyear == year && ptr->%s.iimonth == month && ptr->%s.iidate == date)\n{", member[i], member[i], member[i]);
                fprintf(fp, "if(temp == 0){");

                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");

                // print %-15s
                fprintf(fp, "printf(\"");

                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "%s", "%-15s");
                fprintf(fp, "%s", "\\n\"");

                // variable name
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, ",\"%s\"", member[j]);
                fprintf(fp, "%s", " );\n");

                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");

                fprintf(fp, "temp = 1;\n}\n");

                //---------------------------------------------------------------------------------------
                // printing Data
                fprintf(fp, "%s", "\nprintf(\"\\033[33m");
                // forma t_specifiers
                for (j = 0; j < no_of_members; j++)
                {
                    if (types_member[j] != 5)
                    {
                        if (strcmp(format_specifier[types_member[j]], "s") == 0)
                            fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
                        else
                            fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
                    }
                    else
                    {
                        fprintf(fp, "%%2d/%%2d/%%-9d");
                    }
                }
                fprintf(fp, "%s", "\\n\"");
                // variable name
                for (j = 0; j < no_of_members; j++)
                {
                    // if (format_specifier[types_member[i]] == 's')
                    if (types_member[j] != 5)
                        fprintf(fp, "%s%s", ",ptr->", member[j]);
                    else
                        fprintf(fp, "%s%s%s%s%s%s%s%s%s", ",ptr->", member[j], ".iidate", ",ptr->", member[j], ".iimonth", ",ptr->", member[j], ".iiyear");
                }
                fprintf(fp, "%s", " );}ptr = ptr->next;\n}\n");

                fprintf(fp, "if(temp == 1)\n");
                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");
                fprintf(fp, "else\n");
                fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

                fprintf(fp, "}\n");
            }
            else
            {
                fprintf(fp, "else if(flag==%d)\n{\n", i + 1);
                fprintf(fp, "char temp = 0;\n");
                fprintf(fp, "do\n{\nprintf(\"\\033[35mEnter the  %s%s", member[i], ":- \\033[0m\");\n");
                fprintf(fp, "x = ");
                // printing
                // do while start

                if (strcmp(format_specifier[types_member[i]], "s") == 0)
                    fprintf(fp, "%s%s%s", "scanf(\" ", "%14[^\\n]", "\",");
                else // else all other type data
                    fprintf(fp, "%s%c%s%s", "scanf(\" ", '%', format_specifier[types_member[i]], "\",");

                // if datatype is string
                if (strcmp(format_specifier[types_member[i]], "s") == 0)
                    fprintf(fp, "%s", member[i]);
                else
                    fprintf(fp, "%s%s", "&", member[i]);
                fprintf(fp, ");\n");
                fprintf(fp, "if (x != 1)\nprintf(\"\\033[31mInvalid DATA\\033[0m\\n\");\nscanf(\"%%*[^\\n]\");\n} while (x != 1);\n");
                // do while end

                //---------------------------------------------------------------------------------------
                if (strcmp(format_specifier[types_member[i]], "s") == 0)
                    fprintf(fp, "while(ptr)\n{\nif(strcmp(ptr->%s,%s)==0)\n{", member[i], member[i]);
                else
                    fprintf(fp, "while(ptr)\n{\nif(ptr->%s==%s)\n{", member[i], member[i]);

                fprintf(fp, "if(temp == 0){");

                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");

                // print %-15s
                fprintf(fp, "printf(\"");

                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "%s", "%-15s");
                fprintf(fp, "%s", "\\n\"");

                // variable name
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, ",\"%s\"", member[j]);
                fprintf(fp, "%s", " );\n");

                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");

                fprintf(fp, "temp = 1;\n}\n");

                //---------------------------------------------------------------------------------------
                // printing Data
                fprintf(fp, "%s", "\nprintf(\"\\033[33m");
                // forma t_specifiers
                for (j = 0; j < no_of_members; j++)
                {
                    if (types_member[j] != 5)
                    {
                        if (strcmp(format_specifier[types_member[j]], "s") == 0)
                            fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
                        else
                            fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
                    }
                    else
                    {
                        fprintf(fp, "%%2d/%%2d/%%-9d");
                    }
                }
                fprintf(fp, "%s", "\\n\"");
                // variable name
                for (j = 0; j < no_of_members; j++)
                {
                    // if (format_specifier[types_member[i]] == 's')
                    if (types_member[j] != 5)
                        fprintf(fp, "%s%s", ",ptr->", member[j]);
                    else
                        fprintf(fp, "%s%s%s%s%s%s%s%s%s", ",ptr->", member[j], ".iidate", ",ptr->", member[j], ".iimonth", ",ptr->", member[j], ".iiyear");
                }
                fprintf(fp, "%s", " );}ptr = ptr->next;\n}\n");

                fprintf(fp, "if(temp == 1)\n");
                // print dot line
                fprintf(fp, "\nprintf(\"\\033[33m");
                for (j = 0; j < no_of_members; j++)
                    fprintf(fp, "---------------");
                fprintf(fp, "\\033[0m\\n\");\n");
                fprintf(fp, "else\n");
                fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

                fprintf(fp, "}\n");
            }

            // fprintf(fp, "else if(flag==%d)\n{\n", i + 1);
            // fprintf(fp, "char temp = 0;\n");
            // fprintf(fp, "do\n{\nprintf(\"\\033[35mEnter the  %s%s", member[i], ":- \\033[0m\");\n");
            // fprintf(fp, "x = ");
            // // printing
            // // do while start

            // if (strcmp(format_specifier[types_member[i]], "s") == 0)
            //     fprintf(fp, "%s%s%s", "scanf(\" ", "%14[^\\n]", "\",");
            // else // else all other type data
            //     fprintf(fp, "%s%c%s%s", "scanf(\" ", '%', format_specifier[types_member[i]], "\",");

            // // if datatype is string
            // if (strcmp(format_specifier[types_member[i]], "s") == 0)
            //     fprintf(fp, "%s", member[i]);
            // else
            //     fprintf(fp, "%s%s", "&", member[i]);
            // fprintf(fp, ");\n");
            // fprintf(fp, "if (x != 1)\nprintf(\"\\033[31mInvalid DATA\\033[0m\\n\");\nscanf(\"%%*[^\\n]\");\n} while (x != 1);\n");
            // // do while end

            // //---------------------------------------------------------------------------------------
            // if (strcmp(format_specifier[types_member[i]], "s") == 0)
            //     fprintf(fp, "while(ptr)\n{\nif(strcmp(ptr->%s,%s)==0)\n{", member[i], member[i]);
            // else
            //     fprintf(fp, "while(ptr)\n{\nif(ptr->%s==%s)\n{", member[i], member[i]);

            // fprintf(fp, "if(temp == 0){");

            // // print dot line
            // fprintf(fp, "\nprintf(\"\\033[33m");
            // for (j = 0; j < no_of_members; j++)
            //     fprintf(fp, "---------------");
            // fprintf(fp, "\\033[0m\\n\");\n");

            // // print %-15s
            // fprintf(fp, "printf(\"");

            // for (j = 0; j < no_of_members; j++)
            //     fprintf(fp, "%s", "%-15s");
            // fprintf(fp, "%s", "\\n\"");

            // // variable name
            // for (j = 0; j < no_of_members; j++)
            //     fprintf(fp, ",\"%s\"", member[j]);
            // fprintf(fp, "%s", " );\n");

            // // print dot line
            // fprintf(fp, "\nprintf(\"\\033[33m");
            // for (j = 0; j < no_of_members; j++)
            //     fprintf(fp, "---------------");
            // fprintf(fp, "\\033[0m\\n\");\n");

            // fprintf(fp, "temp = 1;\n}\n");

            // //---------------------------------------------------------------------------------------
            // // printing Data
            // fprintf(fp, "%s", "\nprintf(\"\\033[33m");
            // // forma t_specifiers
            // for (j = 0; j < no_of_members; j++)
            // {
            //     if (types_member[j] != 5)
            //     {
            //         if (strcmp(format_specifier[types_member[j]], "s") == 0)
            //             fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
            //         else
            //             fprintf(fp, "%s%s", "%-15", format_specifier[types_member[j]]);
            //     }
            //     else
            //     {
            //         fprintf(fp, "%%2d/%%2d/%%-9d");
            //     }
            // }
            // fprintf(fp, "%s", "\\n\"");
            // // variable name
            // for (j = 0; j < no_of_members; j++)
            // {
            //     // if (format_specifier[types_member[i]] == 's')
            //     if (types_member[j] != 5)
            //         fprintf(fp, "%s%s", ",ptr->", member[j]);
            //     else
            //         fprintf(fp, "%s%s%s%s%s%s%s%s%s", ",ptr->", member[j], ".iidate", ",ptr->", member[j], ".iimonth", ",ptr->", member[j], ".iiyear");
            // }
            // fprintf(fp, "%s", " );}ptr = ptr->next;\n}\n");

            // fprintf(fp, "if(temp == 1)\n");
            // // print dot line
            // fprintf(fp, "\nprintf(\"\\033[33m");
            // for (j = 0; j < no_of_members; j++)
            //     fprintf(fp, "---------------");
            // fprintf(fp, "\\033[0m\\n\");\n");
            // fprintf(fp, "else\n");
            // fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

            // fprintf(fp, "}\n");
        }
    }
    // last else condirtion
    // fprintf(fp, "else\nsort_flag = 0;\n\n");
    //---------------------------------------------------------------------------------------

    fprintf(fp, "\n}\n");
    fclose(fp);
}