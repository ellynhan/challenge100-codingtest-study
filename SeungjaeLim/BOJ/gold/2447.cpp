#include<stdio.h>

void star(int x, int y, int num, int arr[][2188]);

int main()
{
    int arr[2188][2188] = {0, };
    int n;
    scanf("%d",&n);
    star(0, 0, n, arr);
    for( int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            if(arr[i][j] == 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}

void star(int x, int y, int num, int arr[][2188])
{
    if(num == 1)
    {
        arr[x][y] = 1;
    }
    else
    {
        num = num / 3;
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if( i == 1 && j == 1)
                {
                    continue;
                }
                else
                {
                    star(x + i*num, y + j*num, num, arr);
                }
            }
        }
    }
    return;
}
