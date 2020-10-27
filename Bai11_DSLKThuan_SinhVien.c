#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

typedef struct{
    char hoTen[25];
    int tuoi;
    float diemTB;
} SinhVien;

typedef struct node {
    SinhVien data;
    struct node* next;
} node;

node* first = NULL;

SinhVien nhapSinhVien (){
    SinhVien sv;
    printf("\tNhap ten: ");
    fflush(stdin);
    gets(sv.hoTen);

    printf("\tNhap tuoi: ");
    scanf("%d",&sv.tuoi);

    printf("\tNhap diem: ");
    scanf("%f",&sv.diemTB);

    return sv;
}

node* taoNode (){
    node* pnode = (node*)malloc(sizeof(node));

    pnode->data = nhapSinhVien();

    pnode->next = NULL;
    return pnode;
}

void themNodeDauTien (){
    node* pnode = taoNode();
    first = pnode;
}

void themNodeViTriDau (){
    if (first == NULL){
        themNodeDauTien();
    }
    else{
        node* pnode = taoNode();
        pnode->next = first;
        first = pnode;
    }
}

void themNodeViTriCuoi(){
    if (first == NULL){
        themNodeDauTien();
    }
    else{
        node* last;
        for (last=first; last->next!=NULL ;last=last->next);
        node* pnode = taoNode();
        last->next = pnode;
    }
}

void hienThi1SinhVien (SinhVien sv){
    printf("\tHo ten: %s\n",sv.hoTen);
    printf("\tTuoi: %d\n",sv.tuoi);
    printf("\tDiem TB: %.2f\n",sv.diemTB);
}

void hienThi1SinhVienDangBang (SinhVien sv){
    printf("|%20s|%6d|%8.2f|\n",sv.hoTen,sv.tuoi,sv.diemTB);
}

void hienThiDanhSachSinhVien (){
    if (first==NULL){
        printf("Danh sach rong\n");
        return;
    }
    printf("\t\tDANH SACH SINH VIEN\n");
    printf("\t|%4s|%20s|%6s|%8s|\n","STT","HO TEN", "TUOI", "DIEM");
    printf("\t|%4s|%20s|%6s|%8s|\n","____","____________________","______","________");
    int STT = 1;
    for (node* i =first; i!=NULL; i=i->next){
        printf("\t|%4d",STT++);
        hienThi1SinhVienDangBang(i->data);
    }
}

void menu(){
    printf("\t\tMENU\n");
    printf("\t1. Nhap danh sach sinh vien\n");
    printf("\t2. Hien thi danh sach\n");
    printf("\t3. Chen sinh vien theo ten\n");
    printf("\t4. Xoa sinh vien theo ten\n");
    printf("\t5. Sua sinh vien theo ten\n");
    printf("\t0. Exit\n");
    printf("\t\tVui long chon: ");
}

node* timSinhVienTheoTen (char tenCanTim[]){
    for (node* i=first; i!=NULL; i=i->next){
        if (strcmp(i->data.hoTen,tenCanTim)==0){
            return i;
        }
    }
    return NULL;
}

int chenSinhVienTheoTen (char tenCanTim[]){
    node* i = timSinhVienTheoTen(tenCanTim);
    if (i==NULL){
        return 0;
    }

    node* pnode = taoNode();
    pnode->next = i->next;
    i->next = pnode;
    return 1;
}

int suaSinhVienTheoTen (char tenCanTim[]){
    node* i = timSinhVienTheoTen(tenCanTim);
    if (i==NULL){
        return 0;
    }
    printf("\tNhap thong tin can sua\n");
    i->data = nhapSinhVien();
    return 1;
}

int xoaNode (node* del){
    if (del==NULL)
        return 0;

    if (del==first){
        first = first->next;
        free(del);
    }
    else{
        node* i;
        for (i=first; i->next != del; i = i->next);
        i->next = del->next;
        free(del);
    }
    return 1;
}

int xoaNodeTheoTen (char tenCanTim[]){
    node* i = timSinhVienTheoTen(tenCanTim);
    if (i==NULL){
        return 0;
    }

    xoaNode(i);
    return 1;
}

void xoaDanhSach (){
    while (first !=NULL){
        xoaNode(first);
    }
}

void nhapDanhSachSinhVien (){
    xoaDanhSach();
    while (1){
        themNodeViTriCuoi();

        char chon;
        printf("\tNhap tiep? (y/n) ");
        fflush(stdin);
        chon = getchar();

        if (chon=='n'||chon=='N')
            break;
    }
}

int main(){
    int chon;
    char tenCanTim[25];
    while (1){
        menu();
        scanf("%d",&chon);
        system("cls");
        switch(chon){
            case 1:
                printf("\tBan da chon nhap danh sach sinh vien\n");
                nhapDanhSachSinhVien();
                printf("\tBan da nhap thanh cong\n");
                break;
            case 2:
                hienThiDanhSachSinhVien();
                break;
            case 3:
                printf("\tBan da chon chen sinh vien theo ten\n");
                printf("\tNhap ten sinh vien muon chen sau: ");
                fflush(stdin);
                gets(tenCanTim);

                if (chenSinhVienTheoTen(tenCanTim)){
                    printf("\tChen thanh cong\n");
                }
                else{
                    printf("\tChen that bai\n");
                }
                break;
            case 4:
                printf("\tBan da chon xoa sinh vien theo ten\n");
                printf("\tNhap ten sinh vien muon xoa: ");
                fflush(stdin);
                gets(tenCanTim);

                if (xoaNodeTheoTen(tenCanTim)){
                    printf("\Xoa thanh cong\n");
                }
                else{
                    printf("\tXoa that bai\n");
                }
                break;
            case 5:
                printf("\tBan da chon sua sinh vien theo ten\n");
                printf("\tNhap ten sinh vien muon sua: ");
                fflush(stdin);
                gets(tenCanTim);

                if (suaSinhVienTheoTen(tenCanTim)){
                    printf("\tSua thanh cong\n");
                }
                else{
                    printf("\tSua that bai\n");
                }
                break;
            case 0:
                exit(0);
            default:
                printf("\tChi nhap tu 0-5\n");
                break;
        }
        printf("Bam phim bat ky de ve menu");
        getch();
        system("cls");
    }
}

