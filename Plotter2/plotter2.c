// Coded by ScratchyCode
    
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FUNCTION.h"

void checkPtr(void *ptr);

int main(){
    long double xinf, xsup, yinf, ysup;
    long double xinc, yinc;
    long double x, y, z;
    
    printf("Enter the lower x: ");
    scanf("%llf",&xinf);
    
    printf("Enter the upper x: ");
    scanf("%llf",&xsup);
    
    printf("Enter the lower y: ");
    scanf("%llf",&yinf);
    
    printf("Enter the upper y: ");
    scanf("%llf",&ysup);
    
    printf("Enter the increment for x: ");
    scanf("%llf",&xinc);
    
    printf("Enter the increment for y: ");
    scanf("%llf",&yinc);
    
    // check parameters
    if(xinc <= 0 || yinc <= 0 || xinf >= xsup || yinf >= ysup){
        fprintf(stderr,"\n*** invalid parameters ***\n");
        exit(1);
    }
    
    FILE *output = fopen("graph.dat","w");
    checkPtr(output);
    
    // estimate elaboration percentage
    int progress = 0;
    double runs = (double)fabsl(xsup - xinf)/xinc;
    
    printf("\n");
    
    x = xinf;
    do{
        progress++;
        fprintf(stderr,"\rcalculating:\t\t%2d%%",(int)(progress*100./runs));
        
        y = yinf;
        do{
            z = f(x,y);
            fprintf(output,"%llf\t%llf\t%llf\n",x,y,z);
            y += yinc;
        }while(y <= ysup);
        
        x += xinc;
    }while(x <= xsup);
    
    /*
    // per plottare la sfera intera
    #define f(x,y) -sqrt(1 - ((x*x) + (y*y))) // semisfera negativa
    progress = 0;

    x = xinf;
    do{
        progress++;
        fprintf(stderr,"\rcalculating:\t\t%2d%%",(int)(progress*100./runs));
        
        y = yinf;
        do{
            z = f(x,y);
            fprintf(output,"%llf\t%llf\t%llf\n",x,y,z);
            y += yinc;
        }while(y <= ysup);
        
        x += xinc;
    }while(x <= xsup);
    */
    
    //fprintf(stderr,"\n\n*** done ***\n");
    fprintf(stderr,"\n");
    fflush(output);
    fclose(output);
    
    return 0;
}

void checkPtr(void *ptr){
    
    if(ptr == NULL){
        perror("\nERROR");
        fprintf(stderr,"\n");
        exit(0);
    }
    
    return;
}

