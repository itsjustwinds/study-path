/*
 * function.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: huy
 */

#include"function.h"

void back_track(int stage,int *&resX,int *&resY, int *&row,int *&col,int *&fDia,int *&sDia,int &ok){
	if (stage==8) {
		ok=1;
		for (int i=0;i<8;++i)
			cout<<resX[i]+1<<" "<<resY[i]+1<<"\n";
		return;
	}
	if (ok) return;
	for (int j=0;j<8;++j){
		if (row[stage]||col[j]||fDia[stage-j+8]||sDia[stage+j]) continue;
		row[stage]=col[j]=fDia[stage-j+8]=sDia[stage+j]=1;
		resX[stage]=stage;
		resY[stage]=j;
		back_track(stage+1,resX,resY,row,col,fDia,sDia,ok);
		row[stage]=col[j]=fDia[stage-j+8]=sDia[stage+j]=0;
	}
}

void init(){
	int *resX=new int[8];
	int *resY=new int[8];
	int *row=new int[8];
	int *col=new int[8];
	int *fDia=new int[16];
	int *sDia=new int[15];
	int ok=0;
	back_track(0,resX,resY,row,col,fDia,sDia,ok);
	delete[] resX;
	delete[] resY;
	delete[] row;
	delete[] col;
	delete[] fDia;
	delete[] sDia;
}
