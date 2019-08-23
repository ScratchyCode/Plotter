// Coded by ScratchyCode
    
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*** FUNCTIONS ***/
//#define f(x,y) sqrt(1 - ((x*x) + (y*y))) // semisfera positiva
#define f(x,y) (sin((x*x) + (y*y))/((x*x) + (y*y)))
//#define f(x,y) ((x*x) - (y*y)) // pringles
//#define f(x,y) ((x*x*x) - (4*x*y*y))
//#define f(x,y) ((x*y)/((x*x) + (y*y))) // singolare in (0,0)
//#define f(x,y) (((x-2)*(x-2)*(y-1))/(((x-2)*(x-2)*(x-2)*(x-2)) + ((y-1)*(y-1))))

void checkPtr(void *ptr);

int main(){
    double xinf, xsup, yinf, ysup;
    double xinc, yinc;
    double x, y, z;
    
    printf("Enter the lower x: ");
    scanf("%lf",&xinf);
    
    printf("Enter the upper x: ");
    scanf("%lf",&xsup);
    
    printf("Enter the lower y: ");
    scanf("%lf",&yinf);
    
    printf("Enter the upper y: ");
    scanf("%lf",&ysup);
    
    printf("Enter the increment for x: ");
    scanf("%lf",&xinc);
    
    printf("Enter the increment for y: ");
    scanf("%lf",&yinc);
    
    // check parameters
    if(xinc <= 0 || yinc <= 0 || xinf >= xsup || yinf >= ysup){
        fprintf(stderr,"\n*** invalid parameters ***\n");
        exit(1);
    }
    
    FILE *output = fopen("graph.dat","w");
    checkPtr(output);
    
    // estimate elaboration percentage
    int progress = 0;
    double runs = fabs(xsup - xinf)/xinc;
    
    printf("\n");
    
    x = xinf;
    do{
        progress++;
        fprintf(stderr,"\rcalculating:\t\t%2d%%",(int)(progress*100./runs));
        
        y = yinf;
        do{
            z = f(x,y);
            fprintf(output,"%lf\t%lf\t%lf\n",x,y,z);
            y += yinc;
        }while(y <= ysup);
        
        x += xinc;
    }while(x <= xsup);
    
    fprintf(stderr,"\n\n*** done ***");
    fflush(output);
    fclose(output);
    
    // plotting
    fprintf(stderr,"\n*** plotting ***\n");
    
    system("gnuplot script.gp");
    
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

