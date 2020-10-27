#include <stdio.h>

int laTamGiac (float a, float b, float c){
    return (a+b)>c && (b+c)>a && (a+c)>b;
}



int main(){
    float a, b ,c;
    scanf("%f%f%f",&a,&b,&c);
    if (laTamGiac(a,b,c)){
        if (a==b && b==c){
            printf("Tam giac deu");
        }
        else if (a==b || b==c || c==a){
            printf("Tam giac can");
        }
        else if (a*a+b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b){
            printf("Tam giac vuong");
        }
        else{
            printf("Tam giac thuong");
        }
    }
    else{
        printf("Khong phai 3 canh tam giac");
    }
}
