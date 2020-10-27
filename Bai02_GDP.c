#include <stdio.h>

int main(){
    int nam = 2014;
    float GDP_ban_dau, GDP;
    float he_so_tang_truong;

    printf("Nhap GDP nam 2014: ");
    scanf("%f",&GDP_ban_dau);
    GDP = GDP_ban_dau;

    printf("Nhap he so tang truong: ");
    scanf("%f",&he_so_tang_truong);
    he_so_tang_truong /= 100;

    printf("\t%6s%6s\n","NAM", "GDP");

    while (1){
        printf("\t%6d  %6.2f\n",nam,GDP);
        if (GDP>= 2* GDP_ban_dau)
            break;
        GDP = GDP*(1+he_so_tang_truong);
        nam++;

    }

}
