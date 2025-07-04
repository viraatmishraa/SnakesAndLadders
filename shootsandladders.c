//press alt+z for better readibility (works in vs code)
#include <stdio.h>
int move(int);
void printGrid();
typedef struct playerpos
{
int x,y,position;
char previousA, previousB, nextX, nextY;

}player;
player p1;
player p2;

// player * p1=NULL;
// player * p2=NULL;

char grid[31][61]=
{
"-------------------------------------------------------------",
"|100   |M 99|   98|   97|   96|   95|   94|   93|   92|   91|",
"|     (' ') |     |     |     |     |  X-X|     |     |     |",
"------X X-------------------------------X-X------------------",
"| 81  /0/ 82|   83|   84|   85|   86|  84X-X  88|   89|   90|",
"|     X X   |     |     |     |     |     X-X   |     |     |",
"------/0/----------------------------------X-X---------------",
"| 80  X X 79|   78|   77|   76|   75|  74 | X-X |   72|   71|",
"|     /0/   |     |     |     |     |     | 73  |     |     |",
"----- X X ---------------------------------------------------",
"| 61  /0/ 62|   63|   64|   65|   66|   67|   68|   69|   70|",
"|     X X   |   X-X     |     |  M  |     |     |     |     |",
"------/0/--------X-X-----------(^ ^)-------------------------",
"| 60  X X 59|   58X-X57 |   56|/ /  |   54| 53  |   52|   51|",
"|     /0/   |     |X-X  |     ( ) 55|     |  /-/|     |     |",
"------X X-----------X-X------/ /------------/-/--------------",
"| 41  /0/ 42|   43|  X-X|45 ( )   46|   47|/-/48|49  M|   50|",
"|     X X   |     | 44X-X  / /|     |     /-/   |  [' ']    |",
"------/0/--------------X-X( )------------/-/--------X X------",
"| 40  X X 39|   38|   37X/ /36|   35| 34/-/   33|  32X X  31|",
"|     /0/   |     |     ( )X  |     |  /-/|     |     X     |",
"------X X--------------/ /X-X---------/-/--------------------",
"| 21  /0/ 22|   23| 22( )  X-X|   26|/-/27|   28|   29|   30|",
"|     X X   |     |  / /|   25|     /-/   |     |     |     |",
"------/0/-----------( )------------/-/-----------------------",
"| 20  X X 19|   18|   17|   16|   /-/   14|   13|   12|   11|",
"|     |     |     |     |     |15   |     |     |     |     |",
"-------------------------------------------------------------",
"|    1|    2|    3|    4|    5|    6|    7|    8|    9|   10|",
"|p1 p2|     |     |     |     |     |     |     |     |     |",
"-------------------------------------------------------------"
};
int moder=1;

int main()
{
p1.x=1;
p1.y=29;
p1.previousA=" ";
p1.previousB=" ";
p2.x=4;
p2.y=29;
p2.previousA=" ";
p2.previousB=" ";

}


//instead of calling movement function once, and no. of steps as a parameter, i will call movement function n times which intern help me to reduce work for animation and also makes the alternating row direction problem a lot simple
int move(int player)
{
if(player==1)
    {
    if(p1.position%10==0/*we want to change y,  cause pointer at 10 or 1*/)
        {
        // we will change the x-coordinate modification symbol by multiplying -1 to the mod-er
        moder*=-1;
       
        // we want to unprint from last location i.e position before modification
        grid[p1.x][p1.y]=p1.previousA;
        grid[p1.x+1][p1.y]=p1.previousB;
       
        // we will move y one up (y-3 in this case),
        p1.y=p1.y+3;
        
        // we want to store what is in the next block in the previous A & B of the structure
        p1.previousA=grid[p1.x][p1.y];
        p1.previousB=grid[p1.x+1][p1.y];
        
        // we want to print to mod location, moving player 1
        grid[p1.x][p1.y]='p';
        grid[p1.x+1][p1.y]='1';
        
        //updating postion
        p1.position++;

        //we will update the grid
        printGrid();
        
        //return
        return;
        }
    else//(/*we want to change x cause pointer in betweeen 1 and 10*/)
        {
            
        // we want to unprint from last location i.e position before modification
        grid[p1.x][p1.y]=p1.previousA;
        grid[p1.x+1][p1.y]=p1.previousB;
            
        //we will x+(mod_er) ((x+mode_er)*6 in this case)
        p1.x=p1.x+(moder*6);// this line decides the direction of insertion for' p1' and updates x coordinate accordingly
            
        // we want to store what is in the next block in the previous A & B of the structure
        p1.previousA=grid[p1.x][p1.y];
        p1.previousB=grid[p1.x+1][p1.y];
        
        // we want to print to mod location, moving player 1
        grid[p1.x][p1.y]='p';
        grid[p1.x+1][p1.y]='1';

        //updating postion
        p1.position++;

        //we will update the grid
        printGrid();
        
        //return
        return;
        }
    }
else 
if(player==2)
    if(p2.position%10==0/*we want to change y,  cause pointer at 10 or 1*/)
        {
        // we will change the x-coordinate modification symbol by multiplying -1 to the mod-er
        moder*=-1;
       
        // we want to unprint from last location i.e position before modification
        grid[p2.x][p2.y]=p2.previousA;
        grid[p2.x+1][p2.y]=p2.previousB;
       
        // we will move y one up (y-3 in this case),
        p2.y=p2.y+3;
        
        // we want to store what is in the next block in the previous A & B of the structure
        p2.previousA=grid[p2.x][p2.y];
        p2.previousB=grid[p2.x+1][p2.y];
        
        // we want to print to mod location, moving player 1
        grid[p2.x][p2.y]='p';
        grid[p2.x+1][p2.y]='1';
        
        //updating postion
        p2.position++;

        //we will update the grid
        printGrid();
        
        //return
        return;
        }
    else//(/*we want to change x cause pointer in betweeen 1 and 10*/)
        {
            
        // we want to unprint from last location i.e position before modification
        grid[p2.x][p2.y]=p2.previousA;
        grid[p2.x+1][p2.y]=p2.previousB;
            
        //we will x+(mod_er) ((x+mode_er)*6 in this case)
        p2.x=p2.x+(moder*6);// this line decides the direction of insertion for' p2' and updates x coordinate accordingly
            
        // we want to store what is in the next block in the previous A & B of the structure
        p2.previousA=grid[p2.x][p2.y];
        p2.previousB=grid[p2.x+1][p2.y];
        
        // we want to print to mod location, moving player 1
        grid[p2.x][p2.y]='p';
        grid[p2.x+1][p2.y]='1';

        //updating postion
        p2.position++;

        //we will update the grid
        printGrid();
        
        //return
        return;
        }
    }
