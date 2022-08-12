#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /* declaration made */
	
    char array[11][11]={ }, userdirect;
    int i,n=0,x,userlength, turtleset='T', positionx=5, positiony=5;

    memset(&array, '0', sizeof(array));     /* clear all characters in that array */

    printf("\n\t********** Turtle game ******************\n\n");

    printf("\n");
    array[5][5] = turtleset;    /* the turtle will always start at the middle */

    /* for loop to print the board */
	
        for(i=0; i<11; i++)
        {
            for(x=0; x<11; x++)
            {
                printf(" %c ",array[i][x]);
            }
            printf("\n");
        }

    while(n==0)
    {
        /* user input required */
		
        printf("\nYour direction(U/R/D/L): ");
        scanf("%c", &userdirect);
        printf("\nHow far: ");
        scanf("%i", &userlength);
        fflush(stdin);  /* clear keyboard buffer */


        if (userdirect=='u'||userdirect=='U')
        {
            for(i=positionx; i>(positionx-userlength); i--)     /* prints * whenever T pass through the position where T went */
                array[i][positiony]='*';

            positionx -= userlength;    /* positionx = positionx - userlength */

            array[positionx][positiony] = turtleset;    /* get the position of the turtle in correct coordinate */

        }
        else if (userdirect=='R'||userdirect=='r')
        {
            for(i=positiony; i<(positiony+userlength); i++)     /* prints * whenever T pass through the position where T went */
                array[positionx][i]='*';

            positiony += userlength;    /* positiony = positiony + userlength */

            array[positionx][positiony] = turtleset;    /* get the position of the turtle in correct coordinate */
        }
        else if (userdirect=='D'||userdirect=='d')
        {

            for(i=positionx; i<(positionx+userlength); i++)
                array[i][positiony]='*';

            positionx += userlength;    /*  positionx = positionx + userlength */

            array[positionx][positiony] = turtleset;    /* get the position of the turtle in correct coordinate */
        }
        else if (userdirect=='L'||userdirect=='l')
        {

            for(i=positiony; i>(positiony-userlength); i--)     /* prints * whenever T pass through the position where T went */
                array[positionx][i]='*';

            positiony -= userlength;    /* positiony = positiony - userlength */

            array[positionx][positiony] = turtleset;    /* get the position of the turtle in correct coordinate */
        }
        else
            printf("Wrong Input! Please try again!\n");     /* prints error msg if user input a wrong value */

        userlength=0;   /* resets the userlength */

        /* prints the final result */
        
		for(i=0; i<11; i++)
            {
                for(x=0; x<11; x++)
                {
                    printf(" %c ",array[i][x]);
                }
                printf("\n");
            }

    }
    return 0;
}

