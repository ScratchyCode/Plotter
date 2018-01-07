#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tinyexpr.h"

#define DIM 10000

int control(void){
    char path[] = "/usr/bin/gnuplot";
    
    FILE *pf = fopen(path,"r");
    if(pf == NULL){
        fclose(pf);
        return 1;
    }else{
        fclose(pf);
        return 0;
    }
}

int main(void){
    long double inf, sup, inc;
    double x, y;
    te_variable vars[] = {{"x",&x}};
    char expression[DIM];
    
    // control that gnuplot is present on system
    int gnupl = control(), i;
    if(gnupl == 1){
        printf("\nYou need gnuplot to graph the results.");
        printf("\nInstall it with: sudo apt-get install gnuplot\n\n");
        exit(2);
    }

    printf("\nEnter the analytical expression of f(x): ");
    fgets(expression,DIM,stdin);
    
    printf("Enter the lower abscissa (INF) of f(x): ");
    scanf("%llf",&inf);
    
    printf("Enter the upper abscissa (SUP) of f(x): ");
    scanf("%llf",&sup);
    
    printf("Enter the increment to represent: ");
    scanf("%llf",&inc);
    
    FILE *output = fopen("graph.dat","w");
    if(output == NULL){
        perror("\nError");
        printf("\n");
        exit(1);
    }
    
    printf("\nCalculating...\n");
    
    x = inf;
    
    do{
        int err;
        
        te_expr *n = te_compile(expression, vars, 1, &err);
        
        if(n){
            x += inc;
            y = te_eval(n);
            fprintf(output,"%lf\t%lf\n",x,y);
            te_free(n);
        }else{
            printf("\t%*s^\nError", err-1, "");
            exit(1);
        }
    }while(x <= sup);
    
    printf("End.\n");
    
    fflush(output);
    fclose(output);
    
    return 0;
}
