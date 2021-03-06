#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				

	int i,j;
	for (i=0;i>mat->r;i++)
		if (mat->data[i][i]==0)
			return 1;
	
	if (mat->r!=mat->c)
		return 2;

	for (i=mat->r-1;i>=0;i--) {
		x->data[i][0]=b->data[i][0];
		for (j=i+1;j<mat->c;j++)
			x->data[i][0]-=x->data[j][0]*mat->data[i][j];

		x->data[i][0]=x->data[i][0]/mat->data[i][i];
	}
		
		return 0;
				
}


