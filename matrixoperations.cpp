#include <iostream>

using namespace std;

#define ROWS 10
#define COLS 10
#define NOTUT 0
#define UT 1
#define NOTFOUND 0
#define FOUND 1

class matrix
{
	private:
		int m,n;
		int mat[ROWS][COLS];

	public:
		matrix()
		{
			m = n = 0;
		}

		matrix(int m, int n)
		{
			this->m = m;
			this->n = n;			
		}

		void create()
		{
			cout << "Enter no of rows and cols:" << endl;
			cin >> m >> n;
			int i,j;
			cout << "Enter the matrix" << endl;
			for(i=0; i<m; i++)
			{
				for(j=0; j<n; j++)
					cin >> mat[i][j];
			}
		}

		void display()
		{
			int i,j;
			cout << "The matrix is: " << endl;
			for(i=0; i<m; i++)
			{
				for(j=0; j<n; j++)
					cout << mat[i][j] << "\t";
				cout << "\n";
			}
		}

		void uptri()
		{
			int i,j;
			int flag;
			if(m != n)
			{
				cout << "Not upper triangular because the matrix isn't a square matrix" << endl;
				flag = NOTUT;
				return;
			}
			for(i=0; i<n; i++)
			{
				flag = UT;
				for(j=0; j<i; j++)
				{
					if(mat[i][j] != 0)
						flag = NOTUT;
				}
			}
			if(flag == UT)
				cout << "Matrix is an upper triangular matrix" << endl;
			else
				cout << "Matrix is not an upper triangular matrix" << endl;
		}

		void sumdia()
		{
			int i,j;
			int sum = 0;
			if(m == n)
			{
				for(i=0; i<m; i++)
				{
					for(j=0; j<n; j++)
					{
						if(i == j)
							sum = sum + mat[i][j];
					}
				}
				cout << "Sum is" << sum << endl;
			}
			else
				cout << "Entered matrix isn't a square matrix" << endl;
		}

		void transpose()
		{
			int i,j;
			matrix mat1;
			for(i=0; i<m; i++)
			{
				for(j=0; j<n; j++)
					mat[j][i] = mat[i][j];
			}
		}

		matrix add(matrix mat2)
		{
			int i,j;
			matrix mat3(m,n);
			if(mat2.m == m && mat2.n == n)
			{
				for(i=0; i<m; i++)
				{
					for(j=0; j<n; j++)
						mat3.mat[i][j] = mat[i][j] + mat2.mat[i][j];
				}
				return mat3;
			}
			else
				cout << "The entered matrices aren't compatible for addition" << endl;

		}

		matrix sub(matrix mat2)
		{
			int i,j;
			matrix mat3(m,n);
			if(mat2.m == m && mat2.n == n)
			{
				for(i=0; i<m; i++)
				{
					for(j=0; j<n; j++)
						mat3.mat[i][j] = mat[i][j] -  mat2.mat[i][j];
				}
				return mat3;
			}
			else
				cout << "The entered matrices aren't compatible for subtraction" << endl;
		}
		matrix mul(matrix mat2)
		{
			int i,j,k;
			matrix mat3(m,mat2.n);
			
			if(n == mat2.m)
			{
				for(i=0; i<m; i++)
				{
					for(j=0; j<n; j++)
					{
						mat3.mat[i][j] = 0;
						for(k=0; k<n; k++)
							mat3.mat[i][j] = mat3.mat[i][j] + mat[i][k] * mat2.mat[k][j];
					}
				}
			return mat3;
			}
			else
				cout << "The entered matrices aren't compatible for multiplication" << endl;
		}

		void saddle()
		{
			int i,j,k;
			int min;
			int flag;
			for(i=0; i<m; i++)
			{
				min = mat[i][0];
				for(j=1; j<n; j++)
				{
					if(min < mat[i][j])
						continue;
					else
						min = mat[i][j];
				}
				for(k=0; k<n; k++)
				{
					if(min < mat[i][j])
						flag = NOTFOUND;
					else
						flag = FOUND;
				}
			}
			if(flag == FOUND)
				cout << "Saddle point is " << min << endl;
			else
				cout << "No saddle point" << endl;
		}
};

int main()
{
	matrix m;
	matrix m1,m2;
	matrix m3;
	int choice;
	while(1)
	{
		cout << "Enter choice: 1 for upper triangular, 2 for sum of diagonal elements, 3 for transpose, 4 for addition, 5 for subtraction, 6 for multiplication, 7 for saddle pt " << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				m.create();
				m.display();
				m.uptri();
				break;
			case 2:
				m.create();
				m.display();
				m.sumdia();
				break;
			case 3:
				m.create();
				m.display();
				m.transpose();
				m.display();
				break;
			case 4:
				m1.create();
				m1.display();
				m2.create();
				m2.display();
				m3 = m1.add(m2);
				m3.display();
			case 5:
				m1.create();
				m1.display();
				m2.create();
				m2.display();
				m3 = m1.sub(m2);
				m3.display();
			case 6:
				m1.create();
				m1.display();
				m2.create();
				m2.display();
				m3 = m1.mul(m2);
				m3.display();
				break;
			case 7:
				m.create();
				m.display();
				m.saddle();
				break;
			default:
				cout << "Invalid choice code" << endl;
				return 0;
		}
	}
}

