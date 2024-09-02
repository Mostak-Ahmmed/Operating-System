#include<stdio.h>
#define max 25

void main(){
    int frag[max], b[max], f[max], i, j, nb, nf, temp, best_fit;

    int bf[max], ff[max];

    //initialize all values to zero
    for(i = 0; i < max; i++){
        b[i] = 0;
        f[i] = 0;
        frag[i] = 0;
        bf[i] = 0;
        ff[i] = 0;
    }

    printf("\nEnter the number of Blocks: ");
    scanf("%d", &nb);

    printf("\nEnter the number of Files: ");
    scanf("%d", &nf);

    printf("\nEnter size of the blocks:-\n");
    for(i = 1; i <= nb; i++){
        printf("Block-%d:", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter size of the files:-\n");
    for(i = 1; i <= nf; i++){
        printf("File-%d:", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= nf; i++){
        best_fit = -1; // initialize best fit to invalid index
        temp = max;    // initialize temp to maximum possible value

        // Find the best fit block for the current file
        for(j = 1; j <= nb; j++){
            if(bf[j] != 1){
                int diff = b[j] - f[i];
                if(diff >= 0 && diff < temp){
                    temp = diff;
                    best_fit = j;
                }
            }
        }

        // Update the allocation details
        if(best_fit != -1){
            ff[i] = best_fit;
            frag[i] = temp;
            bf[best_fit] = 1;
        }
    }

    printf("\nFile_no \tFile_size \tBlock_no \tBlock_size \tFragment\n");

    for(i = 1; i <= nf; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
}

