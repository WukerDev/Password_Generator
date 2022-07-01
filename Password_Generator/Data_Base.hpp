#pragma once
//Data
std::vector<char> data_summary;
int value_tries, value_length, value_choose, summing, value_length_max, value_length_min, value_tries_min, value_tries_max;
bool check_another, generating, check_numbers, check_lower, check_upper, check_special_easy, check_special_hard, check_polish_special;
std::string password;
const char data_numbers[] = { "0123456789" };
const char data_lower[] = { "abcdefghijklmnopqrstuvwxyz" };
const char data_upper[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
const char data_special_easy[] = { "`~!@#$%^&()-_=+" }; // special characters from numerical row of keyboard, easier to type
const char data_special_hard[] = { "{[}]<>?/" };
const char data_polish_special[] = { "¹êó³œ¿Ÿæ" }; // my nationality based special
