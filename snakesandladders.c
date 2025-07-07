//press alt+z for better readibility (works in vs code)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int move(int);
void printGrid();
typedef struct playerpos
{
int x,y,position;
char previousA, previousB, nextX, nextY;

}player;
player p1;
player p2;


void printGrid();
int diceRoll();//requires stdlib and time
int SkeletalAlgorithm();
int Snake99_19();
int Snake66_17();
int Snake49_31();
int ladder17_66();
int ladder06_53();
// player * p1=NULL;
// player * p2=NULL;

char grid[31][61]=
{
"-------------------------------------------------------------",
"|100   |M 99|   98|   97|   96|   95|   94|   93|   92|   91|",
"|     (' ') |     |     |     |     |  \\-\\|     |     |     |",
"------\\ \\-------------------------------\\-\\------------------",
"| 81  /0/ 82|   83|   84|   85|   86|  84\\-\\  88|   89|   90|",
"|     \\ \\   |     |     |     |     |     \\-\\   |     |     |",
"------/0/----------------------------------\\-\\---------------",
"| 80  \\ \\ 79|   78|   77|   76|   75|  74 | \\-\\ |   72|   71|",
"|     /0/   |     |     |     |     |     | 73  |     |     |",
"----- \\ \\ ---------------------------------------------------",
"| 61  /0/ 62|   63|   64|   65|   66|   67|   68|   69|   70|",
"|     \\ \\   |   \\-\\     |     |  M  |     |     |     |     |",
"------/0/--------\\-\\-----------(^ ^)-------------------------",
"| 60  \\ \\ 59|   58\\-\\57 |   56|/ /  |   54| 53  |   52|   51|",
"|     /0/   |     |\\-\\  |     ( ) 55|     |  /-/|     |     |",
"------\\ \\-----------\\-\\------/ /------------/-/--------------",
"| 41  /0/ 42|   43|  \\-\\|45 ( )   46|   47|/-/48|49  M|   50|",
"|     \\ \\   |     | 44\\-\\  / /|     |     /-/   |  [' ']    |",
"------/0/--------------\\-\\( )------------/-/--------\\ \\------",
"| 40  \\ \\ 39|   38|   37\\/ /36|   35| 34/-/   33|  32\\ \\  31|",
"|     /0/   |     |     ( )\\  |     |  /-/|     |     \\     |",
"------\\ \\--------------/ /\\-\\---------/-/--------------------",
"| 21  /0/ 22|   23| 22( )  \\-\\|   26|/-/27|   28|   29|   30|",
"|     \\ \\   |     |  / /|   25|     /-/   |     |     |     |",
"------/0/-----------( )------------/-/-----------------------",
"| 20  \\ \\ 19|   18|   17|   16|15 /-/   14|   13|   12|   11|",
"|     |     |     |     |     |  /-/|     |     |     |     |",
"--------------------------------/-/--------------------------",
"|    1|    2|    3|    4|    5|/-/ 6|    7|    8|    9|   10|",
"|p1 p2|     |     |     |     |     |     |     |     |     |",
"-------------------------------------------------------------"
};
int moder=1;

int main()
{
p1.position=1;
p1.x=29;
p1.y=1;
p1.previousA=' ';//common mistake: string written in place of a character 
p1.previousB=' ';
p2.x=29;
p2.y=4;
p2.previousA=' ';
p2.previousB=' ';
SkeletalAlgorithm();
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
        grid[p1.x][p1.y]=p1.previousA; // y is horizontal movement)
        grid[p1.x][p1.y+1]=p1.previousB;
       
        // we will move y one up (y-3 in this case),
        p1.x=p1.x-3;
        
        // we want to store what is in the next block in the previous A & B of the structure
        p1.previousA=grid[p1.x-3][p1.y];   //
        p1.previousB=grid[p1.x-3][p1.y];   //
        
        // we want to print to mod location, moving player 1
        grid[p1.x][p1.y]='p';
        grid[p1.x][p1.y+1]='1';
        
        //updating postion
        p1.position++;

        //we will update the grid
        printGrid();
        
        //return
        return 1;
        }
    else//(/*we want to change x cause pointer in betweeen 1 and 10*/)
        {
            
        // we want to unprint from last location i.e position before modification
        grid[p1.x][p1.y]=p1.previousA;
        grid[p1.x][p1.y+1]=p1.previousB;
            
        //we will x+(mod_er) ((x+mode_er)*6 in this case)
        p1.y=p1.y+(moder*6);// this line decides the direction of insertion for' p1' and updates x coordinate accordingly
            
        // we want to store what is in the next block in the previous A & B of the structure
        p1.previousA=grid[p1.x][p1.y];
        p1.previousB=grid[p1.x][p1.y+1];
        
        // we want to print to mod location, moving player 1
        grid[p1.x][p1.y]='p';
        grid[p1.x][p1.y+1]='1';

        //updating postion
        p1.position++;

        //we will update the grid
        printGrid();
        
        //return
        return 1;
        }
    }
else 

//optimization idea- make a pointer to the structure and instead of writing the code 2 times just assing p1 or p2 to the struct and go on with a common variable
if(player==-1)// this line executes algo for player two when the flag is -1, which means it will be flippable
    if(p2.position%10==0/*we want to change y,  cause pointer at 10 or 1*/)
        {
        // we will change the x-coordinate modification symbol by multiplying -1 to the mod-er
        moder*=-1;
       
        // we want to unprint from last location i.e position before modification
        grid[p2.x][p2.y-3]=p2.previousA;
        grid[p2.x][p2.y-3]=p2.previousB;
       
        // we will move y one up (y-3 in this case),
        p2.y=p2.y-3;
        
        // we want to store what is in the next block in the previous A & B of the structure
        p2.previousA=grid[p2.x][p2.y];
        p2.previousB=grid[p2.x][p2.y+1];
        
        // we want to print to mod location, moving player 1
        grid[p2.x][p2.y-1]='p';
        grid[p2.x][p2.y-1]='1';
        
        //updating postion
        p2.position++;

        //we will update the grid
        printGrid();
        
        //return
        return 1;
        }
    else//(/*we want to change x cause pointer in betweeen 1 and 10*/)
        {
            
        // we want to unprint from last location i.e position before modification
        grid[p2.x][p2.y]=p2.previousA;
        grid[p2.x][p2.y+1]=p2.previousB;
            
        //we will x+(mod_er) ((x+mode_er)*6 in this case)
        p2.y=p2.y+(moder*6);// this line decides the direction of insertion for' p2' and updates x coordinate accordingly
            
        // we want to store what is in the next block in the previous A & B of the structure
        p2.previousA=grid[p2.x][p2.y];
        p2.previousB=grid[p2.x][p2.y+1];
        
        // we want to print to mod location, moving player 1
        grid[p2.x][p2.y]='p';
        grid[p2.x][p2.y+1]='1';

        //updating postion
        p2.position++;

        //we will update the grid
        printGrid();
        
        //return
        return 1;
        }
    }

int SkeletalAlgorithm()
{
    printf("press enter to start");
    while(p1.position<=99||p2.position<=99)
    {
    getchar();
    printGrid();
    int playerFlag=1;
    int dieResult=diceRoll();
  
    if(dieResult==6)
    {
      move(playerFlag);
        // move(playerFlag),move(playerFlag),move(playerFlag),
        // move(playerFlag),move(playerFlag),move(playerFlag);
        continue;

    }
    else//possible bug site
    {
        move(playerFlag);
        playerFlag*=-1;
        continue;
    }
}

}
/* 
this from project snake:

int printMatrix() {
    // usleep(1000000);

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 32; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
  printf("          ****your current score=%d*****", len);
}

Has been modified to :
*/

void printGrid() 
{
    printf("\033[H");
  for (int i = 0; i < 31; i++) {
    for (int j = 0; j < 61; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}


/* this from project snake:

int createRand(int num) {
  int random;
  if (first_c == 'w') {
    srand(time(NULL));

    random = rand();
    random = (random % num) + 1;
  } // srand is basically feeding a seed value to the pseudo
  // // random function rand() on the basis of time
  else if (first_c == 'a') {
    n++;
    srand(len + n);
  }
  //   ///this line makes this version of snake , speedrunable, as its
  //   predictable with exactlty same pattern everytime

  random = rand();
  random = (random % num) + 1;

  return random;
}
has been modified to:*/



int diceRoll() 
{
    
    srand(time(NULL));

    int random = rand();
    random = (random % 6) + 1;
   // srand is basically feeding a seed value to the pseudo
   // random function rand() on the basis of time


  return random;
}


