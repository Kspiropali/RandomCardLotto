#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fp = fopen("Results.txt", "a");
    time_t clock;
    int random[16], finalArr[7], userArr[7], matchArr[7], flag = 0;

    srand(time(&clock));

    printf("Enter 7 numbers between 1 and 16 and without duplicates please:\n\n");

    while(flag == 0 || flag == -1)
    {
        flag = 0;
        for(int i = 0; i <= 6;i++)
        {
            do
            {
                scanf("%d", &userArr[i]);
                if(userArr[i] < 1 || userArr[i] > 16)
                {
                    printf("Re-enter a number between 1 and 16:\n");
                }
            }while(userArr[i] < 1 || userArr[i] > 16);

            if(i==1 && userArr[0] == userArr[1])
            {
                flag = -1;
                system("clear");
                printf("Duplicate found; start over please\n\n");
                break;
            }
            else if(i==2 && (userArr[0] == userArr[2] || userArr[1] == userArr[2]))
            {
                flag = -1;
                system("clear");
                printf("Duplicate found; start over please\n\n");
                break;
            }
            else if(i==3 && (userArr[0] == userArr[3] || userArr[1] == userArr[3] || userArr[2] == userArr[3]))
            {
                flag = -1;
                system("clear");
                printf("Duplicate found; start over please\n\n");
                break;
            }
            else if(i==4 && (userArr[0] == userArr[4] || userArr[1] == userArr[4] || userArr[2] == userArr[4] || userArr[3] == userArr[4]))
            {
                flag = -1;
                system("clear");
                printf("Duplicate found; start over please\n\n");
                break;
            }
            else if(i==5 && (userArr[0] == userArr[5] || userArr[1] == userArr[5] || userArr[2] == userArr[5] || userArr[3] == userArr[5] || userArr[4] == userArr[5]))
            {
                flag = -1;
                system("clear");
                printf("Duplicate found; start over please\n\n");
                break;
            }
            else if(i==6 && (userArr[0] == userArr[6] || userArr[1] == userArr[6] || userArr[2] == userArr[6] || userArr[3] == userArr[6] || userArr[4] == userArr[6] || userArr[5] == userArr[6]))
            {
                flag = -1;
                system("clear");
                printf("Duplicate found; start over please\n\n");
                break;
            }
            printf("Number %d is accepted!\n",userArr[i]);
        }

        if (flag != -1)
        {
            flag = 1;
        }
    }

    for (int i = 1; i < 17; i++)
    {
        random[i-1] = i;
    }

    for (int i = 0; i < 16; i++)
    {
        int temp = random[i];
        int rIndex = rand() % 16;

        random[i] = random[rIndex];
        random[rIndex] = temp;
    }

    printf("\nLottery Numbers:\nDraw unsorted: ");
    for(int i=0; i<=6;i++)
    {
        finalArr[i] = random[i];
        printf(" %d ",finalArr[i]);
    }

    for(int i = 0;i < 6; i++)
    {
        for(int j = 0; j < 6 - i; j++)
        {
            if(finalArr[j] > finalArr[j+1])
            {
                int temp = finalArr[j];
                finalArr[j] = finalArr[j + 1];
                finalArr[j+1] = temp;
            }
        }
    }

    printf("\nDraw sorted: ");
    for(int i=0; i<=6;i++)
    {
        printf("   %d",finalArr[i]);
    }

    printf("\n\nUser's Numbers:\nDraw unsorted: ");
    for(int i=0; i<=6;i++)
    {
        printf(" %d ",userArr[i]);
    }

    for(int i = 0;i < 6; i++)
    {
        for(int j = 0; j < 6 - i; j++)
        {
            if(userArr[j] > userArr[j+1])
            {
                int temp = userArr[j];
                userArr[j] = userArr[j + 1];
                userArr[j+1] = temp;
            }
        }
    }

    printf("\nDraw sorted: ");
    for(int i=0; i<=6;i++)
    {
        printf("   %d",userArr[i]);
    }

    printf("\nMatching User's Numbers:\n");
    for(int i = 0; i <= 6; i++)
    {
        for(int j = 0; j <= 6; j++)
        {
            if(userArr[j] == finalArr[i])
            {
                matchArr[i] = finalArr[i];
                printf("%d  ",userArr[j]);
            }
        }
    }

    fwrite("\n\nDraw Sorted: ", 16, 1, fp);
    for(int i = 0;i <= 6;i++)
    {
        fprintf(fp,"  %d", finalArr[i]);
    }

    fwrite("\nUser's Sorted: ", 16, 1, fp);
    for(int i = 0;i <= 6;i++)
    {
        fprintf(fp,"  %d", userArr[i]);
    }

    fwrite("\nMatching numbers: ", 23, 1, fp);
    for(int i = 0;i <= 6;i++)
    {
        for(int j = 0; j <= 6; j++)
        {
            if(userArr[j] == finalArr[i])
            {
                fprintf(fp,"%d", matchArr[i]);
            }
        }
    }

    fclose(fp);
    
    return 0;
}
