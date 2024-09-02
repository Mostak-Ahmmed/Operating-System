#include <stdio.h>
#include <limits.h>

int checkHit(int incomingPage, int queue[], int occupied)
{

    for (int i = 0; i < occupied; i++)
    {
        if (incomingPage == queue[i])
            return 1;
    }

    return 0;
}

void printFrame(int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
        printf("%d\t\t\t", queue[i]);
}

int main()
{
    int n, frames;
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int incomingStream[n];
    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &incomingStream[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int queue[n];
    int distance[n];
    int occupied = 0;
    int pagefault = 0;
    int totalPageFault = 0;

    printf("The Page Replacement Process is -->\n");

    printf("\n\t\t\tFrame->1\t\tFrame->2\t\tFrame->3\n");
    for (int i = 0; i < n; i++)
    {
        printf("For %d : \t\t", incomingStream[i]);

        if (checkHit(incomingStream[i], queue, occupied))
        {
            printFrame(queue, occupied);
        }

        else if (occupied < frames)
        {
            queue[occupied] = incomingStream[i];
            pagefault++;
            totalPageFault++;
            occupied++;

            printFrame(queue, occupied);
        }
        else
        {

            int max = INT_MIN;
            int index;
            for (int j = 0; j < frames; j++)
            {
                distance[j] = 0;
                for (int k = i - 1; k >= 0; k--)
                {
                    ++distance[j];

                    if (queue[j] == incomingStream[k])
                        break;
                }

                if (distance[j] > max)
                {
                    max = distance[j];
                    index = j;
                }
            }
            queue[index] = incomingStream[i];
            printFrame(queue, occupied);
            pagefault++;
            totalPageFault++;
        }

        if (pagefault == 0)
            printf("No page fault!");

        printf("\n");
        pagefault = 0;
    }

    printf("Total no of page faults using LRU is : %d\n", totalPageFault);

    return 0;
}


//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
// page number: 20
// frame number: 3