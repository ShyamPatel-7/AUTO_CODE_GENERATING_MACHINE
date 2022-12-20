#include "header.h"

void sort_data()
{
    int i;
    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n///-------------------------------- SORT DATA ---------------------------------\n");
    fprintf(fp, "void sort_data(%s**ptr)\n{\n", alias_name);
    //---------------------------------------------------------------------------------------
    // if condition for null data
    fprintf(fp, "if (*ptr == NULL)\n{\nprintf(\"\\033[33mNo Record found\\n\\033[0m\");\nreturn;\n}\n");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, " int i, j, c = count_node(*ptr);\n");
    fprintf(fp, " int flag = 0, sort_flag = 0;\n");
    fprintf(fp, "%s *p1, *p2, temp;\n", alias_name);
    fprintf(fp, "p1 = p2 = *ptr;\n");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // body
    // select sorting data field
    fprintf(fp, "printf(\"\\033[33mAccroding to which data field you want sort your Data\\033[0m\\n\");");
    fprintf(fp, "printf(\"");
    for (i = 0; i < no_of_members; i++)
    {
        fprintf(fp, "%d) %s\\n", i + 1, member[i]);
    }
    fprintf(fp, "\");\n");
    fprintf(fp, "printf(\"\\033[34mEnter your choice: \\033[0m\");\n");
    fprintf(fp, "scanf(\"%%d\", &flag);\n");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // check option is in range or not
    fprintf(fp, "if(flag<1||flag>%d)\n{printf(\"\\033[31mWrong Input\\033[0m\\n\");\nreturn;\n}\n", no_of_members);
    fprintf(fp, "flag--;\n");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------

    // sort logic
    // outer loop
    fprintf(fp, "for (i = 0; i < c-1; i++)\n{\np2 = p1->next;\n");
    // inner loop
    fprintf(fp, "for (j = i+1; j < c; j++)\n{\n");
    for (i = 0; i < no_of_members; i++)
    {
        if (i == 0)
        {
            fprintf(fp, "if(flag==0)\n{\n");
            if (types_member[i] == 4)
                fprintf(fp, "if(strcmp(p1->%s,p2->%s)>0)\nsort_flag=1;\n}\n", member[i], member[i]);
            else if (types_member[i] == 5)
                fprintf(fp, "sort_flag = (int)shortByDate(p1->%s,p2->%s);\n}\n", member[i], member[i]);
            else
                fprintf(fp, "if(p1->%s>p2->%s)\nsort_flag=1;\n}\n", member[i], member[i]);
        }
        else
        {
            fprintf(fp, "else if(flag==%d)\n{\n", i);
            if (types_member[i] == 4)
                fprintf(fp, "if(strcmp(p1->%s,p2->%s)>0)\nsort_flag=1;\n}\n", member[i], member[i]);
            else if (types_member[i] == 5)
                fprintf(fp, "sort_flag = (int)shortByDate(p1->%s,p2->%s);\n}\n", member[i], member[i]);
            else
                fprintf(fp, "if(p1->%s>p2->%s)\nsort_flag=1;\n}\n", member[i], member[i]);
        }
    }
    // last else condirtion
    fprintf(fp, "else\nsort_flag = 0;\n\n");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // // swap logic
    // // if start
    fprintf(fp, "if(sort_flag)\n{\n");
    fprintf(fp, "swapData(p1,p2);\n");
    // // if start
    // fprintf(fp, "if(sort_flag)\n{\n");
    // for (i = 0; i < no_of_members; i++)
    // {
    //     if (types_member[i] == 4)
    //     {
    //         fprintf(fp, "strcpy(temp.%s,p1->%s);\n", member[i], member[i]);
    //     }
    //     else
    //     {
    //         fprintf(fp, "temp.%s=p1->%s;\n", member[i], member[i]);
    //     }
    // }
    // fprintf(fp, "\n");
    // for (i = 0; i < no_of_members; i++)
    // {
    //     if (types_member[i] == 4)
    //     {
    //         fprintf(fp, "strcpy(p1->%s,p2->%s);\n", member[i], member[i]);
    //     }
    //     else
    //     {
    //         fprintf(fp, "p1->%s=p2->%s;\n", member[i], member[i]);
    //     }
    // }
    // fprintf(fp, "\n");
    // for (i = 0; i < no_of_members; i++)
    // {
    //     if (types_member[i] == 4)
    //     {
    //         fprintf(fp, "strcpy(p2->%s,temp.%s);\n", member[i], member[i]);
    //     }
    //     else
    //     {
    //         fprintf(fp, "p2->%s=temp.%s;\n", member[i], member[i]);
    //     }
    // }

    fprintf(fp, "sort_flag = 0;\n}\n"); // if end
    //---------------------------------------------------------------------------------------

    fprintf(fp, "p2 = p2->next;\n}\n");    // inner loop over
    fprintf(fp, "p1 = p1->next;\n}\n}\n"); // outer loop over
    // body End
    fclose(fp);
}

void swapLogic()
{
    int i;
    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//--------------------------------- SWAP LOGIC --------------------------------\n");
    fprintf(fp, "void swapData(%s *p1, %s *p2)\n{\n", alias_name, alias_name);
    // swap logic
    //-----------------------------------------------------------------------------
    // varialbe declaration
    fprintf(fp, "%s temp;\n",alias_name);

    // swap logic
    //-----------------------------------------------------------------------------
    // to store data into tem variable
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] == 4)
        {
            fprintf(fp, "strcpy(temp.%s,p1->%s);\n", member[i], member[i]);
        }
        else
        {
            fprintf(fp, "temp.%s=p1->%s;\n", member[i], member[i]);
        }
    }
    //-----------------------------------------------------------------------------

    fprintf(fp, "\n");

    //-----------------------------------------------------------------------------
    // to  swap data p2 to p1
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] == 4)
        {
            fprintf(fp, "strcpy(p1->%s,p2->%s);\n", member[i], member[i]);
        }
        else
        {
            fprintf(fp, "p1->%s=p2->%s;\n", member[i], member[i]);
        }
    }
    //-----------------------------------------------------------------------------

    fprintf(fp, "\n");

    //-----------------------------------------------------------------------------
    // restore data from temp to p2
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] == 4)
        {
            fprintf(fp, "strcpy(p2->%s,temp.%s);\n", member[i], member[i]);
        }
        else
        {
            fprintf(fp, "p2->%s=temp.%s;\n", member[i], member[i]);
        }
    }
    //-----------------------------------------------------------------------------
    fprintf(fp, "\n}\n");
    fclose(fp);
}

