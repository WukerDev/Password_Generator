#include <iostream>
#include <conio.h>
#include "windows.h"  
#include <ctime>
#include <vector>
#include <string>
#define KEY_UP 87
#define KEY_UP2 72
#define KEY_DOWN 83
#define KEY_DOWN2 80
#define KEY_ENTER 13
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
     //Header
    header_text = "Password generator v2.1 by Wiktor Kozakowski 2022";
     
	//Colors
    main_text_color = 14;
    main_text_select_color = 240;
    main_warning_color = 4; // header color too

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

	//Base func
    menu_init(); 
	      

}