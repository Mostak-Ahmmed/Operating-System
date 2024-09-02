#include<stdio.h>

struct Process
{
    int id, Bt, Pr, Wt, TAt;

} P[20], temp;

int main()
{
    int i, j, n;
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        P[i].id = i + 1;
        printf("\nEnter burst time of Process %d: ", P[i].id);
        scanf("%d", &P[i].Bt);
        printf("Enter priority of Process %d: ", P[i].id);
        scanf("%d", &P[i].Pr);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (P[j].Pr > P[j + 1].Pr)
            {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    P[0].Wt = 0;
    P[0].TAt = P[0].Bt;
    for (i = 1; i < n; i++)
    {
        P[i].Wt = P[i - 1].TAt;
        P[i].TAt = P[i].Bt + P[i].Wt;
    }

    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    printf("___________\t__________\t________\t____________\t________________\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", P[i].id, P[i].Bt, P[i].Pr, P[i].Wt, P[i].TAt);
    }
    return 0;
}
