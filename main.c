#include "header.h"

#define path "/home/sp/DS_Project/new_program"
#define path_exe "/home/sp/DS_Project/run_file"

void create_dir(void);
void create_exe_dir(void);

void main()
{
    system("clear");
    int mainopt, x;
    printf("Welcome to auto generate program...\n");
    while (1)
    {
        sleep(2);
        system("clear");
        do
        {
            printf("\033[31mPlease Select an Option\n\033[0m");
            printf("------------------------\n");
            printf("\033[32m1)Single Linked List\n2)Double linked List\n3)Exit\n\033[0m");
            printf("\033[34mInput : \033[0m");
            x = scanf("%d", &mainopt);
            if (x == 0)
                printf("\033[31mWrong Input\033[0m\n");
            scanf("%*[^\n]");
        } while (x == 0);
        printf("\033[0m");
        switch (mainopt)
        {
        case 1:
            create_sll();
            break;
        case 2:
            create_dll();
            break;
        case 3:
            exit(0);
        default:
            printf("\033[31mUnknown Option\n\033[0m");
            break;
        }
    }
}
void create_dll()
{
    printf("\033[33mThis Feature not available\n\n\033[0m");
    exit(0);
}
void create_sll()
{
    char prgName[20];
    // printf("\033[34mEnter the Program Name :-\033[0m new_main.c\n");
    printf("\033[34mEnter the Program Name :- \033[0m");
    scanf("%s", prgName);
    //  char m_path[100];
    create_dir();
    sprintf(main_path, "%s/%s", path, prgName);
    sprintf(header_path, "%s/%s", path, "header.h");
    FILE *header_fp;
    header_fp = fopen(main_path, "w");
    fprintf(header_fp, "%s", "#include<stdio.h>\n#include<string.h>\n#include<stdlib.h>\n");
    fclose(header_fp);

    // create header file
    create_heder_file();

    // create main c source file
    create_main();

    // create executable file
    // create_exe_dir();
    system("cc /home/sp/DS_Project/new_program/main.c -o /home/sp/DS_Project/new_program/exe");

    printf("\033[33mSLL Program created Successfully\n\n\033[0m");
    exit(0);
}

void create_dir(void)
{

    int x = mkdir(path, 0777);
    // printf("x = %d\n",x);
    if (x == -1)
    {
        char cmd[50] = {0};
        sprintf(cmd, "rm -rf %s", path);
        system(cmd);
        // rmdir(path);
        x = mkdir(path, 0777);
        // printf("x = %d\n",x);
    }
}

void create_exe_dir(void)
{

    int x = mkdir(path_exe, 0777);
    // printf("x = %d\n",x);
    if (x == -1)
    {
        char cmd[50] = {0};
        sprintf(cmd, "rm -rf %s", path_exe);
        system(cmd);
        x = mkdir(path_exe, 0777);
    }
    char cmd[200] = {0};

    // sprintf(cmd, "cc %s -o ", main_path);
    // strcat(cmd, path_exe);
    // strcat(cmd, "/xyz");

    // printf("\n%s\n", cmd);
    printf("\n%s\n", "cc /home/sp/DS_Project/new_program/main.c -o /home/sp/DS_Project/new_program/exe");
    // system( "cc /home/sp/DS_Project/new_program/main.c -o /home/sp/DS_Project/new_program/exe");
}