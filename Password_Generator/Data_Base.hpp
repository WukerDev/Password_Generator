#pragma once
//Data
std::vector<char> data_summary;
int value_tries, value_length, value_choose, summing, value_length_max, value_length_min, value_tries_min, value_tries_max;
bool check_another, generating, check_numbers=0, check_lower=0, check_upper=0, check_special_easy=0, check_special_hard=0, check_polish_special=0;
std::string password;
std::string header_text;
std::string menu_base[] = { "[ ]Include Numbers", "[ ]Include Lower Case", "Include Upper Case", "Include Special Easy", "Include Special Hard", "Include Polish Symbols", "Password length:", "Amount of passwords generated:", ">Generate<", "GitHub", "Exit" };
//Change colors
int main_text_color = 14;
int main_text_select_color = 240;
int main_warning_color = 4; // header color too
int selected = 1;
int pressed;
//do not touch

const char data_numbers[] = { "0123456789" };
const char data_lower[] = { "abcdefghijklmnopqrstuvwxyz" };
const char data_upper[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
const char data_special_easy[] = { "`~!@#$%^&()-_=+" }; // special characters from numerical row of keyboard, easier to type
const char data_special_hard[] = { "{[}]<>?/" };
const char data_polish_special[] = { "¹êó³œ¿Ÿæ" }; // my nationality based special
