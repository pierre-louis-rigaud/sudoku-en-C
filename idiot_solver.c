#include <stdio.h>
#include "strsplit.h"
#include "fonctions.h"

int idiot_solver(sudoku *sud)
{
    int running = 1;
    int segment = 1;
    int x = 0;
    int y = 0;
    while (running)
    {
        running = 0;
        segment = 0;
        segment += segment(sud);
        running += clib_nu(sud);
        running += clib_cache(sud);
        if (running != 0)
        {
            gridasse(sud);
        }
    }
    if (case_vide(sud -> gridClone, &x, &y) == 0)
        return 1;
    return 0;
        
        
}