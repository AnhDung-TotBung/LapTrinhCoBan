#include <stdio.h>

int BCNN (int a, int b){
    for (int i=a;;i++){
        if (i%a==0 && i%b==0)
            return i;
    }
    return 0;
}

int main(){
    int a, b;
    printf("Nhap a, b: "); scanf("%d%d",&a,&b);
    printf("BCNN(%d, %d) = %d\n",a,b,BCNN(a,b));
}
