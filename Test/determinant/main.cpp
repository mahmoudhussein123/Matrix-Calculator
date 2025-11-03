#include<iostream>

#include <bits/stdc++.h>

#include<conio.h>

#include <cmath>

using namespace std;

// Matrix A Determinant

int determinantA(int matrixA[10][10], int n)
{
    int detA = 0;
    int submatrixA[10][10];

    if (n == 2)
        return ((matrixA[0][0] * matrixA[1][1]) - (matrixA[1][0] * matrixA[0][1]));
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrixA[subi][subj] = matrixA[i][j];
                    subj++;
                }
                subi++;

            }
            detA = detA + (pow(-1, x) * matrixA[0][x] * determinantA(submatrixA, n - 1));
        }
    }
    return detA;
}

// Matrix B Determinant

int determinantB(int matrixB[10][10], int x)
{
    int detB = 0;
    int submatrixB[10][10];

    if (x == 2)
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

int main()
{
    int i, j, a[10][10], b[10][10], add[10][10], sub[10][10];
    int n, m,x,y,z, mul[10][10],k;

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

    // Matrix Addition & Subtraction
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            add[i][j] = a[i][j] + b[i][j];
            sub[i][j] = a[i][j] - b[i][j];
        }
    }

    // Matrix Multiplication
    for (i = 0; i < n; i++)
	{
		for (j = 0; j < y; j++)
		{
			mul[i][j] = 0;
			for (k = 0; k < m; k++)
			{
				mul[i][j] += a[i][k] * b[k][j];
			}
		}
	}

    if (n == x && m ==y)
    {
        do
        {
            cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
            cin >> z;

            if (z ==1)
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                    {
                        cout << add[i][j] << " ";
                    }
                    cout << "\n";
                }
            }

            else if (z ==2)
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < m; j++)
                    {
                        cout << sub[i][j] << " ";
                    }
                    cout << "\n";
                }
            }

            else if (z ==3)
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                cout << mul[i][j] << " ";
                    }
                    cout << "\n";
                }
            }

            else if (z ==5)
            {
                cout << determinantA(a, n) << endl;
            }

            else if (z ==6)
            {
                cout << determinantB(b, x) << endl;
            }

            else if (z ==7)
            {
                cout << "Thank you!";
                return 0;
            }

        }

        while (z ==1 || z ==2 || z ==3 || z ==4 || z ==5 || z ==6);

    }

    else if (n == m || x == y)
    {
        do
        {
            cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
            cin >> z;

            if (z==1 || z==2 )
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }

            else if (m == x && z == 3)
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                cout << mul[i][j] << " ";
                    }
                    cout << "\n";
                }
            }

            else if (m != x && z ==3)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }

            else if (n == m && z == 5)
            {
                cout << determinantA(a, n) << endl;
            }

            else if (x == y && z == 6)
            {
                cout << determinantB(b, x) << endl;
            }

            else if (n != m && z == 5)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }

            else if (x != y && z == 6)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }

            else if (z ==7)
            {
                cout << "Thank you!";
                return 0;
            }

        }

        while (z ==1 || z ==2 || z ==3 || z ==4 || z ==5 || z ==6);

    }

    else if (m == x)
    {
        do
        {
            cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
            cin >> z;

            if (z==1 || z==2 || z==5 || z==6)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }

            else if (z ==3)
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                cout << mul[i][j] << " ";
                    }
                    cout << "\n";
                }
            }

            else if (z ==7)
            {
                cout << "Thank you!";
                return 0;
            }

        }

        while (z ==1 || z ==2 || z ==3 || z ==4 || z ==5 || z ==6);

    }

    else
    {
        do
        {
            cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
            cin >> z;

            if (z==1 || z==2 || z ==3 || z==5 || z==6)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }

            else if (z ==7)
            {
                cout << "Thank you!";
                return 0;
            }

        }

        while (z ==1 || z ==2 || z ==3 || z ==4 || z ==5 || z ==6);

    }

        return 0;

}
