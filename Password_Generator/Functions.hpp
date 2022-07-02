#pragma once


void input_password_length() {
    while (true) {
        std::cout << "Please enter the length of the password: "; std::cin >> value_length;
        //check if value meet the criteria
        if (value_length >= value_length_min && value_length <= value_length_max) {
            break;
        }
        // if not, do it again
        else { std::cout << "Password need to have at least 6 characters and 2048 max!\n"; };
    };
};

void input_password_iterations() {
    while (true) {
        std::cout << "Please enter how many passwords you want to generate: "; std::cin >> value_tries;
        //check if value meet the criteria
        if (value_tries >= value_tries_min && value_tries <= value_tries_max) {
            break;
        }
        // if not, do it again
        else { std::cout << "You can generater at least 1 password and maximum ammount is 2048\n"; };
    };
};

void selecting_settings() {
    while (generating == 1) {
        system("CLS");
        std::cout << "1.Include Numbers:\t\t0123456789\n2.Include Lowercase Characters:\tabcdefghijklmnopqrstuvwxyz\n3.Include Uppercase Characters:\tABCDEFGHIJKLMNOPQRSTUVWXYZ\n4.Include Easy Symbols:\t\t`~!@#$%^&*()-_=+\n5.Include Hard Symbols:\t\t{[}]<>?/\n6.Include Polish Symbols:\t¹êó³œ¿Ÿæ\n";
        std::cout << "Current state of check boxes:\t" << "[1]:" << check_numbers << "\t[2]:" << check_lower << "\t[3]:" << check_upper << "\t[4]:" << check_special_easy << "\t[5]:" << check_special_hard << "\t[6]:" << check_polish_special;
        std::cout << "\nChoose the type of characters that need to be added to your password,\ntype the number to choose or enter anything else to generate: "; std::cin >> value_choose;
        switch (value_choose) {
        case 1:
            check_numbers = !check_numbers;
            break;
        case 2:
            check_lower = !check_lower;
            break;
        case 3:
            check_upper = !check_upper;
            break;
        case 4:
            check_special_easy = !check_special_easy;
            break;
        case 5:
            check_special_hard = !check_special_hard;
            break;
        case 6:
            check_polish_special = !check_polish_special;
            break;
        default:
            if (check_polish_special == 1 || check_special_hard == 1 || check_special_easy == 1 || check_upper == 1 || check_lower == 1 || check_numbers == 1) {
                generating = 0;
            } // blocking generation of the password without data
            break;
        }
    }
};

void summing_the_size() { // summing up the data
    if (check_numbers == 1) {
        for (int x = 0; x < (sizeof(data_numbers) / sizeof(data_numbers[0])); x++) {
            data_summary.push_back(data_numbers[x]);
            summing++;
        };
    };
    if (check_lower == 1) {
        for (int x = 0; x < (sizeof(data_lower) / sizeof(data_lower[0])); x++) {
            data_summary.push_back(data_lower[x]);
            summing++;
        };
    };
    if (check_upper == 1) {
        for (int x = 0; x < (sizeof(data_upper) / sizeof(data_upper[0])); x++) {
            data_summary.push_back(data_upper[x]);
            summing++;
        };
    };
    if (check_special_easy == 1) {
        for (int x = 0; x < (sizeof(data_special_easy) / sizeof(data_special_easy[0])); x++) {
            data_summary.push_back(data_special_easy[x]);
            summing++;
        };
    };
    if (check_special_hard == 1) {
        for (int x = 0; x < (sizeof(data_special_hard) / sizeof(data_special_hard[0])); x++) {
            data_summary.push_back(data_special_hard[x]);;
            summing++;
        };
    };
    if (check_polish_special == 1) {
        for (int x = 0; x < (sizeof(data_polish_special) / sizeof(data_polish_special[0])); x++) {
            data_summary.push_back(data_polish_special[x]);
            summing++;
        };
    };
};



void generator_base_and_results() {
    std::cout << "Here are " << value_tries << " results of passwords : \n";
    for (int i = 0; i < value_tries; i++) {
        for (int i = 0; i < value_length; i++) {
            int one_time_random = rand() % summing;
            password += data_summary[one_time_random];
        };//Main generation
        Sleep(150);
        std::cout << password;
        std::cout << std::endl;
        password = "";
        
    };//Generating more results
    std::cout << "Press anything to go back";
    pressed = _getche();
};

