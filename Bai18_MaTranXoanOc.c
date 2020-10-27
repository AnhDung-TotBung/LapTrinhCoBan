#include <stdio.h>
#define MAX 100

int taoMaTranXoanOc (int m[][MAX]){
    int n;
    scanf("%d",&n);
    int left, right;
    int top = left = 0;
    int bot = right = n-1;
    int k = 1;

    while (1){
        //(1)
        for (int i = left; i<=right; i++)
            m[top][i] = k++;
        top++;
        if (top>bot)
            break;

        //(2)
        for (int i = top; i<= bot; i++)
            m[i][right] = k++;
        right--;
        if (left>right)
            break;

        //(3)
        for (int i = right; i>= left; i--)
            m[bot][i] = k++;
        bot--;
        if (top>bot)
            break;

        //(4)
        for (int i = bot; i>= top; i--)
            m[i][left] = k++;
        left++;
        if (left>right)
            break;
    }
    return n;
}

void inMaTran (int m[][MAX], int n){
    for (int i=0; i<n; i++){
        printf("\t");
        for (int j=0; j<n; j++){
            printf("%4d",m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    int m[MAX][MAX];
    n = taoMaTranXoanOc(m);
    inMaTran(m,n);

}
