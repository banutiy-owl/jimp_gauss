#include "gauss.h"
#include <math.h>

/**
 *
 *
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int max (Matrix *mat, int n_k) {
	double m = mat->data[0][0];
		int index_max;
		for( int j = n_k+1; j < mat->r; j++)
		{	if(mat->data[j][n_k] > m)
			{	
				m = mat->data[j][n_k];
				index_max=j;
			}
		}
		if(m==0.0)
			return -1;
		else
			return index_max;
}

int eliminate(Matrix *mat, Matrix *b)
{	
	int i,j;
	Matrix *m1 = createMatrix( mat->r, mat->c + 1); 
 	for (i = 0; i < m1->r; i++) 			
	{
		for (j = 0; j < mat->c; j++)
			m1->data[i][j] = mat->data[i][j];

		m1->data[i][j] = b->data[i][0];
	}
	
			
		if( max == 0)	return 1;

		for(m = 0; m < m1->c; m++)		
		{
			double temp;
			temp = m1->data[i_max][m];
			m1->data[i_max][m] = m1->data[i][m];
			m1->data[i][m] = temp;
		}
		
		

		for( j = i+1; j < m1->r; j++)			
		{
			if(m1->data[j][i] == 0)		continue;
			double dzielnik = m1->data[j][i] / m1->data[i][i];
			for( m = 0; m < m1->c; m++)
			{	
				m1->data[j][m] -=m1->data[i][m] * dzielnik;
			}
		}	
		
	}		

	for(i = 0; i < mat->r; i++)
	{	for( j = 0; j < mat->c; j++)
        		mat->data[i][j] = m1->data[i][j];
		b->data[i][0] = m1->data[i][j];
   	}

		return 0;
}

