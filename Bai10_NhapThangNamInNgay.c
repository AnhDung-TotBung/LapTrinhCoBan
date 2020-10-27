#include <stdio.h>

int laNhuan (int nam){
    if (nam%400==0 || (nam%100!=0 && nam%4==0)){
        return 1;
    }
    return 0;
}

int timNgay (int thang, int nam){
    switch (thang){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 2:
            if (laNhuan(nam))
                return 29;
            else
                return 28;
        default:
            return 30;
    }
}

int main(){
    int thang, nam;
    printf("Nhap thang, nam: ");
    scanf("%d%d",&thang,&nam);

    if (thang<=0 ||thang >12 || nam==0){
        printf("Khong co thang nam tuong ung");
    }
    else{
        printf("Thang %d nam %d co %d ngay",thang,nam,timNgay(thang,nam));
    }

}
