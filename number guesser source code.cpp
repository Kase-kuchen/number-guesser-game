#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
//libraries used above
void Game(int choice,int tries) //this is the function of the game
{
HANDLE  hConsole;    //from here
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
FlushConsoleInputBuffer(hConsole);
SetConsoleTextAttribute(hConsole, 15); //to here, declarations required for colored text

    system("cls"); //clears the screen [aesthetic upgrade]

    int limit,guess,number,col; //declaration of variables, limit is the maximum number that can be randomly taken, guess is the guess of the player, number is a random number from 0 to limit

  switch(choice)  //Game takes in choice, that is because there are different levels, and they each have some conditions
  {
case 1:
    {
      limit=15;  //upper limit
      number=rand()%limit;  //generates a number up to the previous limit

      break;
    }
    case 2:
    {
      limit=50;
      number=rand()%limit;

      break;
    }
    case 3:
    {
      limit=100;
      number=rand()%limit;

      break;
    }
    case 4:
    {
      limit=500;
    number=rand()%limit;

      break;
    }
    case 5:
    {
      limit=2147483647; //int limit
    number=rand()%limit;

      break;
    }

  }

  for(int i=1;i<=limit;i++) //you get to try until you get to the limit
  {
   cout<<"You guess the number to be..."; cin>>guess; //main part of the game, where the player chooses a number

   if(guess==number)  //if the guess and the numbers match
        {
           col=2;
           SetConsoleTextAttribute(hConsole, col); //this and previous are for aesthetic purposes, changes color to green
           cout<<"You found the number! Congratulations!"<<endl;
            break;
        }
   else
    {
    col=4;
    SetConsoleTextAttribute(hConsole, col); //this and the previous are for aesthetic purposes, changes color to red

    tries--; //you lose 1 attempt
    cout<<"That was not the number, try again."<<endl;

    SetConsoleTextAttribute(hConsole, 15); //changes color back to white for the console

    }
    if(tries<=15) cout<<"You have "<<tries<<" tries left"<<endl; //aesthetic function, if you have less tries than 15, the game tells you how many you have left

    if(number>guess&&tries!=0)  //this is the approximation part of the game, purely done for user comfort, it tells the user if the guess was too high or too low, and how close he is to the answer
    {
        if(number-guess<=5)  //if the guess was too low, but 5 numbers far from the answer
         {
           col=3;  //changes color to blue
           SetConsoleTextAttribute(hConsole, col);

           cout<<"You're very close...the number is bigger"<<endl;

           SetConsoleTextAttribute(hConsole, 15); //changes color back to white for the console
         }
         else if(number-guess<=15)
            {
           col=5; //changes color to red
           SetConsoleTextAttribute(hConsole, col);

           cout<<"You're close...the number is bigger"<<endl;

           SetConsoleTextAttribute(hConsole, 15); //changes color back to white for the console
            }
    }
    else if (guess>number&&tries!=0)
    {
        if((guess-number)<=5)
        {
          col=3; //changes color to blue
          SetConsoleTextAttribute(hConsole, col);

          cout<<"You're very close...the number is smaller"<<endl;

          SetConsoleTextAttribute(hConsole, 15); //changes color back to white for the console
        }
        else if(number-guess<=15)
        {
          col=5; //changes color to red
          SetConsoleTextAttribute(hConsole, col);

          cout<<"You're  close...the number is smaller"<<endl;

          SetConsoleTextAttribute(hConsole, 15); //changes color back to white for the console
        }

    }

    if (guess!=number&&tries==0)  //lose condition for the game, you selected a wrong answer and have 0 attempts left
   {
    SetConsoleTextAttribute(hConsole, 4); //changes color to dark red

    cout<<"You failed! The number was "<<number<<" Maybe try again?"<<endl;

    SetConsoleTextAttribute(hConsole, 15); //changes color back to white for the console

    break;  //exits the for
   }
  }
  getch(); // quality of life function, the game will restart when any button [except power button] is pressed

}
int main()
{
    bool ProgramRunning=true;  //this variable makes the program run
    int choice,tries=100000,difficulty,col; //declaration of variables

    HANDLE  hConsole;  //from here
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, 15);//to here is the colored text declaration part

    while(ProgramRunning==true)  // heart of the program
    {

        system("cls"); //clears screen, aesthetic purposes
        SetConsoleTextAttribute(hConsole, 15); //resets color of text back to white

        cout<<"Welcome to the number guessing game! What difficulty would you like to play?"<<endl<<endl; //the player selects the difficulty here
        Sleep(1500); //waits 1.5 seconds, purely aesthetic
        col=2; //aesthetic purposes, changes colour of text to match difficulty
        SetConsoleTextAttribute(hConsole, col);
        cout<<"[1] Newbie (0-10)"<<endl;
        col=2;//aesthetic purposes, changes colour of text to match difficulty
        SetConsoleTextAttribute(hConsole, col);
        Sleep(500); //waits 0.5 seconds, purely aesthetic
        cout<<"[2] Beginner (0-50)"<<endl;
        col=3;//aesthetic purposes, changes colour of text to match difficulty
        SetConsoleTextAttribute(hConsole, col);
        Sleep(500);//waits 0.5 seconds, purely aesthetic
        cout<<"[3] Intermediate (0-100)"<<endl;
        col=4;//aesthetic purposes, changes colour of text to match difficulty
        SetConsoleTextAttribute(hConsole, col);
        Sleep(500);//waits 0.5 seconds, purely aesthetic
        cout<<"[4] Expert (0-500) "<<endl;
        col=5;//aesthetic purposes, changes colour of text to match difficulty
        SetConsoleTextAttribute(hConsole, col);
        Sleep(500);//waits 0.5 seconds, purely aesthetic
        cout<<"[5] Mission Impossible (0-2147483647) (1 attempt)"<<endl; //int limit
        SetConsoleTextAttribute(hConsole, 15);
        Sleep(500);//waits 0.5 seconds, purely aesthetic
        cout<<"[6] Exit the game"<<endl;
        cin>>choice; //lets the player choose what he wants to play

        switch (choice) //switch that selects the gamemode, based on the player's choice
        {
      case 1:
        {
         cout<<endl;
         cout<<"[1] Do you want to play with bonus difficulty? [Default: 15 tries]"<<endl<<"Press any other key to continue with infinite tries."<<endl;
         cin>>difficulty; //allows the player to select whether they want added difficulty or not
         cout<<endl;

         if(difficulty==1)
            tries=15;

        Game(choice,tries); //calls the game function with the respective parameters
        break;
        }
      case 2:
        {
         cout<<"[1] Do you want to play with bonus difficulty? [Default: 10 tries]"<<endl<<"Press any other key to continue with infinite tries."<<endl;
         cin>>difficulty;
         cout<<endl;

         if(difficulty==1)
            tries=10;

        Game(choice,tries); //calls the game function with the respective parameters
        break;
        }
      case 3:
        {
         cout<<"[1] Do you want to play with bonus difficulty? [Default: 7 tries]"<<endl<<"Press any other key to continue with infinite tries."<<endl;
         cin>>difficulty;
         cout<<endl;

         if(difficulty==1)
            tries=7;

        Game(choice,tries); //calls the game function with the respective parameters
        break;
        }
      case 4:
        {
         cout<<"[1] Do you want to play with bonus difficulty? [Default: 3 tries]"<<endl<<"Press any other key to continue with infinite tries."<<endl;
         cin>>difficulty;
         cout<<endl;

         if(difficulty==1)
            tries=3;

        Game(choice,tries); //calls the game function with the respective parameters
        break;
        }
      case 5:
        {
        tries=1;

        Game(choice,tries); //calls the game function with the respective parameters
        break;
        }
      case 6:
        {
          cout<<"You have decided to exit the program...farewell"<<endl;

          ProgramRunning=false; //makes the program end
          break;
        }
      default : //if the user inputs any other value than the correct ones, this will be executed
        {
          cout<<"Invalid output!"<<endl;
          break;
        }
        }
    }

    return 0;  //returns 0, the program is finished
}
