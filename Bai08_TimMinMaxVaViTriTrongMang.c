#include <stdio.h>
#define MAX 100

int nhapMang (int a[]){
    int n;

    printf("Nhap n: ");
    scanf("%d",&n);
    for (int i=0; i<n; i++)
        scanf("%d",&a[i]);
    return n;
}

int inMang (int a[], int n){
    for (int i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int timMax (int a[], int n){
    int max = a[0];
    for (int i=1; i<n; i++){
        if (a[i]>max)
            max = a[i];
    }
    return max;
}

int timMin (int a[], int n){
    int min = a[0];
    for (int i=1; i<n; i++){
        if (a[i]<min)
            min = a[i];
    }
    return min;
}

void lietKeViTriMax (int a[], int n){
    int max = timMax(a,n);
    for (int i=0; i<n; i++){
        if (a[i]==max){
            printf("%d ",i);
        }
    }
    printf("\n");
}

void lietKeViTriMin (int a[], int n){
    int min = timMin(a,n);
    for (int i=0; i<n; i++){
        if (a[i]==min){
            printf("%d ",i);
        }
    }
    printf("\n");
}

void main(){
    int a[MAX];
    int n = nhapMang(a);

    printf("Max = %d, o vi tri: ",timMax(a,n));
    lietKeViTriMax(a,n);
    printf("Min = %d, o vi tri: ",timMin(a,n));
    lietKeViTriMin(a,n);
}
