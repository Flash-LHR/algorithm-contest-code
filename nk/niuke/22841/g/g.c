#include <stdio.h>

#define mx 1000100

int is[mx], prim[mx], cnt;
int i, j;

int main() {
    is[0] = is[1] = 1;
    for (i = 2; i < mx; i++) {
        if (!is[i]) prim[cnt++] = i;
        for (j = 0; j < cnt && prim[j] * i < mx; j++) {
            is[prim[j] * i] = 1;
            if (i % prim[j] == 0) break;
        }
    }
    printf("%d\n", cnt);

    return 0;
}
