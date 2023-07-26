#include "fonctions.h"


int segment2(sudoku *sud)
{
    int return_value = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sud->gridClone[i][j] == 0)
            {
                for (int n = 1; n < 10; n++)
                {
                    int cube_Lsegment[3];
                    int cube_Csegment[3];

                    for (int b = 0; b < 3; b++)
                    {
                        cube_Lsegment[b] = 0;
                        cube_Csegment[b] = 0;
                    }

                    int _i = 3 * (i / 3);
                    int _j = 3 * (j / 3);

                    for (int x = _i; x < _i + 3; x++)
                    {
                        for (int y = _j; y < _j + 3; y++)
                        {
                            for (int q = 0; q < 9; q++)
                            {   
                                if (sud->megaTab[q][j][n - 1] == 1)
                                {
                                    cube_Lsegment[q / 3]++;                                    
                                }
                                if (sud -> megaTab[i][q][n - 1] == 1)
                                {
                                    cube_Csegment[q / 3]++;
                                }
                            }
                        }
                    }
                    int incr_ligne = 0;
                    int incr_colonne = 0;

                    for (int k = 0; k < 3; k++)
                    {
                        if (cube_Lsegment[k] > 0)
                        {
                            incr_ligne++;
                        }
                        if (cube_Csegment[k] > 0)
                        {
                            incr_colonne++;
                        }
                    }
                    int index_i = i / 3;
                    int index_j = j / 3;
                    int xprime = index_i * 3;
                    int yprime = index_j * 3;

                    if (incr_ligne == 1 && cube_Lsegment[index_i] > 1)
                    {
                        for (int e = 0; e < 9; e++)
                        {   
                            for (int f = xprime; f < xprime + 3; f++)
                            {
                                if (index_i != e / 3)
                                {
                                    if (sud->megaTab[e][f][n - 1] == 1)
                                        return_value++;
                                    sud->megaTab[e][f][n - 1] = 0;
                                }
                            }
                            
                        }
                    }
                    if (incr_colonne == 1 && cube_Lsegment[index_j] > 1)
                    {
                        for (int e = 0; e < 9; e++)
                        {   
                            for (int f = yprime; f < yprime + 3; f++)
                            {
                                if (index_j != e / 3)
                                {
                                    if (sud->megaTab[e][f][n - 1] == 1)
                                        return_value++;
                                    sud->megaTab[e][f][n - 1] = 0;
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return return_value;
}                    