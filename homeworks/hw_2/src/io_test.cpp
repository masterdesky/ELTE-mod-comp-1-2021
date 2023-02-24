////////////////////////////////////////////////////////
//
//    Creating a custom vector class with operator
//    overloading
//
//    File : io_test.cpp
//    Desc : Contains the I/O tests and textual infos displayed on
//           screen during the execution of the software
//
//    Written by Balázs Pál @ 2021
//    For Furu and Szigety
//
////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <vector.hpp>
#include <thread>
#include <chrono>

void program_info()
{
  std::cout << "======= Komputer Softvere Program - England Edition 2021 ======="
            << std::endl;
  std::cout << "\n" << std::endl;
  std::cout << "Good day Sir my name is Tommy Macrosoft Computer Tech Suport.\n"
            << "I will guiding u true all the steps needed to check integrity\n"
            << "of the Computer Sovtware Progrem and see if it works correctly."
            << std::endl;
  std::cout << "----------------------------------------------------------------"
            << std::endl;
  std::cout << "Pls follow every steps in order what I tell u to succesfully\n" 
            << "complete the procideur. Otervise heckers infect your komputer\n"
            << "so plz Sir be aware of this."
            << std::endl;
  std::cout << "================================================================"
            << std::endl;
  std::cout << "\n\n" << std::endl;
}

void input_arguments(vector2d& v_1, vector2d& v_2, double& c)
{
  std::cout << "For tests we need some parameters from u to be given imedietly!"
            << std::endl;
  std::cout << "----------------------------------------------------------------"
            << std::endl;
  std::cout << "Plz enter the vektor_1 (two random numbers and then hit enter):"
            << std::endl;
  std::cin >> v_1;
  std::cout << "\n" << std::endl;
  std::cout << "Now Sir, plz enter the vektor_2 (date on ur creadit card):"
            << std::endl;
  std::cin >> v_2;
  std::cout << "\n" << std::endl;
  do {
    std::cout << "Okay now enter a scalar (3 numberz on back of ur credit card):"
              << std::endl;
    std::cin >> c;
    if(c == 0)
    {
      std::cout << "Plz choose another number not 0... Pls... 4 ur own sake Sir"
                << std::endl;
    }
  } while(c == 0);
  std::cout << "\n" << std::endl;
  std::cout << "Thank you Sir, plz stay in the Computer Program Software!"
            << std::endl;
}

void checking_virus_maderchod()
{
  std::cout << "Now checking 4 viruses on ur computer plz leave the mouse and\n"
            << "keyboard buttons on your computer alone! The test staring now\n"
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  std::cout << "\n" << std::endl;

  std::cout << "THE VAIRUS SEARCHING STARTING ON UR CUMPOTUER..."
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  std::cout << "STARTIN TESTS..."
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));

  std::cout << "\n" << std::endl;
}

void results_are_okay()
{
  char choose;
  std::cout << "Are you satisfied with the results above? [y/n]"
            << std::endl;
  std::cin >> choose;

  switch(choose)
  {
    case 'y':
      std::cout << "I really hope you had a good quality expirience Sir."
                << std::endl;
      break;
    case 'n':
      std::cout << "It's your problem Sir, not mine."
                << std::endl;
      break;
    default:
      std::cout << "Plz Sir write 'y' or 'n' as I said 2 u!!!!!!!"
                << std::endl;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void closing_program()
{
  std::cout << "\n\n" << std::endl;
  std::cout << "----------------------------------------------------------------"
            << std::endl;
  std::cout << "\n" << std::endl;

  std::cout << "TERI YE HIMAT MADER CHOD!!!!! DON'T CLOSE THE PROGRAM!!!!!!!!!!\n"
            << "I SAID DON'T CLOSE THE PROGRAM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
            << "ARE YOU STUPID SIR ARE AN IDIOT I SAID DO AS I SAID!!!!!!!!!!!!\n"
            << "HECKER NOW INVADED YOUR KOMPUTER SIR UR SO STUPID!!!!!!!!!!!!!!\n"
            << "I WILL T--"
            << std::endl;

  std::cout << "\n" << std::endl;

  std::cout << "Exiting program gracefully..."
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(800));
  std::cout << "Network connection closing..."
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(900));
  std::cout << "Closing connection to client FTP://229.654.18.244:443..."
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(380));
  std::cout << "Chrome+passwords.tar.gz zipping..."
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1400));
  std::cout << "Pinging target TOR-nodes with 4 bytes packets for 300ms..."
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(300));
  std::cout << "TOR input node location #1 selected: Estonia -- Tartu"
            << std::endl;
  std::cout << "TOR input node location #2 selected: Germany -- Stuttgart"
            << std::endl;
  std::cout << "TOR input node location #3 selected: South-Korea -- Seoul"
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << "Sending surprise... ;)"
            << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  std::cout << "\n\n" << std::endl;
  std::cout << "Good bye! :)"
            << std::endl;
}