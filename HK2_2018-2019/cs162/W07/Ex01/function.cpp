/*
 * function.cpp
 *
 *  Created on: Mar 28, 2019
 *      Author: huy
 */

#include"function.h"

void res_fibo(int n){
	int *f=new int[n+1];
	for (int i=0;i<=n;++i)
		f[i]=0;
	cout<<fibo(n,f);
	delete[] f;
}
int fibo(int n,int *&f){
	if (f[n]!=0) return f[n];
	if (n==0||n==1) {
		f[n]=1;
		return f[n];
	}
	f[n]=fibo(n-1,f)+fibo(n-2,f);
	return f[n];
}

//////////////////////////

void res_Xn_Yn(int n){
	int *X=new int[n+1];
	int *Y=new int[n+1];
	setup_Xn_Yn(n,X,Y);
	cout<<X[n]<<" "<<Y[n];
	delete[] X;
	delete[] Y;
}

void setup_Xn_Yn(int n,int *&X,int *&Y){
	if (n==0){
		X[n]=1;
		Y[n]=0;
		return;
	}
	setup_Xn_Yn(n-1,X,Y);
	X[n]=X[n-1]+Y[n-1];
	Y[n]=3*X[n-1]+2*Y[n-1];
}

//////////////////////////////

void res_Xn(int n){
	int *X=new int[n+1];
	setup_Xn(n,X);
	cout<<X[n];
	delete[] X;
	return;
}

void setup_Xn(int n,int *&X){
	if (n==0) {
		X[n]=1;
		return;
	}
	setup_Xn(n-1,X);
	for (int i=0;i<n;++i){
		X[n]+=(n-i)*(n-i)*X[i];
	}
}

/////////////////////////////

void res_Ckn(int k,int n){
	int **C;
	C=new int *[k+1];
	for (int i=0;i<=k;++i)
		C[i]=new int[n+1];
	for (int i=0;i<=k;++i)
		for (int j=0;j<=n;++j)
			C[i][j]=0;
	cout<<get_Ckn(k,n,C);
	for (int i=0;i<=k;++i)
		delete[] C[i];
	delete[] C;
}

int get_Ckn(int k,int n,int **&C){
	if (k==1||k==n) {
		C[k][n]=n;
		return C[k][n];
	}
	if (C[k][n]!=0) return C[k][n];
	C[k][n]=get_Ckn(k,n-1,C)+get_Ckn(k-1,n-1,C);
	return C[k][n];
}

/////////////////////////////////

void to_binary(int x){
	if (x==0) return;
	to_binary(x/2);
	cout<<x%2;
}

//////////////////////////////////

int sum_of_ditgits(int x){
	if (x==0) return 0;
	return x%10+sum_of_ditgits(x/10);
}