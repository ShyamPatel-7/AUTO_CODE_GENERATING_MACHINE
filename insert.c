#include "header.h"

void add_begin()
{
    int i;

    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//--------------------------------- Add Begin ---------------------------------\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fprintf(fp, "%s", "void add_begin(");
    fprintf(fp, "%s %s\n%s %s", alias_name, "**ptr)\n{\nint flag =0;\n", alias_name, "*new;\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, "%s%s%s", "new = malloc(sizeof(", alias_name, "));\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // Data scaning
    fprintf(fp, "%s", "printf(\"\\033[35mPlease Enter the Data\\n\");\n");
    // fprintf(fp, "%s", "scanf(\"");
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] == 5) // Date scanning
        {
            // printing
            fprintf(fp, "%s%s%s", "do\n{\nprintf(\"\\033[35mEnter the value of ", member[i], "(DD/MM/YYYY):- \\033[0m\");\n");
            fprintf(fp, "flag = ");
            // scanning Date
            fprintf(fp, "%s%s%s", "scanf(\" ", "%2d/%2d/%4d", "\",");

            fprintf(fp, "%s%s%s%s%s%s%s%s%s", "&new->", member[i], ".iidate,", "&new->", member[i], ".iimonth,", "&new->", member[i], ".iiyear");
            fprintf(fp, ");\n");

            // check for valid input
            fprintf(fp, "if (flag != 3)\nprintf(\"\\033[31mWrong Input\\033[0m\\n\");\n");

            // check for valid date
            fprintf(fp, "\nelse if(isValidDate(new->%s.iidate,new->%s.iimonth,new->%s.iiyear)==0)\n{\nprintf(\"\\033[31mInvalid Date\\033[0m\\n\");\nflag = 0;\n}\n", member[i], member[i], member[i]);
            // isValidDate( new->member[i].iidate, new->member[i].iimonth, new->member[i].iiyear);
            fprintf(fp, "scanf(\"%%*[^\\n]\");\n} while (flag != 3);\nflag = 0;\n");
        }
        else if (types_member[i] == 6)
        {
            fprintf(fp, "\nnew->%s = autoIncValue(ptr);", member[i]);
        }
        else
        {
            // printing
            fprintf(fp, "%s%s%s", "do\n{\nprintf(\"\\033[35mEnter the value of ", member[i], ":- \\033[0m\");\n");
            fprintf(fp, "flag = ");
            // scanning Data
            // if string
            if (strcmp(format_specifier[types_member[i]], "s") == 0)
                fprintf(fp, "%s%s%s", "scanf(\" ", "%14[^\\n]", "\",");
            else // else all other type data
                fprintf(fp, "%s%c%s%s", "scanf(\" ", '%', format_specifier[types_member[i]], "\",");

            // if datatype is string
            if (strcmp(format_specifier[types_member[i]], "s") == 0)
                fprintf(fp, "%s%s", "new->", member[i]);
            else
                fprintf(fp, "%s%s", "&new->", member[i]);
            fprintf(fp, ");\n");
            fprintf(fp, "if (flag != 1)\nprintf(\"\\033[31mWrong Input\\033[0m\\n\");\nscanf(\"%%*[^\\n]\");\n} while (flag != 1);\nflag = 0;\n");
        }
    }
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // fprintf(fp, "%s", " );\n");
    fprintf(fp, "%s", "new->next = *ptr;\n");
    fprintf(fp, "%s", "*ptr=new;\n}\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fclose(fp);
}

void add_end()
{
    int i;

    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "//--------------------------------- Add End -----------------------------------\n");
    fprintf(fp, "\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fprintf(fp, "%s", "void add_end(");
    fprintf(fp, "%s %s\n%s %s", alias_name, "**ptr)\n{\nint flag =0;\n", alias_name, "*last,*new;\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, "%s%s%s", "new = malloc(sizeof(", alias_name, "));\n");

    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // Data Scaning
    fprintf(fp, "%s", "printf(\"\\033[35mPlease Enter the Data\\n\");\n");
    // fprintf(fp, "%s", "scanf(\"");
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] == 5) // Date scanning
        {
            // printing
            fprintf(fp, "%s%s%s", "do\n{\nprintf(\"\\033[35mEnter the value of ", member[i], "(DD/MM/YYYY):- \\033[0m\");\n");
            fprintf(fp, "flag = ");
            // scanning Date
            fprintf(fp, "%s%s%s", "scanf(\" ", "%2d/%2d/%4d", "\",");

            fprintf(fp, "%s%s%s%s%s%s%s%s%s", "&new->", member[i], ".iidate,", "&new->", member[i], ".iimonth,", "&new->", member[i], ".iiyear");
            fprintf(fp, ");\n");

            // check for valid input
            fprintf(fp, "if (flag != 3)\nprintf(\"\\033[31mWrong Input\\033[0m\\n\");\n");

            // check for valid date
            fprintf(fp, "\nelse if(isValidDate(new->%s.iidate,new->%s.iimonth,new->%s.iiyear)==0)\n{\nprintf(\"\\033[31mInvalid Date\\033[0m\\n\");\nflag = 0;\n}\n", member[i], member[i], member[i]);
            // isValidDate( new->member[i].iidate, new->member[i].iimonth, new->member[i].iiyear);
            fprintf(fp, "scanf(\"%%*[^\\n]\");\n} while (flag != 3);\nflag = 0;\n");
        }
        else if (types_member[i] == 6)
        {
            fprintf(fp, "\nnew->%s = autoIncValue(ptr);", member[i]);
        }
        else
        { // printing
            fprintf(fp, "%s%s%s", "do\n{\nprintf(\"\\033[35mEnter the value of ", member[i], ":- \\033[0m\");\n");
            fprintf(fp, "flag = ");
            // scanning Data
            if (strcmp(format_specifier[types_member[i]], "s") == 0)
                fprintf(fp, "%s%s%s", "scanf(\" ", "%14[^\\n]", "\",");
            else
                fprintf(fp, "%s%c%s%s", "scanf(\" ", '%', format_specifier[types_member[i]], "\",");

            if (strcmp(format_specifier[types_member[i]], "s") == 0)
                fprintf(fp, "%s%s", "new->", member[i]);
            else
                fprintf(fp, "%s%s", "&new->", member[i]);
            fprintf(fp, ");\n");
            fprintf(fp, "if (flag != 1)\nprintf(\"\\033[31mWrong Input\\033[0m\\n\");\nscanf(\"%%*[^\\n]\");\n} while (flag != 1);\nflag = 0;\n");
        }
    }
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fprintf(fp, "%s", "new->next = 0;\n");
    fprintf(fp, "%s", "if(*ptr==0)\t// if no record present\n*ptr=new;\t// update headpter as new node\n");
    fprintf(fp, "else\t// if record present\n{\nlast=*ptr;\nwhile(last->next)\t// finding last node\nlast=last->next;\t// visit next node\nlast->next=new;\t// update last node next add as newly created node \n}");
    fprintf(fp, "%s", "\n}\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    fclose(fp);
}

void autoIncFun()
{
    int i;

    FILE *fp = fopen(main_path, "a");

    //---------------------------------------------------------------------------------------
    fprintf(fp, "//--------------------------------- Auto_Inc_Function -------------------------\n");
    fprintf(fp, "int autoIncValue(%s**ptr)\n{", alias_name);

    // if no data available return base value
    fprintf(fp, " if (*ptr == NULL)\n{\nreturn baseValue;\n}\n");

    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, " int i, j, c = count_node(*ptr);\n");
    // fprintf(fp, " int flag = 0, sort_flag = 0;\n");
    fprintf(fp, "%s *p1, *p2, temp;\n", alias_name);
    fprintf(fp, "p1 = p2 = *ptr;\n");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // sort logic
    // outer loop
    fprintf(fp, "for (i = 0; i < c-1; i++)\n{\np2 = p1->next;\n");
    // inner loop
    fprintf(fp, "for (j = i+1; j < c; j++)\n{\n");
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] == 6)
        {
            fprintf(fp, "if(p1->%s > p2->%s)\n", member[i], member[i]);
            fprintf(fp, "swapData(p1,p2);\n");
            break;
        }
    }
    fprintf(fp, "p2 = p2->next;\n}\n"); // inner loop over
    fprintf(fp, "p1 = p1->next;\n}\n"); // outer loop over
                                        // body End
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    fprintf(fp, "p1 = *ptr;\nint retValue = baseValue;\n");
    fprintf(fp, "while (p1->next)\n{\n");

    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] == 6)
        {
            fprintf(fp, "if(p1->%s == retValue)\n{\n", member[i]);
            fprintf(fp, "retValue++;\np1 = p1->next;\n}\n");
            break;
        }
    }

    fprintf(fp, "else\nreturn retValue;\n}\nreturn ++retValue;\n}\n");
    fclose(fp);
}
