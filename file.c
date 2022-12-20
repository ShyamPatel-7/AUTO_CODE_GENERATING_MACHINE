#include "header.h"

void save_file()
{
    int i;
    const char *print_str2 = "*ptr)\n{\nif (ptr == NULL)\n{\nprintf(\"\\n\\033[33mNo Record found to SAVE\\n\\n\\033[0m\");\nreturn;\n}\nFILE *fp;\nfp = fopen(\"database.csv\", \"w\");\n";

    FILE *fp = fopen(main_path, "a");
    //---------------------------------------------------------------------------------------
    fprintf(fp, "\n//--------------------------------- SAVE FILE ---------------------------------\n");
    fprintf(fp, "%s", "void save_file(");
    fprintf(fp, "%s %s", alias_name, print_str2);
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // logic for fprintf(fp, "id,name,marks,\n");
    fprintf(fp, "fprintf(fp,\"");
    for (i = 0; i < no_of_members; i++)
    {
        fprintf(fp, "%s,", member[i]);
    }
    fprintf(fp, "%s", "\\n\");");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // fprintf(fp, "\nwhile (ptr)\n{\nfprintf(fp,\"");
    // // forma t_specifiers
    // for (i = 0; i < no_of_members; i++)
    // {
    //     fprintf(fp, "%c%s%c", '%', format_specifier[types_member[i]], ',');
    // }
    // fprintf(fp, "%s", "\\n\"");
    // // variable name
    // for (i = 0; i < no_of_members; i++)
    // {
    //     // if (format_specifier[types_member[i]] == 's')
    //     fprintf(fp, "%s%s", ",ptr->", member[i]);
    // }
    // fprintf(fp, "%s", " );\n");

    //
    //
    //---------------------------------------------------------------------------------------
    // while loop for save all data
    fprintf(fp, "%s", "\nwhile (ptr)\n	{\nfprintf(fp,\"");
    //---------------------------------------------------------------------------------------
    // forma t_specifiers
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] != 5)
        {
            if (strcmp(format_specifier[types_member[i]], "s") == 0)
                fprintf(fp, "%s%s%c", "%", format_specifier[types_member[i]], ',');
            else
                fprintf(fp, "%s%s%c", "%", format_specifier[types_member[i]], ',');
        }
        else
        {
            fprintf(fp, "%%d/%%d/%%d,");
        }
    }
    fprintf(fp, "%s", "\\n\"");
    //---------------------------------------------------------------------------------------
    // variable name
    for (i = 0; i < no_of_members; i++)
    {
        // if (format_specifier[types_member[i]] == 's')
        if (types_member[i] != 5)
            fprintf(fp, "%s%s", ",ptr->", member[i]);
        else
            fprintf(fp, "%s%s%s%s%s%s%s%s%s", ",ptr->", member[i], ".iidate", ",ptr->", member[i], ".iimonth", ",ptr->", member[i], ".iiyear");
    }
    fprintf(fp, "%s", " );\n");
    fprintf(fp, "%s", "ptr = ptr->next;\n");
    fprintf(fp, "%s", "\n}\n");
    //---------------------------------------------------------------------------------------

    //---------------------------------------------------------------------------------------
    // fprintf(fp, "%s", "ptr = ptr->next;\n");
    // fprintf(fp, "%s", "\n}\nprintf(\"\\n\\033[33mData Saved Successfully\\n\\n\\033[0m\");\n");
    fprintf(fp, "%s", "\nprintf(\"\\n\\033[33mData Saved Successfully\\n\\n\\033[0m\");\n");
    fprintf(fp, "%s", "fclose(fp);\n}\n");
    //---------------------------------------------------------------------------------------
    fclose(fp);
}
//
//
void read_file()
{
    int i;
    const char *print_str2 = "**ptr)\n{\nFILE *fp;\nfp = fopen(\"database.csv\", \"r\");\nif (fp == NULL)\n{\nprintf(\"\\n\\033[33mDatabase Not Found\\n\\n\\033[0m\");\nreturn;\n}\n";

    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//--------------------------------- READ FILE ---------------------------------\n");
    //---------------------------------------------------------------------------------------
    fprintf(fp, "%s", "void read_file(");
    fprintf(fp, "%s %s", alias_name, print_str2);
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // variables
    fprintf(fp, "%s%s", alias_name, " *new, *last;\n");
    //---------------------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------------------
    // logic for  fscanf(fp, "%*[^,],%*[^,],%*[^\n]");
    fprintf(fp, "fscanf(fp, \"");
    for (i = 0; i < no_of_members; i++)
    {
        if ((i + 1) == no_of_members) // if last record
            fprintf(fp, "%s", "%*[^,]");
        else
            fprintf(fp, "%s", "%*[^,],");
    }
    fprintf(fp, ",\\n\");\n");
    //---------------------------------------------------------------------------------------
//
    //---------------------------------------------------------------------------------------
    //add End
    fprintf(fp, "%s%s%s", "do\n{\nnew=malloc(sizeof(", alias_name, "));\n");
    fprintf(fp, "fscanf(fp, \"");
    //---------------------------------------------------------------------------------------
    //formate specifire
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] != 5)
        {
            if (strcmp(format_specifier[types_member[i]], "s") == 0)
                fprintf(fp, "%c%s%s", '%', "[^,]", ",");
            else
                fprintf(fp, "%c%s%s", '%', format_specifier[types_member[i]], ",");
        }
        else
        {
            fprintf(fp, "%%2d/%%2d/%%4d,");
        }
    }
    fprintf(fp, "\\n\"");
    //---------------------------------------------------------------------------------------
    // variable name
    for (i = 0; i < no_of_members; i++)
    {
        if (types_member[i] != 5)
        {
            if (strcmp(format_specifier[types_member[i]], "s") == 0)
                fprintf(fp, "%s%s", ",new->", member[i]);
            else
                fprintf(fp, "%s%s", ",&new->", member[i]);
        }
        else
            fprintf(fp, "%s%s%s%s%s%s%s%s%s", ",&new->", member[i], ".iidate", ",&new->", member[i], ".iimonth", ",&new->", member[i], ".iiyear");
    }
    fprintf(fp, ");\n\n");
    //---------------------------------------------------------------------------------------
    fprintf(fp, "new->next = 0;\nif (*ptr == 0)\n*ptr = new;\nelse\n{\nlast = *ptr;\nwhile(last->next)\nlast = last->next;\nlast->next = new;\n}\n}while (!feof(fp));\nprintf(\"\\n\\033[34mData Read sucesfully\\n\\033[0m\");\nfclose(fp);\n}");
    //---------------------------------------------------------------------------------------
}
