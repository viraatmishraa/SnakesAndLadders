//this line updates x coordinate accordingly and sign of moder decides direction of movement
            
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