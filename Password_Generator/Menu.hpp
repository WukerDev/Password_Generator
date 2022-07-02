
void menu() {
    header();
    if (selected == 0) {
        selected = sizeof(menu_base) / sizeof(menu_base[0]);
    };
    if (selected > sizeof(menu_base) / sizeof(menu_base[0])) {
        selected = 1;
    };
    for (int i = 1; i <= sizeof(menu_base) / sizeof(menu_base[0]); i++) {
         if (i == selected) { text_sel(menu_base[i - 1]); };
         if (i != selected) { text_def(menu_base[i - 1]); };
        // selection
    }
};

void checkbox() {
	menu_base[6]= "Password length:[" + std::to_string(value_length) + "]";
    menu_base[7] = "Password ammount:[" + std::to_string(value_tries) + "]";
    if (check_numbers == 1) {
        menu_base[0] = "[X]Include Numbers";
    }
    if (check_numbers == 0) {
        menu_base[0] = "[ ]Include Numbers";
    }
    if (check_lower == 1) {
        menu_base[1] = "[X]Include Lower Case";
    }
    if (check_lower == 0) {
        menu_base[1] = "[ ]Include Lower Case";
    }
    if (check_upper == 1) {
        menu_base[2] = "[X]Include Upper Case";
    }
    if (check_upper == 0) {
        menu_base[2] = "[ ]Include Upper Case";
    }
    if (check_special_easy == 1) {
        menu_base[3] = "[X]Include Easy Symbols";
    }
    if (check_special_easy == 0) {
        menu_base[3] = "[ ]Include Easy Symbols";
    }
    if (check_special_hard == 1) {
        menu_base[4] = "[X]Include Hard Symbols";
    }
    if (check_special_hard == 0) {
        menu_base[4] = "[ ]Include Hard Symbols";
    }
    if (check_polish_special == 1) {
        menu_base[5] = "[X]Include Polish Symbols";
    }
    if (check_polish_special == 0) {
        menu_base[5] = "[ ]Include Polish Symbols";
    }
    //Checking if the state of the checkbox is 1 or 0 and changing the text of the menu option accordingly
}


void selection() {
    while (true) {
        checkbox();
        //main menu selection, another selection can be added to each select option
        pressed = _getch();
        pressed = toupper(pressed);
        if (pressed == KEY_UP || pressed == KEY_UP2) { selected--; };
        if (pressed == KEY_DOWN || pressed == KEY_DOWN2) { selected++; };
        if (pressed == KEY_ENTER) {
            if (selected == 1) {
              
                check_numbers = !check_numbers;
                checkbox();
            }
            if (selected == 2) {
              
                check_lower = !check_lower;
                checkbox();
            }
            if (selected == 3) {
                
                check_upper = !check_upper;
                checkbox();

            }


			if (selected == 4) {
				
                check_special_easy = !check_special_easy;
                checkbox();
			}
			if (selected == 5) {
				
                check_special_hard = !check_special_hard;
                checkbox();
				}
			if (selected == 6) {
				
				check_polish_special = !check_polish_special;
                checkbox();
				}
			if (selected == 7) {
                input_password_length();
                checkbox();
				}
			if (selected == 8) {
                input_password_iterations();
                checkbox();
                }
			if (selected == 9) { 
				system("CLS");
                summing_the_size();
                generator_base_and_results();
                
				}
			if (selected == 10) {
                system("start /max https://github.com/WukerDev");
				}
			if (selected == 11) { 
				system("CLS");
				exit(0);
				}
        };
		// if the user presses enter, the selected option will be executed
        system("CLS");
        menu();
        // do not touch, it is used to refresh the menu
    }
};

void menu_init()
{
    checkbox();
    menu();
    selection();

}