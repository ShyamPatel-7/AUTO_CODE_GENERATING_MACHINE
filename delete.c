#include "header.h"

void delete_all()
{

    int i;
    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//--------------------------------- DELETE ALL --------------------------------\n");
    //---------------------------------------------------------------------------------------
    fprintf(fp, "%s", "void delete_all(");
    fprintf(fp, "%s ", alias_name);
    fprintf(fp, "**ptr)\n{\n	if (*ptr == NULL)\n{\nprintf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");\nreturn;\n}\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, "%s *del;\n", alias_name);
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // delete all data
    fprintf(fp, "del = *ptr;\nwhile (del)\n{\n*ptr = del->next;\nfree(del);\ndel = *ptr;\n}\nprintf(\"\\n\\033[33mAll Data Deleted\\n\\033[0m\\n\");\n}\n");
    //---------------------------------------------------------------------------------------
}

void delete_pos()
{

    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//--------------------------------- DELETE POSITION ---------------------------\n");
    //---------------------------------------------------------------------------------------
    fprintf(fp, "void delete_pos(");
    fprintf(fp, "%s **ptr)\n{\n", alias_name);
    fprintf(fp, "if(*ptr == NULL)\n{\nprintf(\"\\n\\033[31mNo Record found\\n\\n\\033[0m\");\nreturn;\n}\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, "%s *node, *prev;\nint pos, i = 1, c = count_node(*ptr);", alias_name);
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // scan position and validation
    fprintf(fp, "printf(\"Enter the Position : \");\nscanf(\"%%d\",&pos);\n");
    fprintf(fp, "if (pos > c)\n{\nprintf(\"\\033[31mNo Record found\\n\\033[0m\");\nreturn;\n}\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // find Node
    fprintf(fp, " prev = node = *ptr;");
    fprintf(fp, " while (i < pos)\n{\nprev = node;\nnode = node->next;\ni++;\n}\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // delete Node
    fprintf(fp, "if (node == *ptr)\n{\n*ptr = (*ptr)->next;\nfree(prev);\n}\nelse\n{\nprev->next = node->next;\nfree(node);\n}\n");
    fprintf(fp, "printf(\"\\033[33mData Deleted Succesfully\\n\\n\\033[0m\");");
    //---------------------------------------------------------------------------------------
    fprintf(fp, "\n}\n");
}

void delete_node()
{
    int i, j, k;
    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//--------------------------------- DELETE NODE -------------------------------\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fprintf(fp, "void delete_node(");
    fprintf(fp, "%s **ptr)\n{\n", alias_name);
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // check for data availability
    fprintf(fp, "if(*ptr == NULL)\n{\nprintf(\"\\n\\033[31mNo Record found\\n\\n\\033[0m\");\nreturn;\n}\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, " int flag = 0,x=0,delete_flag = 0;\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // body
    // select delete data field
    fprintf(fp, "printf(\"\\033[33mAccroding to which data field you want DELETE a Data\\033[0m\\n\");");
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
    //
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
    // extra variables
    fprintf(fp, "\n%s *del, *temp1, *temp = *ptr;\n", alias_name);
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // Delete logic
    for (i = 0; i < no_of_members; i++)
    {
        if (i == 0)
        {
            if (types_member[i] == 5) // Date scanning
            {
                fprintf(fp, "if(flag == 1)\n{\n");
                // fprintf(fp, "char temp = 0;\n");

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
                fprintf(fp, "while(temp)\n{\nif(temp->%s.iiyear == year && temp->%s.iimonth == month && temp->%s.iidate == date)\n{\ndelete_flag=1;\nbreak;}\ntemp1 = temp;\ntemp = temp->next;\n}\n", member[i], member[i], member[i]);

                // fprintf(fp, "if(delete_flag == 1)\n");
                // fprintf(fp, "printf(\"\\033[33m");
                // fprintf(fp, "Data Deleted Succefully");
                // fprintf(fp, "\\033[0m\\n\");\n");
                // fprintf(fp, "else\n");
                // fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

                fprintf(fp, "}\n");
            }
            else
            {
                fprintf(fp, "if(flag==%d)\n{\n", i + 1);
                // fprintf(fp, "char temp = 0;\n");
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
                    fprintf(fp, "while(temp)\n{\nif(strcmp(temp->%s,%s)==0)\n{\ndelete_flag=1;\nbreak;}\ntemp1 = temp;\ntemp = temp->next;\n}\n", member[i], member[i]);
                else
                    fprintf(fp, "while(temp)\n{\nif(temp->%s==%s)\n{\ndelete_flag=1;\nbreak;}\ntemp1 = temp;\ntemp = temp->next;\n}\n", member[i], member[i]);

                // fprintf(fp, "if(delete_flag == 1)\n");
                // fprintf(fp, "printf(\"\\033[33m");
                // fprintf(fp, "Data Delete Succefully");
                // fprintf(fp, "\\033[0m\\n\");\n");
                // fprintf(fp, "else\n");
                // fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

                fprintf(fp, "}\n");
            }
        }
        else
        {
            if (types_member[i] == 5) // Date scanning
            {
                fprintf(fp, "else if(flag==%d)\n{\n", i + 1);
                // fprintf(fp, "char temp = 0;\n");

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
                fprintf(fp, "while(temp)\n{\nif(temp->%s.iiyear == year && temp->%s.iimonth == month && temp->%s.iidate == date)\n{\ndelete_flag=1;\nbreak;}\ntemp1 = temp;\ntemp = temp->next;\n}\n", member[i], member[i], member[i]);

                // fprintf(fp, "if(delete_flag == 1)\n");
                // fprintf(fp, "printf(\"\\033[33m");
                // fprintf(fp, "Data Delete Succefully");
                // fprintf(fp, "\\033[0m\\n\");\n");
                // fprintf(fp, "else\n");
                // fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

                fprintf(fp, "}\n");
            }
            else
            {
                fprintf(fp, "else if(flag==%d)\n{\n", i + 1);
                // fprintf(fp, "char temp = 0;\n");
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
                    fprintf(fp, "while(temp)\n{\nif(strcmp(temp->%s,%s)==0)\n{\ndelete_flag=1;\nbreak;}\ntemp1 = temp;\ntemp = temp->next;\n}\n", member[i], member[i]);
                else
                    fprintf(fp, "while(temp)\n{\nif(temp->%s==%s)\n{\ndelete_flag=1;\nbreak;}\ntemp1 = temp;\ntemp = temp->next;\n}\n", member[i], member[i]);

                // fprintf(fp, "if(delete_flag == 1)\n");
                // fprintf(fp, "printf(\"\\033[33m");
                // fprintf(fp, "Data Delete Succefully");
                // fprintf(fp, "\\033[0m\\n\");\n");
                // fprintf(fp, "else\n");
                // fprintf(fp, "printf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");");

                fprintf(fp, "}\n");
            }
        }
    }
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // delete logoc
    fprintf(fp, "if (delete_flag == 1)\n{\nif (temp == *ptr)\n	{\n*ptr = (*ptr)->next;\nfree(temp);\n}\nelse\n{\ntemp1->next = temp->next;\nfree(temp);\n}\nprintf(\"\\033[33mData Delete Succefully\\n\\033[0m\\n\");\n}\nelse\nprintf(\"\\n\\033[33mNo Record found\\n\\n\\033[0m\");\n\nreturn;\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fprintf(fp, "\n}\n");
}
