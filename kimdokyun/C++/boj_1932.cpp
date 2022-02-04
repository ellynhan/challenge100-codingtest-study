#include<stdio.h>

int main() {
    int N;
    int tri[500][500];
    scanf("%d",&N);
    scanf("%d",&tri[0][0]);
    int max = tri[0][0];
    for(int i=1;i<N;i++) {
        for(int j=0;j<=i;j++) {
            scanf("%d",&tri[i][j]);
            int back = 0;
            if(j!=0 && back < tri[i-1][j-1]){
                back = tri[i-1][j-1];
            }
            if(j!=i && back < tri[i-1][j]) {
                back = tri[i-1][j];
            }
            tri[i][j]+=back;
            if(tri[i][j] > max) {
                max = tri[i][j];
            }
        }
    }
    printf("%d",max);
}