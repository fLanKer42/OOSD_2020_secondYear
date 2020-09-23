/*****************************

 * Name: Dhruv Rai
 * Roll number: 19QM30002
 * Tick Tack Toe Game

*****************************/


#include <iostream>

using namespace std;

void displayTable(int array[9]);
/*
displayTable: 
Displays the game area of tic tak toe in it's present situation
prints to std output
*/
char printChar(int num);
/*
printChar:
Converts numbers to respective characters in table
0->" "
1->"X"
2->"O"
*/
int gameOver(int array[9]);
/*
gameOver:
Checks if game is over, if game over then returns 1,else 0
prints a suitable statement to std output.
*/
int makeMove(int array[9], int player);
/*
makeMove:
Moves for player 1 are different from player 2.
returns the integer coordinate to be updated in array.
*/
int moveCounter(int array[9], int player);
/*
tells how many moves have already been made by the player.
*/

int main() {

    /*
    Main function
    */
    
    int player,computer; 
    // player is 1 if user plays as player 1 and computer will take the value 2 and vice versa.
    int temp; 
    // temporary variable
    while(1) {                                          
        // infinite while loop that breaks only when user enters 1.
        int table[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        //array of game area, 0 -> empty, 1 -> X, 2 -> O
        cout << "Player 1 or Player 2\n";               
        cin >> player;                                  
        //input of player value
        if(player != 1 && player != 2) {
            //check if player value is correct
            cout << "Enter the correct value of player";
            continue;
        }
        computer = (player%2) + 1;                     
        //finds computer number if player is given.
        if (player == 2) {
            //if player is 2, computer makes the first move
            table[makeMove(table, player)] = computer;
            //computer makes the move
            displayTable(table);
        }
        else {
            //display empty table
            displayTable(table);
        }
        while(!(gameOver(table))) {
            cin >> temp;
            //input from user (1-9)
            if( temp < 1 || temp > 9 ) {
                //check if the entered number is out-of-bound.
                cout << "Input out of bound";
                break;
            }
            temp = temp - 1;
            //convert to (0-8)
            if( table[temp] !=0 ) {
                //check if the entered cell is empty.
                cout << "Table element already occupied";
                break;
            }
            table[temp] = player;
            //update in table
            if(gameOver(table)) {
                //check if game is over.
                break;
            }
            table[makeMove(table, player)] = computer;
            //computer makes the move and updates the table
            displayTable(table);
            //display table
        }
        temp = 0;
        cout << "\nPress 1 to exit\n";
        cin >> temp;
        if( temp == 1 ) {
            break;
        }
    }

}

void displayTable(int arr[9]) {

    int i;
    //iteration variable
    for(i=0;i<3;i++) {
        //from 0 to 2
        cout << printChar(arr[i]);
        if ( i != 2 ) {
            // last element of line will not have "|" after.
            cout << " | ";
        }
    }
    cout << "\n----------\n";
    //design of game area
    for(i=3;i<6;i++) {
        //from 3 to 5
        cout << printChar(arr[i]);
        if ( i != 5 ) {
            cout << " | ";
        }
    }
    cout << "\n----------\n";
    for(i=6;i<9;i++) {
        //from 6 to 8
        cout << printChar(arr[i]);
        if ( i != 8 ) {
            cout << " | ";
        }
    }
    cout << "\n";

}

char printChar(int num) {

    if( num == 0) {
        //empty
        return ' ';
    }
    else if ( num == 1) {
        //player 1
        return 'X';
    }
    else {
        //player 2
        return 'O';
    }
}

int gameOver(int arr[9]) {

    int i;
    //iteration variable
    for(i=0;i<9;i++) {
        if (arr[i] == 0) {
            //check if empty place left
            i = 0;
            break;
        }
    }
    if( arr[0] == arr[1] && arr[1] == arr[2] && arr[0] != 0) {
        //row 1
        cout << "\nLose";
        return 1;
    }
    else if( arr[3] == arr[4] && arr[4] == arr[5] && arr[3] != 0) {
        //row 2
        cout << "\nLose";
        return 1;
    }
    else if( arr[6] == arr[7] && arr[7] == arr[8] && arr[6] != 0) {
        //row 3
        cout << "\nLose";
        return 1;
    }
    else if( arr[0] == arr[4] && arr[4] == arr[8] && arr[0] != 0) {
        //diagnol 1
        cout << "\nLose";
        return 1;
    }
    else if( arr[2] == arr[4] && arr[4] == arr[6] && arr[2] != 0) {
        //diagnol 2
        cout << "\nLose";
        return 1;
    }
    else if( arr[0] == arr[3] && arr[3] == arr[6] && arr[0] != 0) {
        //column 1
        cout << "\nLose";
        return 1;
    }
    else if( arr[1] == arr[4] && arr[4] == arr[7] && arr[1] != 0) {
        //column 2
        cout << "\nLose";
        return 1;
    }
    else if( arr[2] == arr[5] && arr[5] == arr[8] && arr[2] != 0) {
        //column 3
        cout << "\nLose";
        return 1;
    }
    else if ( i != 0 ) {
        //no empty location left, tie
        cout << "\nTie";
        return 1;
    }
    return 0;
    //gamee continues
}

int makeMove(int arr[9], int player)  {
    int num_moves = moveCounter(arr,player);
    //number of moves played by player
    int i, computer = (player%2) + 1;
    //iteration variable and computer variable
    int sites[4], count = 0;
    //sites is an array that holds the location of all the moves of the player
    //count is counting variable 


    //Starting with if user is playing as player 1

    if (num_moves == 1 ) {
        //first move player 1 & second move player 2
        if ( arr[4] == 0 ) {
            //if player has not occupied center, take it
            return 4;
        }
        else if(arr[0] == 0 && arr[8] == 0 && arr[5] == 0 && arr[7] == 0) {
            //take a corner
            return 0;
        }
        else if(arr[2] == 0 && arr[6] == 0 && arr[7] == 0) {
            //only for player 2 case
            return 2;
        }
        else {
            //only for player 2 case
            return 8;
        }
    }
    else if ( num_moves == 2 && player == 1) {
        //second move player 1

        for (i = 0; i < 9; i++) {
            //find sites of player moves
            if (arr[i] == player) {
                sites[count] = i;
                count = 1;
            }
        }
        if (sites[0]%3 == sites[1]%3) {
            if (arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[1])] != computer) {
                //find if vertical combination is about to form
                return (3*(3+(sites[0]%3)))-(sites[0] + sites[1]);
            }
            else {
                if(sites[0]%3==2) {
                    //otherwise come into position to form own formation
                    return (3*(3+(sites[0]%3)))-(sites[0] + sites[1]) - 1;
                }
                else {
                    return (3*(3+(sites[0]%3)))-(sites[0] + sites[1]) + 1;
                }
            }
        }
        else if(int(sites[0]/3) == int(sites[1]/3)) {
                if(arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1])] != computer) {
                    //find if horizontal combination is about to form, if not then com into own position
                    return (3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1]);
                }
                else {
                    if(int(sites[0]/3) == 2) {
                        return (3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1]) - 3;
                    }
                    else {
                        return (3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1]) + 3;
                    }
                }
            }
        else if((arr[2] == player && arr[6] == player)||(arr[2] == player && arr[4] == player)||(arr[4] == player && arr[6] == player)){
            //check for second diagnol formation
                if (arr[4] == computer) {
                    return 1;
                }
                else {
                    return 12 - (sites[0] + sites[1]);
                }
        }
        else if(arr[0]==player && arr[8]==player && arr[4]==computer) {
            //first diagnol formation, 2 player and one computer.
            return 1;
        }
        else {
            //user has made non center first move and second move does not create threat.
            if (arr[2] == 0 && arr[6] == 0) {
                return 2;
            }
            else if(arr[0] == 0 && arr[8] == 0) {
                return 0;
            }
            else if(arr[7] == 0 && arr[1] == 0) {
                return 1;
            }
        }
    }


    else if ( num_moves == 3 && player == 1 ) {
        //third move player 1
        int x[3], count2 = 0;
        //x is the array of location of computer moves
        for (i = 0; i < 9; i++) {
            //count sites
            if (arr[i] == player) {
                sites[count] = i;
                count++;
            }
            if (arr[i] == computer) {
                //count x (computer moves)
                x[count2] = i;
                count2++;
            }
        }
        if (arr[(3*(3+(x[0]%3)))-(x[0] + x[1])] != computer && x[0]%3 == x[1]%3 && arr[(3*(3+(x[0]%3)))-(x[0] + x[1])] == 0 ) {
            //checks possibility of vertical line finish
            return (3*(3+(x[0]%3)))-(x[0] + x[1]);
        }
        else if(arr[(3*(1+3*int(x[0]/3))) - (x[0]+x[1])] != computer && int(x[0]/3) == int(x[1]/3) && arr[(3*(1+3*int(x[0]/3))) - (x[0]+x[1])] == 0) {
            //checks possibility of horizontal line finish
            return (3*(1+3*int(x[0]/3))) - (x[0]+x[1]);
        }
        else if(arr[4]==computer && arr[2]==computer && arr[6]==0) {
            //check possibility of second diagonal finish
            return 6;
        }
        else if(arr[4]==computer && arr[6]==computer && arr[2]==0) {
            //check possibility of second diagonal finish
            return 2;
        }
        else if(arr[4]==computer && arr[0]==computer && arr[8]==0) {
            //checks possibility of first diagonal finish
            return 8;
        }
        else if(arr[4]==computer && arr[8]==computer && arr[0]==0) {
            //checks possibility of first diagonal finish
            return 0;
        }
        //thwarts verticle finish attempt of user
        else if (arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[1])] != computer && sites[0]%3 == sites[1]%3 && arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[1])] == 0) {
            return (3*(3+(sites[0]%3)))-(sites[0] + sites[1]);
        }
        else if (arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[2])] != computer && sites[0]%3 == sites[2]%3 && arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[2])] == 0) {
            return (3*(3+(sites[0]%3)))-(sites[0] + sites[2]);
        }
        else if (arr[(3*(3+(sites[1]%3)))-(sites[2] + sites[1])] != computer && sites[2]%3 == sites[1]%3 && arr[(3*(3+(sites[2]%3)))-(sites[2] + sites[1])] == 0) {
            return (3*(3+(sites[1]%3)))-(sites[2] + sites[1]);
        }
        
        //thwarts horizontal finish attempt by user
        else if(arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1])] != computer && int(sites[0]/3) == int(sites[1]/3) && arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1])] == 0) {
            return (3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1]);
        }
        else if(arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[2])] != computer && int(sites[0]/3) == int(sites[2]/3) && arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[2])] == 0) {
            return (3*(1+3*int(sites[0]/3))) - (sites[0]+sites[2]);
        }
        else if(arr[(3*(1+3*int(sites[2]/3))) - (sites[2]+sites[1])] != computer && int(sites[2]/3) == int(sites[1]/3) && arr[(3*(1+3*int(sites[2]/3))) - (sites[2]+sites[1])] == 0) {
            return (3*(1+3*int(sites[2]/3))) - (sites[2]+sites[1]);
        }
        
        else if(arr[4]==player) {
            //thwarts diagonal attemp by user
            if(arr[6]==player && arr[2]==0) {
                return 2;
            }
            else if(arr[2] == player && arr[6]==0) {
                return 6;
            }
        }
        
        if( arr[0] == computer) {
            //creates next move, if above cases are not met
            if (arr[3]==0 && arr[6]==0) {
                return 3;
            }
            else if(arr[1]==0 && arr[2]==0) {
                return 1;
            }
        }
        if (arr[4] == computer) {
            //creates next move, if above cases are not met
            if(arr[1]==0 && arr[7]==0) {
                return 1;
            }
            else if(arr[3]==0 && arr[5]==0) {
                return 3;
            }
            else if(arr[2]==0 && arr[6]==0) {
                return 2;
            }
            else if(arr[0]==0 && arr[8]==0) {
                return 0;
            }
        }    
    }

    else if (num_moves == 4 && player == 1) {
        //fourth move player 1
        int x[3], count2 = 0;
        //x is the array of location of computer moves
        for (i = 0; i < 9; i++) {
            //count sites
            if (arr[i] == player) {
                sites[count] = i;
                count++;
            }
            if (arr[i] == computer) {
                //count x (computer moves)
                x[count2] = i;
                count2++;
            }
        }
        //checks possibility of verticle finish
        if (arr[(3*(3+(x[0]%3)))-(x[0] + x[1])] != computer && x[0]%3 == x[1]%3 && arr[(3*(3+(x[0]%3)))-(x[0] + x[1])] == 0 ) {
            return (3*(3+(x[0]%3)))-(x[0] + x[1]);
        }
        else if (arr[(3*(3+(x[1]%3)))-(x[1] + x[2])] != computer && x[1]%3 == x[2]%3 && arr[(3*(3+(x[1]%3)))-(x[1] + x[2])] == 0 ) {
            return (3*(3+(x[1]%3)))-(x[1] + x[2]);
        }
        else if (arr[(3*(3+(x[2]%3)))-(x[0] + x[2])] != computer && x[2]%3 == x[0]%3 && arr[(3*(3+(x[2]%3)))-(x[0] + x[2])] == 0 ) {
            return (3*(3+(x[2]%3)))-(x[0] + x[2]);
        }

        //checks possibility of horizontal finish
        else if(arr[(3*(1+3*int(x[0]/3))) - (x[0]+x[1])] != computer && int(x[0]/3) == int(x[1]/3) && arr[(3*(1+3*int(x[0]/3))) - (x[0]+x[1])] == 0) {
            return (3*(1+3*int(x[0]/3))) - (x[0]+x[1]);
        }
        else if(arr[(3*(1+3*int(x[1]/3))) - (x[2]+x[1])] != computer && int(x[2]/3) == int(x[1]/3) && arr[(3*(1+3*int(x[1]/3))) - (x[2]+x[1])] == 0) {
            return (3*(1+3*int(x[1]/3))) - (x[2]+x[1]);
        }
        else if(arr[(3*(1+3*int(x[0]/3))) - (x[2]+x[0])] != computer && int(x[0]/3) == int(x[2]/3) && arr[(3*(1+3*int(x[0]/3))) - (x[0]+x[2])] == 0) {
            return (3*(1+3*int(x[0]/3))) - (x[0]+x[2]);
        }

        //checks possibility of diagonal finish
        else if(arr[0]==computer && arr[4]==computer && arr[8] ==0) {
            return 8;
        }
        else if(arr[8]==computer && arr[4]==computer && arr[0]==0) {
            return 0;
        }
        else if(arr[2]==computer && arr[4]==computer && arr[6]==0) {
            return 6;
        }
        else if(arr[6]==computer && arr[4]==computer && arr[2]==0) {
            return 2;
        }


        int t, y;
        //iteration variables
        for(t = 0;t < 4; t++) {
            //double for to thwart user attempts
            for(y = t + 1;y < 4;y++) {
                if (arr[(3*(3+(sites[t]%3)))-(sites[t] + sites[y])] != computer && sites[t]%3 == sites[y]%3 && arr[(3*(3+(sites[t]%3)))-(sites[t] + sites[y])] == 0) {
                    return (3*(3+(sites[t]%3)))-(sites[t] + sites[y]);
                }
                else if(arr[(3*(1+3*int(sites[t]/3))) - (sites[t]+sites[y])] != computer && int(sites[t]/3) == int(sites[y]/3) && arr[(3*(1+3*int(sites[t]/3))) - (sites[t]+sites[y])] == 0) {
                    return (3*(1+3*int(sites[t]/3))) - (sites[t]+sites[y]);
                }
            }
        }

        //thwarts diagonal attempts
        if(arr[4]==player) {
            if(arr[2]==player && arr[6]==0) {
                return 6;
            }
            else if(arr[6]==player && arr[2]==0) {
                return 2;
            }
        }


        // move towards a draw
        for(i=0;i<9;i++) {
            if(arr[i]==0) {
                return i;
            }
        } 
    }



    else if (num_moves == 0) {
        //first move player 2 
        return 4;
        //occupy center position
    }

    else if ( num_moves == 2 && player == 2) {
        //third move player 2
        for (i = 0; i < 9; i++) {
            if (arr[i] == player) {
                //count sites
                sites[count] = i;
                count = 1;
            }
        }
        if (arr[0] == computer) {
            //first diagonal finish
            if(arr[8] == 0) {
                return 8;
            }
        }
        else if (arr[8] == computer) {
            if(arr[0] == 0) {
                //first diagonal finish
                return 0;
            }
        }
        else if (arr[2] == computer) {
            //second diagonal finish
            if(arr[6] == 0) {
                return 6;
            }
        }
        if ((arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[1])] != computer) && (sites[0]%3 == sites[1]%3)) {
            //thwarting vertical finish
            return (3*(3+(sites[0]%3)))-(sites[0] + sites[1]);
        }
        else if((arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1])] != computer) && (int(sites[0]/3) == int(sites[1]/3))) {
            //thwarting horizontal finish
            return (3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1]);
        }

        //positioning for next move
        else if(arr[1] == player && arr[8] == player) {
            return 3;
        }
        else if(arr[1] == player && arr[6] == player) {
            return 5;
        }
        else if(arr[7] == player && arr[0] == player) {
            return 5;
        }
        else if(arr[3] == player) {
            return 1;
        }
        else if(arr[5] == player) {
            return 1;
        }
    }
    
    else if ( num_moves == 3 && player == 2) {
        //fourth move player 2
        int x[3], count2 = 0;
        //x is the array of location of computer moves
        for (i = 0; i < 9; i++) {
            if (arr[i] == player) {
                //count sites
                sites[count] = i;
                count++;
            }
            if (arr[i] == computer) {
                //count x, location of computer moves
                x[count2] = i;
                count2++;
            }
        }


        //vertical finish
        if (arr[(3*(3+(x[0]%3)))-(x[0] + x[1])] != computer && x[0]%3 == x[1]%3 && arr[(3*(3+(x[0]%3)))-(x[0] + x[1])] == 0 ) {
            return (3*(3+(x[0]%3)))-(x[0] + x[1]);
        }
        else if (arr[(3*(3+(x[1]%3)))-(x[1] + x[2])] != computer && x[1]%3 == x[2]%3 && arr[(3*(3+(x[1]%3)))-(x[1] + x[2])] == 0 ) {
            return (3*(3+(x[1]%3)))-(x[1] + x[2]);
        }
        else if (arr[(3*(3+(x[2]%3)))-(x[0] + x[2])] != computer && x[2]%3 == x[0]%3 && arr[(3*(3+(x[2]%3)))-(x[0] + x[2])] == 0 ) {
            return (3*(3+(x[2]%3)))-(x[0] + x[2]);
        }

        //horizontal finish
        else if(arr[(3*(1+3*int(x[0]/3))) - (x[0]+x[1])] != computer && int(x[0]/3) == int(x[1]/3) && arr[(3*(1+3*int(x[0]/3))) - (x[0]+x[1])] == 0) {
            return (3*(1+3*int(x[0]/3))) - (x[0]+x[1]);
        }
        else if(arr[(3*(1+3*int(x[1]/3))) - (x[2]+x[1])] != computer && int(x[2]/3) == int(x[1]/3) && arr[(3*(1+3*int(x[1]/3))) - (x[2]+x[1])] == 0) {
            return (3*(1+3*int(x[1]/3))) - (x[2]+x[1]);
        }
        else if(arr[(3*(1+3*int(x[0]/3))) - (x[2]+x[0])] != computer && int(x[0]/3) == int(x[2]/3) && arr[(3*(1+3*int(x[0]/3))) - (x[0]+x[2])] == 0) {
            return (3*(1+3*int(x[0]/3))) - (x[0]+x[2]);
        }


        //thwarting vertical finish
        else if (arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[1])] != computer && sites[0]%3 == sites[1]%3 && arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[1])] == 0) {
            return (3*(3+(sites[0]%3)))-(sites[0] + sites[1]);
        }
        else if (arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[2])] != computer && sites[0]%3 == sites[2]%3 && arr[(3*(3+(sites[0]%3)))-(sites[0] + sites[2])] == 0) {
            return (3*(3+(sites[0]%3)))-(sites[0] + sites[2]);
        }
        else if (arr[(3*(3+(sites[1]%3)))-(sites[2] + sites[1])] != computer && sites[2]%3 == sites[1]%3 && arr[(3*(3+(sites[2]%3)))-(sites[2] + sites[1])] == 0) {
            return (3*(3+(sites[1]%3)))-(sites[2] + sites[1]);
        }

        //thwarting horizontal finish
        else if(arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1])] != computer && int(sites[0]/3) == int(sites[1]/3) && arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1])] == 0) {
            return (3*(1+3*int(sites[0]/3))) - (sites[0]+sites[1]);
        }
        else if(arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[2])] != computer && int(sites[0]/3) == int(sites[2]/3) && arr[(3*(1+3*int(sites[0]/3))) - (sites[0]+sites[2])] == 0) {
            return (3*(1+3*int(sites[0]/3))) - (sites[0]+sites[2]);
        }
        else if(arr[(3*(1+3*int(sites[2]/3))) - (sites[2]+sites[1])] != computer && int(sites[2]/3) == int(sites[1]/3) && arr[(3*(1+3*int(sites[2]/3))) - (sites[2]+sites[1])] == 0) {
            return (3*(1+3*int(sites[2]/3))) - (sites[2]+sites[1]);
        }


        //move towards a draw
        else if( arr[1] == 0 ) {
            return 1;
        }
        else {
            return 3;
        }
    }
    
        
    else if(num_moves == 4 && player == 2) {
        //fifth move player 2
        //draw move, only one possible move is left
        for(i=0;i<9;i++) {
            if ( arr[i] == 0) {
                return i;
            }
        }
        
    }
    return 0;//for removing warning, this case will never occur
}

int moveCounter(int arr[9], int player) {
    int i, counter = 0;
    //iteration variable
    for(i=0;i<9;i++) {
        //count number of moves of the user.
        if( arr[i] == player) {
            counter++;
        }
    }
    return counter;
}