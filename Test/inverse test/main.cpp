#include <iostream>

using namespace std;

int transposedB (int matrix[10][10] , int x , int y)
{
    int res [10][10];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++ )
        {
            res[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++ )
        {
            cout << res[i][j] << " " ;
        }

        cout << endl ;
    }

    return res[x][y];
}


int determinantB(int matrixB[10][10], int x , int y)
{
    int detB = 0;
    int submatrixB[10][10];

    if (x == 1)
        return (matrixB[0][0]);

    else if (x == 2)
        return ((matrixB[0][0] * matrixB[1][1]) - (matrixB[1][0] * matrixB[0][1]));
    else
    {
        for (int s = 0; s < x; s++)
        {
            int subi = 0;
            for (int i = 0; i < x; i++)
            {
                int subj = 0;
                for (int j = 0; j < x; j++)
                {
                    if (j == x && i == y)
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



int main ()
{
    int i, j, a[10][10], b[10][10], add[10][10], sub[10][10];
    int n, m,x,y,z, mul[10][10],k;
    long long inverse_b[10][10];

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


    cout << transposedB(b , x , y);

}


