/* Merge Sort*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define MAX 100

int nhapMang (int a[]){
    int n;
    scanf("%d",&n);

    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }

    return n;
}

void inMang (int a[], int n){
    for (int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int ghepMang (int a1[], int a2[], int a3[], int n1, int n2){

    int i, j, k;
    i = j = k = 0;

    while (1){
        if (a1[i]<a2[j]){
            a3[k] = a1[i];
            k++;
            i++;
        }
        else{
            a3[k] = a2[j];
            k++;
            j++;
        }

        if (i>=n1 || j>=n2)
            break;
    }

    //Dien not mang 2
    if (i>=n1){
        while (j<n2){
            a3[k] = a2[j];
            k++;
            j++;
        }
    }

    //Dien not mang 1
    if (j>=n2){
        while (i<n1){
            a3[k] = a1[i];
            k++;
            i++;
        }
    }

    return k;
}

void menu(){
    printf("\t\tMENU\n");
    printf("\t1. Nhap 2 mang tang dan\n");
    printf("\t2. Ghep 2  mang\n");
    printf("\t3. In 3 mang\n");
    printf("\t0. Exit\n");
    printf("\t\tVui long chon: ");
}

int main(){
    int chon;
    int n1, n2, n3;
    int a1[MAX], a2[MAX], a3[MAX];
    while (1){
        menu();
        scanf("%d",&chon);

        system("cls");
        switch(chon){
            case 1:
                printf("\tNhap mang thu nhat:\n");
                printf("\tNhap so luong phan tu: ");
                n1 = nhapMang(a1);
                printf("\tNhap mang thu hai:\n");
                printf("\tNhap so luong phan tu: ");
                n2 = nhapMang(a2);
                printf("\tNhap xong 2 mang\n");
                break;
            case 2:
                n3 = ghepMang(a1,a2,a3,n1,n2);
                printf("\tBan da ghep mang xong\n");
                break;
            case 3:
                printf("\tMang thu nhat\n\t");
                inMang(a1,n1);
                printf("\tMang thu hai\n\t");
                inMang(a2,n2);
                printf("\tMang ghep\n\t");
                inMang(a3,n3);
                break;
            case 0:
                exit(0);
            default:
                printf("\tChi nhap tu 0-3\n");
        }

        printf("\tBam phim bat ky de ve menu");
        getch();
        system("cls");
    }
}
