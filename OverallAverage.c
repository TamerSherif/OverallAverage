#include <stdio.h>
#include <stdlib.h>

int main()
{
    int id[256];
    float homework[256];
    float lab[256];
    float midterm[256];
    float finalm[256];
    float mark[256];
    int count = 0;

    FILE *a;
    FILE *b;
    char string [100];
    a = fopen("input.txt", "r");
    if(a == NULL)
        return -1;



    fscanf(a,"%s %s %s %s %s", string, string, string, string, string);

    while (!feof(a))
    {
        fscanf(a, "%d %f\t%f\t%f\t%f", &id[count], &homework[count], &lab[count], &midterm[count], &finalm[count]);

        if(midterm[count]<finalm[count])
        {
                midterm[count]=finalm[count];
        }

        mark[count] = (0.1*homework[count])+(0.2*lab[count])+(0.3*midterm[count])+(0.4*finalm[count]);

        count++;
    }

    b = fopen("outputFile.txt", "w");
    if(b == NULL)
        return -1;

    fprintf(b,"%s\t\t%s\t%s\t%s\t\t%s\t\t%s","ID","homework","lab","midterm","final","overall average\n");
    int  i = 0;
    while (i < count)
    {

        fprintf(b,"xxx%04d\t\t%.1f\t\t%.1f\t  %.1f\t\t%.1f\t\t%.1f\n",id[i]%10000,homework[i],lab[i],midterm[i],finalm[i],mark[i]);
        i++;

    }

    return 0;
}
