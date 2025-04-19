#include<stdio.h>

void main() {
    int i, j, r, n, p, sum, count = 0, k = 0, u, lim = 0;
    int flag = 1, safe;
    printf("Enter no of resources:");
    scanf("%d", &r);
    int max_res[r], avail[r], avail_og[r];
    printf("Enter max instances of each resource:");
    for (i = 0; i < r; i++) {
        printf("R%d:", i + 1);
        scanf("%d", &max_res[i]);
    }
    printf("Enter no of processes:");
    scanf("%d", &p);
    int alloc[p][r], max[p][r], need[p][r], fin[p];
    int finf[p];
    for (i = 0; i < p; i++) finf[i] = 0;
    printf("Enter instances allocated for each process:");
    for (i = 0; i < p; i++) {
        printf("P%d:", i + 1);
        for (j = 0; j < r; j++) {
            printf("\tR%d:", j + 1);
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter max instances required for each process:");
    for (i = 0; i < p; i++) {
        printf("P%d:", i + 1);
        for (j = 0; j < r; j++) {
            printf("\tR%d:", j + 1);
            scanf("%d", &max[i][j]);
        }
    }
    //avail
    for (i = 0; i < r; i++) {
        sum = 0;
        for (j = 0; j < p; j++) {
            sum += alloc[j][i];
        }
        avail_og[i] = avail[i] = max_res[i] - sum;
    }
    //need
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    //printing need
    for (i = 0; i < p; i++) {
        printf("\n");
        for (j = 0; j < r; j++) {
            printf("\t%d", need[i][j]);
        }
    }
    printf("\navail:");
    for (i = 0; i < r; i++) {
        printf("\t%d", avail[i]);
    }
    while (count != p) {
        for (i = 0; i < p; i++) {
            if (finf[i] == 0) {
                flag = 1;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) flag = 0;
                }
                if (flag == 1) {
                    finf[i] = 1;
                    fin[k] = i + 1;
                    k++;
                    count++;

                    for (j = 0; j < r; j++) {
                        avail[j] += alloc[i][j];
                    }
                }
            }
        }
        lim++;
        if (lim > 100) break;
    }
    if (count != p) {
        printf("\ndeadlock occurred!!!!!!!!!!!!!!!!!");
    } else {
        printf("\nNo deadlock occurred\n");
        printf("safe seq: <");
        for (i = 0; i < p; i++) {
            printf("\tP%d\t", fin[i]);
            if (i < p - 1) printf(",");
        }
        printf(">");
    }
}
