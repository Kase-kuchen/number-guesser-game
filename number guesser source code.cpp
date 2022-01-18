#include <iostream>
#include <windows.h>
#include <conio.h>
#include <random>
#include <ctime>
#include <vector>
using namespace std;
//libraries used above
void Game(int choice,int tries) //this is the function of the game
{
    std::mt19937 engine{std::random_device{}()};

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
      limit=10;  //upper limit
      std::uniform_int_distribution<int> randomnumber{0, 10};  //generates a number up to the  limit
      number=randomnumber(engine);
      break;
    }
    case 2:
    {
      limit=50;
     std::uniform_int_distribution<int> randomnumber{0, 50};  //generates a number up to the  limit
      number=randomnumber(engine);

      break;
    }
    case 3:
    {
      limit=100;
      std::uniform_int_distribution<int> randomnumber{0, 100};  //generates a number up to the  limit
      number=randomnumber(engine);

      break;
    }
    case 4:
    {
      limit=500;
    std::uniform_int_distribution<int> randomnumber{0, 500};  //generates a number up to the  limit
      number=randomnumber(engine);

      break;
    }
    case 5:
    {
      limit=2147483647; //int limit
    std::uniform_int_distribution<int> randomnumber{0, 2147483647};  //generates a number up to the  limit
      number=randomnumber(engine);

      break;
    }

  }

  for(int i=1;i<=limit;i++) //you get to try until you get to the limit
  {
   cout<<endl<<"You guess the number to be..."; cin>>guess; //main part of the game, where the player chooses a number

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
    //NOTE 1.0 Choosing added difficulty function removed temporarely [forever if I forget about this program] due to massive bugs and incorrectly implemented features, the compiler made some text that really scared me
    bool ProgramRunning=true;  //this variable makes the program run
    int choice,tries=100000,col; //declaration of variables
    string difficultychoice;

    HANDLE  hConsole;  //from here
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, 15);//to here is the colored text declaration part

    //vector<string> difficulty{"Yes","1","Yeah","Ja","Ok","Si","Da","Y","YES","yes","mkay","sure","yesn't"}; //pre-defined replies for the future question of whether the user wants added difficulty
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
            /*
         cout<<endl;
         cout<<" Do you want to play with bonus difficulty? [Default: 15 tries]"<<endl;
         cin>>difficultychoice; //allows the player to select whether they want added difficulty or not
         cout<<endl;
         for(int k=1;k<=strlen(difficulty);k++)
         if(difficulty==difficultychoice)
            tries=15; */

        Game(choice,tries); //calls the game function with the respective parameters
        break;
        }
      case 2:
        { /*
         cout<<"[1] Do you want to play with bonus difficulty? [Default: 10 tries]"<<endl<<"Press any other key to continue with infinite tries."<<endl;
         cin>>difficulty;
         cout<<endl;

         for(int k=1;k<=strlen(difficulty);k++)
         if(difficulty==difficultychoice)
            tries=10; */


        Game(choice,tries); //calls the game function with the respective parameters
        break;
        }
      case 3:
        { /*
         cout<<"[1] Do you want to play with bonus difficulty? [Default: 7 tries]"<<endl<<"Press any other key to continue with infinite tries."<<endl;
         cin>>difficulty;
         cout<<endl;

         for(int k=1;k<=strlen(difficulty);k++)
         if(difficulty==difficultychoice)
            tries=7; */

        Game(choice,tries); //calls the game function with the respective parameters
        break;
        }
      case 4:
        { /*
         cout<<"[1] Do you want to play with bonus difficulty? [Default: 3 tries]"<<endl<<"Press any other key to continue with infinite tries."<<endl;
         cin>>difficulty;
         cout<<endl;

        for(int k=1;k<=strlen(difficulty);k++)
         if(difficulty==difficultychoice)
            tries=3;
        */
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
