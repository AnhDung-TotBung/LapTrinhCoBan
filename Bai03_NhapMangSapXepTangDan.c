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

void sapXepMang (int a[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (a[j]<a[i]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(){
    int a[MAX];
    int n = nhapMang(a);
    printf("Day sao ban dau: \n");
    inMang(a,n);

    sapXepMang(a,n);
    printf("Day sau khi sap xep: \n");
    inMang(a,n);
}
