#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    scanf("%d",&N);
    for (i=1;i<11;i++){
        printf("%d x %d = %d\n",i,N,i*N);
    }
    return 0;
}
