#include <iostream>
using namespace std;
template <class Type>
class Diagonal
{
    Type *a;
    int size;

public:
    Diagonal(int s1)
    {
        size = s1;
        a = new Type[size];
    }
    void Store(int i, int j, Type x);
    Type Retrieve(int i, int j);
};
template <class Type>
void Diagonal<Type>::Store(int i, int j, Type x)
{
    if ((i < 1) || (j < 1) || (i > size) || (j > size))
    {
        cout << "Invalid Index!!!!.....\n";
    }
    else if (i == j)
        a[i - 1] = x;
    else if (x != 0)
    {
        cout << "x must be zero\n";
        return;
    }
}
template <class Type>
Type Diagonal<Type>::Retrieve(int i, int j)
{
    if ((i < 1) || (j < 1) || (i > size) || (j > size))
    {
        cout << "Invalid Index!!!!.....\n";
        exit(1);
    }
    else if (i == j)
        return a[i - 1];
    else
        return 0;
}
template <class Type>
class LowTri
{
    Type *a;
    int size;

public:
    LowTri(int s1)
    {
        size = s1 * (s1 + 1) / 2;
        a = new Type[size];
    }
    void Store(int i, int j, Type x);
    Type Retrieve(int i, int j);
};
template <class Type>
void LowTri<Type>::Store(int i, int j, Type x)
{
    if ((i < 1) || (j < 1) || (i > size) || (j > size))
    {
        cout << "Invalid Index!!!!.....\n";
        return;
    }
    else if (i >= j)
        a[(i * (i - 1) / 2) + (j - 1)] = x;
    else if (x != 0)
    {
        cout << "x must be zero\n";
        return;
    }
}
template <class Type>
Type LowTri<Type>::Retrieve(int i, int j)
{
    if ((i < 1) || (j < 1) || (i > size) || (j > size))
    {
        cout << "Invalid Index!!!!.....\n";
        exit(1);
    }
    else if (i >= j)
        return a[(i * (i - 1) / 2) + (j - 1)];
    else
        return 0;
}
template <class Type>
class UpTri
{
    Type *a;
    int size;

public:
    UpTri(int s1)
    {
        size = s1 * (s1 + 1) / 2;
        a = new Type[size];
    }
    void Store(int i, int j, Type x);
    Type Retrieve(int i, int j);
};
template <class Type>
void UpTri<Type>::Store(int i, int j, Type x)
{
    if ((i < 1) || (j < 1) || (i > size) || (j > size))
    {
        cout << "Invalid Index!!!!.....\n";
        return;
    }
    else if (j >= i)
        a[(j * (j - 1) / 2) + (i - 1)] = x;
    else if (x != 0)
    {
        cout << "x must be zero\n";
        return;
    }
}
template <class Type>
Type UpTri<Type>::Retrieve(int i, int j)
{
    if ((i < 1) || (j < 1) || (i > size) || (j > size))
    {
        cout << "Invalid Index!!!!.....\n";
        exit(1);
    }
    else if (j >= i)
        return a[(j * (j - 1) / 2) + (i - 1)];
    else
        return 0;
}
template <class Type>
class Symmetric
{
    Type *a;
    int size;

public:
    Symmetric(int s1)
    {
        size = s1 * (s1 + 1) / 2;
        a = new Type[size];
    }
    void Store(int i, int j, Type x);
    Type Retrieve(int i, int j);
};
template <class Type>
void Symmetric<Type>::Store(int i, int j, Type x)
{
    if ((i < 1) || (j < 1) || (i > size) || (j > size))
    {
        cout << "Invalid Index!!!!.....\n";
        return;
    }
    else if (i >= j)
        a[(i * (i - 1) / 2) + (j - 1)] = x;
    else if (x != 0)
    {
        cout << "x must be zero\n";
        return;
    }
}
template <class Type>
Type Symmetric<Type>::Retrieve(int i, int j)
{
    if ((i < 1) || (j < 1) || (i > size) || (j > size))
    {
        cout << "Invalid Index!!!!.....\n";
        exit(1);
    }
    else if (i >= j)
        return a[(i * (i - 1) / 2) + (j - 1)];
    else
        return a[(j * (j - 1) / 2) + (i - 1)];
}
int main()
{
    int size, choice, x;
    char ch = 'y';
    cout << "Enter the size\n";
    cin >> size;
    Diagonal<int> D(size);
    LowTri<int> L(size);
    UpTri<int> U(size);
    Symmetric<int> S(size);
    while (ch == 'y')
    {
        cout << "Main Module\n";
        cout << "1.Diagonal\n";
        cout << "2.Lower Triangular\n";
        cout << "3.Upper Triangular\n";
        cout << "4.Symmetric\n";
        cout << "Enter your choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the elements\n";
            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    cout << "\n";
                    cin >> x;
                    D.Store(i, j, x);
                }
            }
            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    cout << D.Retrieve(i, j) << "\t";
                }
                cout << "\n";
            }
            break;
        case 2:
            cout << "Enter the Elements\n";
            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    cout << "\n";
                    cin >> x;
                    L.Store(i, j, x);
                }
            }
            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    cout << L.Retrieve(i, j) << "\t";
                }
                cout << "\n";
            }
            break;
        case 3:
            cout << "Enter the Elements\n";
            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    cout << "\n";
                    cin >> x;
                    U.Store(i, j, x);
                }
            }
            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    cout << U.Retrieve(i, j) << "\t";
                }
                cout << "\n";
            }
            break;
        case 4:
            cout << "Enter the Elements\n";
            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    cout << "\n";
                    cin >> x;
                    S.Store(i, j, x);
                }
            }
            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    cout << S.Retrieve(i, j) << "\t";
                }
                cout << "\n";
            }
            break;
        }
        cout << "Do you want to continue\n";
        cin >> ch;
    }
    return 0;
}