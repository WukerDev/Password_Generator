#include <iostream>
#include "windows.h" 
#include <ctime>
#include <vector>
using namespace std;

//Data
const char data_numbers[] = { "0123456789" };
const char data_lower[] = { "abcdefghijklmnopqrstuvwxyz" };
const char data_upper[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
const char data_special_easy[] = { "`~!@#$%^&()-_=+" }; // special characters from numerical row of keyboard, easier to type
const char data_special_hard[] = { "{[}]<>?/" };
const char data_polish_special[] = { "ąęółśżźć" }; // my nationality based special
vector<char> data_summary;
int value_tries, value_length, value_choose, summing, value_length_max, value_length_min, value_tries_min, value_tries_max;
bool check_another, generating, check_numbers, check_lower, check_upper, check_special_easy, check_special_hard, check_polish_special;
string password;

const void title_header() {
    cout << "Password generator v1.2 by Wiktor Kozakowski\n";
};

void input_password_length() {
    while (true) {
        cout << "Please enter the length of the password: "; cin >> value_length;
        //check if value meet the criteria
        if (value_length >= value_length_min && value_length <= value_length_max) {
            break;
        }
        // if not, do it again
        else { cout << "Password need to have at least 6 characters and 2048 max!\n"; };
    };
};

void input_password_iterations() {
    while (true) {
        cout << "Please enter how many passwords you want to generate: "; cin >> value_tries;
        //check if value meet the criteria
        if (value_tries >= value_tries_min && value_tries <= value_tries_max) {
            break;
        }
        // if not, do it again
        else { cout << "You can generater at least 1 password and maximum ammount is 2048\n"; };
    };
};

void selecting_settings() {
    while (generating == 1) {
        system("CLS");
        cout << "1.Include Numbers:\t\t0123456789\n2.Include Lowercase Characters:\tabcdefghijklmnopqrstuvwxyz\n3.Include Uppercase Characters:\tABCDEFGHIJKLMNOPQRSTUVWXYZ\n4.Include Easy Symbols:\t\t`~!@#$%^&*()-_=+\n5.Include Hard Symbols:\t\t{[}]<>?/\n6.Include Polish Symbols:\tąęółśżźć\n";
        cout << "Current state of check boxes:\t" << "[1]:" << check_numbers << "\t[2]:" << check_lower << "\t[3]:" << check_upper << "\t[4]:" << check_special_easy << "\t[5]:" << check_special_hard << "\t[6]:" << check_polish_special;
        cout << "\nChoose the type of characters that need to be added to your password,\ntype the number to choose or enter anything else to generate: "; cin >> value_choose;
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

void generating_animation() {
    for (int j = 0; j < 4; j++) {
        cout << "\rGenerating   \rGenerating";
        for (int i = 0; i < 3; i++) {
            cout << ".";
            Sleep(250);
        }
    } //3 secund visual animation, user will think password is more secured :)
};

void generator_base_and_results() {
    cout << "Here are " << value_tries << " results of passwords : \n";
    for (int i = 0; i <= value_tries; i++) {
        for (int i = 0; i < value_length; i++) {
            int one_time_random = rand() % summing;
            password += data_summary[one_time_random];
        };//Main generation
        cout << password;
        cout << endl;
        password = "";
        Sleep(150);
    };//Generating more results
};

void end_info() {
    cout << "Do you want to generate another password?[1/0]: ";
    cin >> check_another;
    if (check_another == false) { cout << "Thank you for using the program!\n"; };
    if (check_another == true) { system("CLS"); };
};

int main()
{
    //Base settings
    system("COLOR 3F");
    srand(time(NULL));
    setlocale(LC_CTYPE, "Polish"); // for polish characters to work

    //Base values
    value_tries_min = 1;
    value_tries_max = 2048;
    value_length_max = 2048;
    //to change max array size, go to line 13
    value_length_min = 6;
    check_another = 1;
    value_tries = 1;
    summing = 0; // don't change this plz
    value_length = 6;
    value_choose = 6;
    generating = 1; // same here, don't change
    check_numbers = 0;
    check_lower = 0;
    check_upper = 0;
    check_special_easy = 0;
    check_special_hard = 0;
    check_polish_special = 0;

    //Base functions
    while (check_another == true) {
        title_header();
        input_password_length();
        input_password_iterations();
        selecting_settings();
        system("CLS");
        summing_the_size();
        generating_animation();
        system("CLS");
        generator_base_and_results();
        end_info();
    };
}