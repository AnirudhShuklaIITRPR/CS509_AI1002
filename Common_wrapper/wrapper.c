#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

int main()
{
    int choice;

    while (1)
    {
        printf("\n=====================================\n");
        printf("CS509 COMMON WRAPPER\n");
        printf("=====================================\n");
        printf("1. Run Assignment 1 (GEMM)\n");
        printf("0. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                // Change current directory to GEMM
                if (_chdir("..\\Assignment_1\\GEMM") != 0)
                {
                    printf("Unable to open GEMM directory.\n");
                    break;
                }

                // Run GEMM
                system("gemm.exe");

                // Return to Common_wrapper directory
                _chdir("..\\..\\Common_wrapper");

                break;
            }

            case 0:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}