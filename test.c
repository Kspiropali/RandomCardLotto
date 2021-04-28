#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL 7 
#define RANGE 16

//int check()

int main()
{
    FILE *fp = fopen("Results.txt", "a");
    time_t clock;
    int random[RANGE], finalArr[TOTAL], userArr[TOTAL], matchArr[TOTAL], flag = 0;

    srand(time(&clock));

    printf("Enter TOTAL numbers between 1 and %d and without duplicates please:\n\n",RANGE);

    while(flag == 0 || flag == -1)
    {
        flag = 0;
        for(int i = 0; i <= TOTAL - 1;i++)
        {
            do
            {
                scanf("%d", &userArr[i]);
                if(userArr[i] < 1 || userArr[i] > RANGE)
                {
                    printf("Re-enter a number between 1 and RANGE:\n");
                }
            }while(userArr[i] < 1 || userArr[i] > RANGE);

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

    for (int i = 1; i < RANGE + 1; i++)
    {
        random[i-1] = i;
    }

    for (int i = 0; i < RANGE; i++)
    {
        int temp = random[i];
        int rIndex = rand() % RANGE;

        random[i] = random[rIndex];
        random[rIndex] = temp;
    }

    printf("\nLottery Numbers:\nDraw unsorted: ");
    for(int i=0; i <= TOTAL - 1;i++)
    {
        finalArr[i] = random[i];
        printf(" %d ",finalArr[i]);
    }

    for(int i = 0; i < TOTAL - 1; i++)
    {
        for(int j = 0; j < TOTAL - 1 - i; j++)
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
    for(int i=0; i <= TOTAL - 1;i++)
    {
        printf("   %d",finalArr[i]);
    }

    printf("\n\nUser's Numbers:\nDraw unsorted: ");
    for(int i=0; i <= TOTAL - 1;i++)
    {
        printf(" %d ",userArr[i]);
    }

    for(int i = 0;i < TOTAL - 1; i++)
    {
        for(int j = 0; j < TOTAL - 1 - i; j++)
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
    for(int i=0; i <= TOTAL - 1;i++)
    {
        printf("   %d",userArr[i]);
    }

    printf("\nMatching User's Numbers:\n");
    for(int i = 0; i <= TOTAL - 1; i++)
    {
        for(int j = 0; j <= TOTAL - 1; j++)
        {
            if(userArr[j] == finalArr[i])
            {
                matchArr[i] = finalArr[i];
                printf("%d  ",userArr[j]);
            }
        }
    }

    fwrite("\n\nDraw Sorted: ", RANGE, 1, fp);
    for(int i = 0;i <= TOTAL - 1;i++)
    {
        fprintf(fp,"  %d", finalArr[i]);
    }

    fwrite("\nUser's Sorted: ", RANGE, 1, fp);
    for(int i = 0;i <= TOTAL - 1;i++)
    {
        fprintf(fp,"  %d", userArr[i]);
    }

    fwrite("\nMatching numbers: ", 23, 1, fp);
    for(int i = 0;i <= TOTAL - 1;i++)
    {
        for(int j = 0; j <= TOTAL - 1; j++)
        {
            if(userArr[j] == finalArr[i])
            {
                fprintf(fp,"%d  ", matchArr[i]);
            }
        }
    }
    printf("\n");

    fclose(fp);

    return 0;
}