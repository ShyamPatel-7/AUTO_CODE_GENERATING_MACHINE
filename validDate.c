#include "header.h"
void validDateFun()
{
    char *validDateCode = "\nchar isLeap(int year)\n{\n	// Return true if year\n	// is a multiple of 4 and\n	// not multiple of 100.\n	// OR year is multiple of 400.\nreturn (((year % 4 == 0) &&(year % 100 != 0)) ||(year % 400 == 0));\n}\n\n// Returns true if given\n// year is valid or not.\nchar isValidDate(int d, int m, int y)\n{\nconst int MAX_VALID_YR = 9999;\nconst int MIN_VALID_YR = 1800;\n	// If year, month and day\n	// are not in given range\n	if (y > MAX_VALID_YR ||	y < MIN_VALID_YR)\n	return 0;\n	if (m < 1 || m > 12)\nreturn 0;\n	if (d < 1 || d > 31)\nreturn 0;\n\n	// Handle February month\n	// with leap year\n	if (m == 2)\n{\nif (isLeap(y))\nreturn (d <= 29);\n	else\nreturn (d <= 28);\n}\n\n	// Months of April, June,\n	// Sept and Nov must have\n	// number of days less than\n	// or equal to 30.\n	if (m == 4 || m == 6 ||	m == 9 || m == 11)\n return (d <= 30);\n\n	return 1;\n}\n\n";

    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//-------------------------- CHECK FOR VALID DATE --------------------------\n");
    fprintf(fp, "%s", validDateCode);
    fclose(fp);
}

void sortByDate()
{
    char *sortByDateCode= "\nchar shortByDate(Date d1, Date d2)\n{\nif (d1.iiyear > d2.iiyear)\n {\nreturn 1;\n}\nelse if (d1.iiyear == d2.iiyear && d1.iimonth > d2.iimonth)\n{\nreturn 1;\n}\nelse if (d1.iiyear == d2.iiyear && d1.iimonth == d2.iimonth && d1.iidate > d2.iidate)\n{\nreturn 1;\n}\nreturn 0;\n}\n";
    
    FILE *fp = fopen(main_path, "a");
    fprintf(fp, "\n//------------------------------ SORT BY DATE -------------------------------\n");
    fprintf(fp, "%s", sortByDateCode);
    fclose(fp);
}
