#include <iostream>
#include <conio.h>
#include "windows.h" 
#include <ctime>
#include <vector>
#include <string>
#include "Data_Base.hpp"
#include "Functions.hpp"
#include "Menu.hpp"
 
// Config and main function
// Edit this file to make ajustments
int main()
{
    //Base settings  
    srand(time(NULL));
    setlocale(LC_CTYPE, "Polish"); // for polish characters to work
       
    //Base values
    // change the limits at will
    value_tries_min = 1;
    value_tries_max = 2048;
    value_length_max = 2048;
    value_length_min = 6;
       
    // these should not be changed
    check_another = 1;
    value_tries = 1;
    summing = 0;
    generating = 1;

    // base value if user press enter without typing anything
    value_length = 6;
    value_choose = 6;

    // base value if user press enter without choosing anything
    check_numbers = 0;
    check_lower = 0;
    check_upper = 0;
    check_special_easy = 0;
    check_special_hard = 0;
    check_polish_special = 0;

    menu_init(); 
	      
    //Base functions call
    while (check_another == true) {
        input_password_length();
        input_password_iterations();
        selecting_settings();
        system("CLS");
        summing_the_size();
        generator_base_and_results();
          
    };
}