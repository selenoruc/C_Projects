    /* Bisection Method methods uses two point of a third-order function to find the root. 
       Takes two parameter from user and starts to calculate root with the given percent 
       margin of error(default 0.01).
       Selen KUTANOGLU 
       April 2017 */

    #include <stdio.h>
    #include <math.h>
    double function(int coef_a,int coef_b,int coef_c,int coef_d,double variable_x);
    /* Prototype of a third-order function which based on variable_x and has 4 coefficient (a,b,c,d) */

    int main()
    {
        int coefficient_a,coefficient_b,coefficient_c,coefficient_d;//coefficients of the function
        double start_point,start_result,finish_point,finish_result,average_point,average_result,tolerance = 0.01;//Default 0.01
        /*  start_result:function result of the start point
            finish_result:function result of the finish point
            average_result:function result of the average point  */

        printf("Find the root of a third-order function with Bisection Method \nFunction: f(x)= ax^3 + bx^2 + cx + d\n");
        //Intro

        printf("Enter a b c d values : ");
        scanf("%d%d%d%d",&coefficient_a,&coefficient_b,&coefficient_c,&coefficient_d);
        
        /* User can choose the tolerance */
        //printf("Enter the tolerance: "); 
        //scanf("%lf",&tolerance);

        while(1)//Checks the range until be sure of there is a root in given range
        {
            printf("Enter the start point:");
            scanf("%lf",&start_point);

            start_result=function(coefficient_a,coefficient_b,coefficient_c,coefficient_d,start_point);

            printf("Enter the finish point:");
            scanf("%lf",&finish_point);

            finish_result=function(coefficient_a,coefficient_b,coefficient_c,coefficient_d,finish_point);

            if(start_result*finish_result>0){//start_result*finish_result>0 case shows there is no root in given range
                printf("\n[%.2f, %.2f] Root not found in the given range.\n",start_point,finish_point);
                printf("\nEnter range again.\n");
            }
            else//Shows there is a root so we should break the while loop
                break;
        }

        printf("\n[%.2f, %.2f] Root found in given range.\n",start_point,finish_point);//Print info on the screen
        int i = 0;//Will keep the iteration count

     while(1)//Run until find the root of the function with given tolerance distance
        {
            average_point=(start_point+finish_point)/2;                     /* Calculation part */
            start_result=function(coefficient_a,coefficient_b,coefficient_c,coefficient_d,start_point);
            finish_result=function(coefficient_a,coefficient_b,coefficient_c,coefficient_d,finish_point);
            average_result=function(coefficient_a,coefficient_b,coefficient_c,coefficient_d,average_point);
            printf("%2d - start_result = %.2f,\tfinish_result = %.2f,\taverage_result = %.2f\n",i+1,start_result,finish_result,average_result);
            
            if(start_result==0){
                average_point=start_point;
                break;
            }
            else{
                if(finish_result==0){
                    average_point=finish_point;
                    break;
                }
                else{
                    if(average_result==0){
                        break;
                    }
                    else{
                        if(start_result*average_result<0){
                            //Means the root is between the start and average point
                            finish_point=average_point;
                        }
                        else{
                            //Means the root is between the finish and average point
                            start_point=average_point;
                        }
                        if(finish_point-start_point<tolerance){
                            //Means we are as close to root as given tolerance
                            break;
                        }
                        else{//otherwise it will continue to search
                            i++;
                        }
                    }
                }
            }
        }
        printf("\nRoot in given range : %.4f\n",average_point);
    }

    double function(int coef_a,int coef_b,int coef_c,int coef_d,double variable_x){
        //Calculation part of the function
        return (coef_a*pow(variable_x,3))+(coef_b*pow(variable_x,2))+(coef_c*variable_x)+coef_d;
    }