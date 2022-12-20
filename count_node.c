#include "header.h"

void count_node()
{
    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//--------------------------------- COUNT NODE --------------------------------\n");
    //---------------------------------------------------------------------------------------
    fprintf(fp, "int count_node(%s *ptr)\n{\nint cnt=0;\nwhile(ptr)\n{\ncnt++;\nptr=ptr->next;\n}\nreturn cnt;\n}\n", alias_name);
    //---------------------------------------------------------------------------------------
}

