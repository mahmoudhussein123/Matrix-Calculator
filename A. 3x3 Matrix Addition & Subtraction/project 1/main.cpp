#include<iostream>

#include<conio.h>

using namespace std;

int main()
{
    int i, j, a[10][10], b[10][10], c[10][10], d[10][10], n, m,x,y,z;

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


    cout << "Please enter values of Matrix B: \n";
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            cin >> b[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            d[i][j] = a[i][j] - b[i][j];
        }
    }

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            d[i][j] = a[i][j] - b[i][j];
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
                        cout << c[i][j] << " ";
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
                        cout << d[i][j] << " ";
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

            if (z==1 || z==2)
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
