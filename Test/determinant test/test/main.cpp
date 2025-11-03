#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

using namespace std;

float determinantB(float [][10], float );

void transpose (float [][10] , float [][10] , float );

float determinantB(float matrixB[10][10], float x)
{
    float s = 1 , b[10][10] , detB = 0;
    int i , j , m , n , c;

    if (x == 1)
        return (matrixB[0][0]);

    else
    {
        detB = 0 ;
        for (c =0 ; c < x; c++)
        {
            m = 0;
            n = 0;
            for (i =0 ; i < x; i++)
            {
                for (j = 0 ; j < x; j++)
                {
                    b[i][j] = 0;
                    if (i !=0 && j != c)
                    {
                        b[m][n] = matrixB[i][j];
                        if (n < (x-2))
                            n ++ ;
                        else
                        {
                            n = 0;
                            m = 0;
                        }
                    }
                }
            }

            detB = detB + s *(matrixB[0][c] * determinantB(b , x-1));
            s = -1 * s ;
        }

    }
    return (detB);
}

void cofactor (float num [10][10], float f)
{
    float b[10][10] , fac [10][10] ;
    int p,q,m,n,i,j ;
    for (q = 0; q < f; q++)
    {
        for (p =0; p < f; p++)
        {
            m = 0;
            n = 0;
            for (i = 0; i < f; i++)
            {
                for (j = 0; j < f; j++)
                {
                    if (i != q && j != p)
                    {
                        b[m][n] = num[i][j];
                        if (n < (f-2))
                        n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }

            fac [q][p] = pow (-1 ,q+p) * determinantB(b ,f-1);
        }
    }

    transpose (num , fac ,f);
}

void transpose (float num [10][10] , float fac [10][10] , float r)
{
    int i , j ;
    float b[10][10] , inverse [10][10] , d;

    for (i = 0; i <r; i++)
    {
        for (j = 0; j < r; j++)
        {
            b[i][j] = fac [j][i] ;
        }
    }

    d = determinantB(num ,r);
    for (i = 0; i <r; i++)
    {
        for (j = 0; j <r; j++)
        {
            inverse [i][j] = b[i][j] /d;
        }
    }

    for (i = 0; i <r; i++)
    {
        for (j = 0; j <r; j++)
        {
            cout << inverse [i][j] << " ";
        }

        cout << endl ;
    }
}

int main()
{
    int i, j, a[10][10], add[10][10], sub[10][10];
    int n, m,y,z, mul[10][10],k;
    float b[10][10],x ;

    cout << "Please enter dimensions of Matrix A:" <<endl;
    cin >> n >> m;
    cout << "Please enter dimensions of Matrix B:" <<endl;
    cin >> x >> y;


    cout << "Please enter values of Matrix A:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }


    cout << "Please enter values of Matrix B:\n";
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            cin >> b[i][j];
        }
    }

    cofactor(b,x);
}
