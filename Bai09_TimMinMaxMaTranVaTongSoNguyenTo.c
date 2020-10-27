#include <stdio.h>
#define MAX 100

void nhapMatrix (int m[][MAX], int d, int c){
    for (int i=0; i<d; i++){
        for (int j=0; j<c; j++){
            scanf("%d",&m[i][j]);
        }
    }
}

void inMatrix(int m[][MAX], int d, int c){
    for (int i=0; i<d; i++){
        for (int j=0; j<c; j++){
            printf("%4d",m[i][j]);
        }
        printf("\n");
    }
}

int timMin (int m[][MAX], int d, int c){
    int min = m[0][0];
    for (int i=0; i<d; i++){
        for (int j=0; j<c; j++){
            if (m[i][j]<min)
            {
                min = m[i][j];
            }
        }
    }
    return min;
}

int timMax (int m[][MAX], int d, int c){
    int max = m[0][0];
    for (int i=0; i<d; i++){
        for (int j=0; j<c; j++){
            if (m[i][j]>max)
            {
                max = m[i][j];
            }
        }
    }
    return max;
}

int laSNT (int n){
    if (n<2)
        return 0;
    for (int i=2; i<n-1; i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}

int tongSNT (int m[][MAX], int d, int c){
    int sum = 0;

    for (int i=0; i<d; i++){
        for (int j=0; j<c; j++){
            sum += laSNT(m[i][j])?m[i][j]:0;
        }
    }
    return sum;
}

int main(){
    int m[MAX][MAX];
    int d, c;
    printf("Nhap so dong, cot: ");
    scanf("%d%d",&d,&c);
    nhapMatrix(m,d,c);
    inMatrix(m,d,c);

    printf("MAX = %d, MIN = %d\n",timMax(m,d,c),timMin(m,d,c));

    printf("Tong cac SNT: %d\n",tongSNT(m,d,c));
}
