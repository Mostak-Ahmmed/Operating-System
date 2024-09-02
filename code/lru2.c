#include <stdio.h>

int main() {
    int q[20], p[50], c = 0, c1, d, f, i, j, k = 0, n, r, t, b[20], c2[20];
    printf("Enter no of pages:");
    scanf("%d", &n);
    printf("Enter the reference string:");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter no of frames:");
    scanf("%d", &f);
    q[k] = p[k];
    printf("The Page Replacement Process is ->\n");
    printf("For %d : %d\n", p[k], q[k]);
    c++;
    k++;
    for (i = 1; i < n; i++) {
        c1 = 0;
        for (j = 0; j < f; j++) {
            if (p[i] != q[j])
                c1++;
        }
        if (c1 == f) {
            c++;
            if (k < f) {
                q[k] = p[i];
                printf("For %d :", p[i]);
                for (j = 0; j <= k; j++)
                    printf(" %d", q[j]);
                printf("\n");
                k++;
            } else {
                for (r = 0; r < f; r++) {
                    c2[r] = 0;
                    for (j = i - 1; j >= 0; j--) {
                        if (q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for (r = 0; r < f; r++)
                    b[r] = c2[r];
                for (r = 0; r < f; r++) {
                    for (j = r; j < f; j++) {
                        if (b[r] < b[j]) {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }
                printf("For %d :", p[i]);
                for (r = 0; r < f; r++) {
                    if (c2[r] == b[0])
                        q[r] = p[i];
                    printf(" %d", q[r]);
                }
                printf("\n");
            }
        }
    }
    printf("\nTotal no of page faults using LRU is : %d\n", c);
    return 0;
}
//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
// page number: 20
// frame number: 3