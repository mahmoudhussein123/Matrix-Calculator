#include<iostream>

#include <new>

#include<conio.h>

using namespace std;

void print_array_using_pointers ( int n ,int m , int *ptr )
{
    int i , j , a[10][10];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

}

double determinant (int m ,int *p)

{
    double ans = 0 , inner_sol , inner_determinant;
    int a[10] [10];

    if (m ==1 || m ==2)
    {
        if (m ==1)
        {
            ans = *p ;
        }

        else (m ==2);
        {
            ans = (a[0][0] *a[1][1]) - (a[0][1] * a[1][0]);
        }
    }

    else
    {
        int i , j , k , l , n = 0 , sign = +1 , basic , element;

        int * q ;

        q = new int [(m-1) * (m-1)] ;

        for (i = 0 ; i < m; i++)
        {
            l=0;
            n=0;
            basic = * (p+i) ;

            for (j = 0;j < m; j++)
            {
                for (k = 0; k < m; k++)
                {
                    element = *(p+l);

                    cout << element << " ";

                    if ((j == 0) || (i==k));

                    else
                    {
                        *( q + n )=element;
                        n = n + 1 ;
                    }

                    l = l + 1 ;
                }
            }

            cout << endl << basic << " x " << endl ;

            print_array_using_pointers ( (m-1) , (m-1) , q );

            inner_determinant = determinant (m-1 ,q);
            inner_sol = sign * basic * inner_determinant;

            cout << "Sign: " << sign << " x Basic : " << basic << " x Determinant " << inner_determinant << " = " << inner_sol << endl ;

            ans = ans + inner_sol;
            sign = sign * -1 ;

        }

        delete [] q;
    }

    return ans;

}

int main()
{
    int i, j, a[10][10], b[10][10], add[10][10], sub[10][10];
    int n, m,x,y,z, mul[10][10],k ,*p;
    double ans;




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



    p = new int [ n * m ];

    print_array_using_pointers( n , m ,p );


    ans = determinant (m , p);

    cout << ans << endl ;

    delete [] p;

    return 0;
}



