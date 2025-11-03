#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

using namespace std;

void transpose (float [][10] , float [][10] , float );

float determinantB(float matrixB[10][10], float x)
{
    int detB = 0;
    float submatrixB[10][10];

    if (x == 1)
        return (matrixB[0][0]);

    else if (x == 2)
        return ((matrixB[0][0] * matrixB[1][1]) - (matrixB[1][0] * matrixB[0][1]));
    else
    {
        for (int s = 0; s < x; s++)
        {
            int subi = 0;
            for (int i = 1; i < x; i++)
            {
                int subj = 0;
                for (int j = 0; j < x; j++)
                {
                    if (j == s)
                        continue;
                    submatrixB[subi][subj] = matrixB[i][j];
                    subj++;
                }
                subi++;

            }
            detB = detB + (pow(-1, s) * matrixB[0][s] * determinantB(submatrixB, x - 1));
        }
    }
    return detB;
}

void cofactor (float num [10][10], float f)
{
    float b[10][10] , fac [10][10] ;
    int p,q,m,n,i,j ;
    for (q =0; q<f; q++)
    {
        for (p =0; p <f; p++)
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
                        if (n < f-2)
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
        for (j = 0; j <r; j++)
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
    float b[10][10],x;

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
