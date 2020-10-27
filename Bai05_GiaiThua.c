#include <stdio.h>

int main(){
    int gt = 1, n;
    printf("Nhap so n: ");
    scanf("%d",&n);

    for (int i=1; i<=n; i++){
        gt *= i;
    }
    printf("%d! = %d\n",n,gt);
}
