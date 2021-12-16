#include "gauss.h"
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{	
	int i,j;
	Matrix *m1 = createMatrix( mat->r, mat->c + 1);  //polaczona maciorka
 	for (i = 0; i < m1->r; i++) 			// zapelnianie macierzy 
	{
		for (j = 0; j < mat->c; j++)
			m1->data[i][j] = mat->data[i][j];

		m1->data[i][j] = b->data[i][0];
	}
	
	int m;
	for(i = 0; i < m1->r-1; i++)  				// przejscie po kolumnach
	{
		double max = m1->data[i][i];
		int i_max;
		for( j = i+1; j < m1->r; j++)			// szukanie max wartosci w kolumnie
		{	if(abs(m1->data[j][i]) > abs(max))
			{	
				max = m1->data[j][i];
				i_max=j;
			}
		}
			
		if( max == 0)	return 1;

		for(m = 0; m < m1->c; m++)			// zamiana wierszy
		{
			double temp;
			temp = m1->data[i_max][m];
			m1->data[i_max][m] = m1->data[i][m];
			m1->data[i][m] = temp;
		}
//yyyyy??			
		

		for( j = i+1; j < m1->r; j++)			// odejmowanie pomnozonej przez wartosc
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

