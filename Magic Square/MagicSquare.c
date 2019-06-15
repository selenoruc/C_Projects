    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        int num,val=0,x,i=0,j=0;
        do{
            printf("Enter the size of block : ");//get the size from user
            scanf("%d",&num);
        }while(num < 3);

        int block[num][num];
        int *ptr=block;
        for(x=0;x<num*num;x++)//reset the block via pointer
            *(ptr+x)=0;

        if(num%2==1){//means the number is odd
            srand(time(NULL));
            int temp=rand()%num;//
            i=temp;//assign i to random numbers
            j=((num-1)/2)+temp;//assign j to the middle top coordinate of the block
            j=j%num;//if j out of the block we need to move it inside of the block :)

            printf("%d - %d coordinate chosen. :)\n\n",i+1,j+1);

            while(val<num*num){
                if(block[(i+1)%num][(j+1)%num]!=0)
                    j--;//means its full and move it one square left
                if(j<0)//don't want to get a negative coordinate
                    j=num-1;

                if(block[i][j]==0)//check if its empty
                    block[i][j]=++val;

                if(++i==num)//check if out of the block
                    i=i%num;
                if(++j==num)
                    j=j%num;

                if(block[i][j]==0)//assignment
                    block[i][j]=++val;
            }
        }

        if(num%2==0 && (num/2)%2==0){//means the size/2 is even and we need to divide the block to 9 parts
            for(i=0;i<(num/4);i++){//First main part
                for(j=0;j<(num/4);j++)
                    block[i][j]=++val;
                for(;j<((3*num)/4);j++)//assign it  to the symmetric position on block
                    block[num-1-i][num-1-j]=++val;
                for(;j<num;j++)
                    block[i][j]=++val;
            }

            for(;i<((3*num)/4);i++){//Second main part
                for(j=0;j<(num/4);j++)
                    block[num-1-i][num-1-j]=++val;
                for(;j<((3*num)/4);j++)
                    block[i][j]=++val;
                for(;j<num;j++)
                    block[num-1-i][num-1-j]=++val;
            }

            for(;i<num;i++){//Third main part
                for(j=0;j<(num/4);j++)
                    block[i][j]=++val;
                for(;j<((3*num)/4);j++)
                    block[num-1-i][num-1-j]=++val;
                for(;j<num;j++)
                    block[i][j]=++val;
            }
        }

        for(i=0;i<num;i++){//print the block
            printf("\n");
            for(j=0;j<num;j++)
                printf("%3d ",block[i][j]);
        }

        printf("\n\n\nVertically, horizontally and diagonally sum is %d \n",(((num*num*num)+num)/2));

        return 0;
    }
