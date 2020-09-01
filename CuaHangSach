#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


typedef struct sach
{
    char tenSach[15];
    char tenTacGia[15];
    int namXB;
}sach;

sach nhapSach()
{
    sach tmp;
    printf("Ten sach:");
    fflush(stdin);
    gets(tmp.tenSach);
    printf("Ten Tac Gia :");
    fflush(stdin);
    gets(tmp.tenTacGia);
    printf("Nhap nam xuat ban:");
    scanf("%d",&tmp.namXB);

    return tmp;
}

void hienThiSach(sach tmp)
{
    printf("%15s|%15s|%8d\n",tmp.tenSach,tmp.tenTacGia,tmp.namXB);
}

sach*nhapDanhSach(int*n)
{
    printf("Nhap so  luong sach :");
    scanf("%d",n);

    sach*list =(sach*)malloc(*n*sizeof(sach));

    for (int i=0;i<*n;i++)
    {
        printf("Nhap sach thu:%d\n",i+1);
        list[i]=nhapSach();
    }
    return list;
}

void hienThiDanhSach(sach*list,int n)
{
    if(n==0)
    {
        printf("Danh Sach Rong\n");

    }
    printf("Danh Sach Sach:\n");
    printf("%3s|%15s|%15s|%8s\n","STT","Ten Sach","Tac Gia","Nam XB");

    for (int i=0;i<n;i++)
    {
        printf("%3d|",i+1);
        hienThiSach(list[i]);
    }
}
void timSach(sach*list,int n)
{
    char tenSachCanTim[15];
    printf("Moi  ban  nhap  ten sch can nhap:");
    fflush(stdin);
    gets(tenSachCanTim);
    printf("%3s|%15s|%15s|%8s","STT","Ten Sach"."Tac Gia","Nam XB");

    for (int i=0;i<n;i++)
    {
        if (strcmp(tenSachCanTim,list[i])==0)
        {
            hienThiSach(list[i]);

        }
    }
}

int main()
{
    int n;
    sach*list=nhapDanhSach(&n);
    hienThiDanhSach(list,n);
    timSach(list,n);
}
