#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#define MAX 100

void nhapHeSoDaThuc (int m[][MAX], int d, int c){
    for (int i=0; i<c; i++){
        scanf("%d",&m[d][i]);
    }
}

void tinhTongDaThuc (int m[][MAX],int c){
    for (int i=0; i<c; i++){
        m[2][i] = m[0][i] + m[1][i];
    }
}

void inHeSoDaThuc (int m[][MAX], int d, int c){
    printf("\t");
    for (int i=0; i<c; i++){
        if (m[d][i]!=0)
            printf("%4d",m[d][i]);
        else
            printf("%4s","");
    }
    printf("\n");
}

float tinhDaThuc (int m[][MAX], int c, float x){
    float sum = 0;

    for (int i=0; i<c; i++){
        sum += m[2][i] * pow (x,i);
    }

    return sum;
}

int main(){
    int m[3][MAX] = {0};
    int d, c1, c2;
    float x;
    printf("Nhap so bac cua da thuc 1: ");
    scanf("%d",&c1);
    printf("Nhap he so cua da thuc 1: ");
    nhapHeSoDaThuc(m,0,c1);

    printf("Nhap so bac cua da thuc 2: ");
    scanf("%d",&c2);
    printf("Nhap he so cua da thuc 2: ");
    nhapHeSoDaThuc(m,1,c2);

    tinhTongDaThuc(m,c1>c2?c1:c2);

    printf("\tHe so 3 da thuc lan luot la\n");
    inHeSoDaThuc(m,0,c1);
    inHeSoDaThuc(m,1,c2);
    inHeSoDaThuc(m,2,c1>c2?c1:c2);

    printf("\tNhap x: ");
    scanf("%f",&x);
    int c3 = c1>c2?c1:c2;
    printf("\tGia tri cua da thuc la: %.2f\n",tinhDaThuc(m,c3,x));

}
