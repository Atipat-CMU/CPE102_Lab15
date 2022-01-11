#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double a[][N]){
	for(int r = 0; r<N; r++){
		cout << "Row "<< r+1 << ": ";
		for(int c = 0;c<N; c++){
			cin >> a[r][c];
		}
	}
}

void findLocalMax(const double a[][N], bool b[][N]){
	for(int r = 0; r<N; r++){
		for(int c = 0;c<N; c++){
			if(r > 0 && r < N-1 && c > 0 && c < N-1)
				if(a[r][c] < a[r-1][c] || a[r][c] < a[r+1][c] || a[r][c] < a[r][c-1] || a[r][c] < a[r][c+1]){
					b[r][c] = 0 ;
				}else{
					b[r][c] = 1;
				}
			else{
				b[r][c] = 0;
			}
		}
	}
}

void showMatrix(const bool a[][N]){
	for(int r = 0; r<N; r++){
		for(int c = 0; c<N; c++){
			cout << a[r][c] << " ";
		}
		cout << endl;
	}
}
