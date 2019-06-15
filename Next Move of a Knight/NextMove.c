    /* In this C program, we will take a position of a knight from user 
       and show the next possible move on the chess board. 
       Selen KUTANOGLU 
       April 2017 */
       
    #include <stdio.h>

    void print_chess_board(int chess_board[8][8]);              //Prints all 8x8 chess board
    void next_move(int chess_board[8][8],int x, int y);         //function prototype

    int main()
    {
        int chess_board[8][8],x,y;                              //x -> row  y -> column

        printf("~ Next Move of Knight ~\nChoose coordinate from 8x8 chess board(1-8)\n");
        print_chess_board(&chess_board);

        while(1)                                                //Run till the user enter the valid coordinate
        {
            printf("\nEnter the x(row) coordinate: ");
            scanf("%d",&x);

            printf("Enter the y(column) coordinate: ");
            scanf("%d",&y);

            if(x<=0 || y<=0 || x>8 || y>8)                      //Checks the values in case being invalid
                printf("\nValues you entered is not between 1-8.\n");
            else
                break;
        }

        chess_board[--x][--y]=0;                                //Given coordinate reseted
        next_move(chess_board,x,y);                             //Call function for next move

        print_chess_board(chess_board);
        printf("\nLocation of the knight showed by 1.\nPossible next moves showed by 9.\n");
        return 0;
    }

    void print_chess_board(int chess_board[8][8]){
        int i,j;
        for (i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
                printf("%d ",chess_board[i][j]);
            printf("\n");
        }
    }

    void next_move(int chess_board[][8],int x,int y){           //Checks the all possible L moves of the knight
        if (x-2>=0 && y+1<8)
            chess_board[x-2][y+1]=9;

        if (x-2>=0 && y-1>=0)
            chess_board[x-2][y-1]=9;

        if (x-1>=0 && y+2<8)
            chess_board[x-1][y+2]=9;

        if (x-1>=0 && y-2>=0)
            chess_board[x-1][y-2]=9;

        if (x+1<8 && y+2<8)
            chess_board[x+1][y+2]=9;

        if (x+1<8 && y-2>=0)
            chess_board[x+1][y-2]=9;

        if (x+2<8 && y+1<8)
            chess_board[x+2][y+1]=9;

        if (x+2<8 && y-1>=0)
            chess_board[x+2][y-1]=9;
    }
