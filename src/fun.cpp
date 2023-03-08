// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cstddef>

unsigned int faStr1(const char *str) {
    int count = 0;
    bool inWord = false;
    bool noNamber = true;
    int i = 0;
    while (str[i - 1] != '\0') {
        if (str[i] != ' ' && inWord == false &&
            (str[i] < '0' || str[i]>'9')) {
            inWord = true;
        }
        if (str[i] >= '0' && str[i] <= '9' &&
            inWord == false && noNamber == true) {
            noNamber = false;
            inWord = true;
        }
        if (str[i] >= '0' && str[i] <= '9' &&
            inWord == true && noNamber == true) {
            noNamber = false;
        }
        if (str[i] == ' ' && inWord == true &&
            noNamber == false) {
            inWord = false;
            noNamber = true;
        }
        if ((str[i] == ' ' || str[i] == '\0') &&
            inWord == true && noNamber == true) {
            inWord = false;
            count++;
            noNamber = true;
        }

        i++;
    }
    //cout << count;
    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    bool stSymbol = false;
    bool inWord = false;
    bool noGarb = true;
    //bool firstSymbol = true;
    int i = 0;
    while (str[i - 1] != '\0') {
        if (inWord == true && stSymbol == true &&
            noGarb == true && (str[i] == ' ' || str[i] == '\0')) {
            inWord = false;
            stSymbol = false;
            noGarb = true;
            count++;
        }
        if (inWord == true && stSymbol == true &&
            (str[i] < 'a' || str[i]>'z')) {
            noGarb = false;
        }
        if (str[i] != ' ' && inWord == false &&
            str[i] >= 'A' && str[i] <= 'Z') {
            inWord = true;
            stSymbol = true;
            //firstSymbol = false;
        }
        if (str[i] != ' ' && inWord == false &&
            (str[i] <= 'A' || str[i] >= 'Z')) {
            inWord = true;
            stSymbol = false;
        }
        if (inWord == true && str[i] == ' ') {
            inWord = false;
            noGarb = true;
            //firstSymbol = true;
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char *str) {
       int i = 0;
    int countWord = 0;
    int countSymbol = 0;
    //double answer;
    bool inWord = false;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            countWord++;
        }
        if (str[i] == ' ' && inWord == true) {
            inWord = false;
        }
        i++;
    }
    i = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            countSymbol++;
        }
        i++;
    }
    return round(static_cast<double>(countSymbol) /
                 static_cast<double>(countWord));
}
