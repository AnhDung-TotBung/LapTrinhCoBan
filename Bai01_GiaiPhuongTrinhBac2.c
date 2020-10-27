#include <stdio.h>
#include <math.h>

int main(){
    double a,b,c,x1,x2;
    printf("Nhap a, b, c: ");
    scanf("%lf%lf%lf",&a,&b,&c);

    if (0==a){
        if (0==b){
            if (0==c){
                printf("PT vo so nghiem");
            }
            else{
                printf("PT vo nghiem");
            }
        }
        else{
            printf("Phuong trinh co nghiem duy nhat %.2f",-b/c);
        }
    }
    else{
        double delta = b*b-4*a*c;
        if (delta<0){
            printf("PT vo nghiem");
        }
        else if (delta == 0){
            printf("PT co nghiem kep x1 = x2 = %.2f",-b/(2*a));
        }
        else{
            x1 = (sqrt(delta)-b)/(2*a);
            x2 = (-sqrt(delta)-b)/(2*a);
            printf("PT co 2 nghiem\n");
            printf("x1 = %.2f, x2 = %.2f",x1,x2);
        }

    }

}
