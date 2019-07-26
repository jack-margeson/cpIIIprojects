// chapter5.cpp
// Chapter 5 book projects.
// Jack Margeson
// 01/22/2019

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  // declarations for menu and looping 
  int menu;
  string ans;

  do {
    // output context menu
    cout << "Chapter 5 Book Projects\n\n" << "1) Program 5.1 - Transportation\n" << "2) Program 5.2 - Elipse\n" << "3) Program 5.3 - Degrees to Radians\n" << "4) Program 5.4 - MPH to FPS\n" << "5) Program 5.5 - Simple Intrest\n" << "6) Program 5.6 - Electricity\n" << "7) Program 5.7 - Force\n" << "8) Program 5.8 - Energy\n" << "9) Program 5.9 - Speeding Ticket\n\n" << "Enter a number 1-9 to choose a program: ";
    cin >> menu;
    cout << "\033[2J\033[1;1H";
    if (menu == 1) { // Program 5.1 - Transportation 
      const int bus = 50;
      int people;
      int nbus;
      int npeople;
      
      cout << "    ______________________\n   |,----.,----.,----.,--.\\\n   ||    ||    ||    ||   \\\\\n   |`----'`----'|----||----\\`.\n   [            |   -||- __|(|\n   [  ,--.      |____||.--.  |\n   =-(( `))-----------(( `))==\n      `--'             `--'    ";
      cout << "Transportation\n" << "Please enter the number of people (50 people/bus): ";
      cin >> people;
      nbus = people / bus;
      npeople = people % bus;
      cout << "\nYou can rent " << nbus << " bus(ses) - " << npeople << " people will have to travel in vans.";
    }
    else if (menu == 2) { // Program 5.2 - Elipse
      int semimajor;
      int semiminor;
      float area;
      const float PI = 3.1415927;

      cout << "         , - ~ ~ ~ - ,\n     , '               ' ,\n   ,                       ,\n  ,                         ,\n ,                           ,\n ,                           ,\n ,                           ,\n  ,                         ,\n   ,                       ,\n     ,                  , '\n       ' - , _ _ _ ,  '     ";
      cout << "Elipse\n" << "Please enter the semi major axis (horizonal radius): ";
      cin >> semimajor;
      cout << "\nPlease enter the semi minor axis (vertical radius): ";
      cin >> semiminor;
      area = PI * semimajor * semiminor;
      cout << "The area of the elipse is " << area << ".";
    }
    else if (menu == 3) { // Program 5.3 - Deg to Rad
      float degrees;
      float radians;
      const float drconversion = 57.3;

      cout << "             (\n              )\n         __..---..__\n     ,-='  /  |  \\  `=-.\n    :--..___________..--;\n     \\.,_____________,./    ";
      cout << "Degrees to Radians\n" << "Enter an amount in degrees: ";
      cin >> degrees;
      radians = degrees / drconversion;
      cout << "\n" << degrees << " in radians equals " << radians << ".";
    }
    else if (menu == 4) { // Program 5.4 - MPH to FPS
      const float mfconversion = 1.46667;
      float miles;
      float feet;

      cout << "\n                             :            :\n                             :            :\n                             :            :\n                             :            :\n                             :            :\n                            .'            :\n                        _.-\"              :\n                    _.-\"                  '.\n    ..__...____...-\"                       :\n   : \\_\\                                    :\n   :    .--\"                                 :\n   `.__/  .-\" _                               :\n      /  /  ,\" ,-                            .'\n     (_)(`,(_,'L_,_____       ____....__   _.'\n      \"' \"             \"\"\"\"\"\"\"          \"\"\"     ";
      cout << "MPH to FPS\n" << "Enter Miles Per Hour: ";
      cin >> miles;
      feet = miles * mfconversion;
      cout << "\n" << miles << " MPH is " << feet << " FPS.";
    }
    else if (menu == 5) { // Program 5.5 - Simple Int.
      int principal;
      int time;
      float rate;
      float interest;

      cout << "___________________________________\n|#######====================#######|\n|#(1)*UNITED STATES OF AMERICA*(1)#|\n|#**          /===\\   ********  **#|\n|*# {G}      | (\") |             #*|\n|#*  ******  | /v\\ |    O N E    *#|\n|#(1)         \\===/            (1)#|\n|##=========ONE DOLLAR===========##|\n------------------------------------     ";
      cout << "Interest\n" << "Please enter principal (starting amount): ";
      cin >> principal;
      cout << "\nPlease enter time (in years): ";
      cin >> time;
      cout << "\nPlease enter rate (in decimal form): ";
      cin >> rate;
      interest = principal * rate * time;
      cout << "\nYour intrest is $" << fixed << setprecision(2) << interest << ".";
      cin.ignore();
    }
    else if (menu == 6) { // Program 5.6 - Electricity
      int voltage;
      int resistance;
      float current;

      cout << "    ___(                        )\n   (                          _)\n  (_                       __))\n    ((                _____)\n      (_________)----'\n         _/  /\n        /  _/\n      _/  /\n     / __/\n   _/ /\n  /__/\n //\n/'     ";
      cout << "Current\n" << "Enter voltage: ";
      cin >> voltage;
      cout << "\nEnter resistance (in ohms): ";
      cin >> resistance;
      current = voltage / resistance;
      cout << "The current through the resistor is " << current << " amp(s).";
  
    }
    else if (menu == 7) { // Program 5.7 - Force
      int newton;
      float accel;
      float force;
      cout << "       #######\n     #######o###\n   #####o#######o#\n ####o#\\#|#/########\n########\\|/##o#####o#\n #      }}{   o    #\n        }{{  (\n    o   }}{_ c_\\   OW!\n        }}{\\(\n        }{{  \\/\\\\  o     ";
      cout << "Force\n" << "Please enter the force (in newtons): ";
      cin >> newton;
      cout << "\nPlease enter the acceleration in meters per second: ";
      cin >> accel;
      force = newton * accel;
      cout << "\nThe force is " << force << "N.";
    }
    else if (menu == 8) { // Program 5.8 - Energy
      const double SPEED_OF_LIGHT = 299792458;
      int mass;
      double energy;

      cout << "        -''--.\n         _`>   `\\.-'<\n      _.'     _     '._\n    .'   _.='   '=._   '.\n    >_   / /_\\ /_\\ \\   _<\n      / (  \\o/\\\\o/  ) \\\n      >._\\ .-,_)-. /_.<\n          /__/ \\__\\\n            '---'     ";
      cout << "e = mc^2\n" << "Please enter the mass of an object: ";
      cin >> mass;
      energy = mass * (SPEED_OF_LIGHT * SPEED_OF_LIGHT);
      cout << "\nThe energy of an object with the mass " << mass << " is equal to " << energy << ".";
    }
    else if (menu == 9) { // Program 5.9 - Speeding
      int mph;
      int speedlim;
      float ticket;

      cout << "                ,\n       __  _.-\"` `'-.\n      /||\\'._ __{}_(\n      ||||  |'--.__\\\n      |  L.(   ^_\\^\n      \\ .-' |   _ |\n      | |   )\\___/\n      |  \\-'`:._]\n      \\__/;      '-.     ";
      cout << "Speeding Ticket\n" << "Enter your MPH at time of ticket: ";
      cin >> mph;
      cout << "Enter speed limit: ";
      cin >> speedlim;
      if (speedlim >= mph){
        cout << "\nYou didn't get a ticket, liar!";
      }
      else if ((mph - speedlim) <= 15) {
        ticket = 35.00;
      }
      else {
        ticket = 35.00 + ((mph - speedlim) * 0.2);
      }
      cout << "\nYou must pay $" << fixed << setprecision(2) << ticket << " for your ticket.";
    }
    else {
      cout << "\nInvalid program.";
    }
    // loop handling
    cout << "\nRun again and return to main menu? (y/n) ";
    cin >> ans;
    cout << "\033[2J\033[1;1H";
  } while(ans == "y" or ans == "Y");
  // system("Pause");
  return 0;
}