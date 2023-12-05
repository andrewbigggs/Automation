//
//  main.cpp
//
//
//  Created by Andrew J Biggs on 12/1/23.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string DecimalToBinary (long decimal) {
    vector<long> bits;
    long number = decimal;
    string binary = "";
    
    while (number > 0) {
        bits.push_back(number % 2);
        number = number / 2;
    }
    reverse(bits.begin(), bits.end());
    int i;
    for (i = 0; i < bits.size(); i++) {
        binary += to_string(bits[i]);
    }
    
    cout << binary << endl;
    
    return binary;
}

void BinaryToTrigrams (string binary) {
    string bin = binary;
    vector<string> trigrams;
    vector<string> planets;
    
    if ((bin.size() % 3) == 2) {
        bin = "0" + bin;
    }
    else if ((bin.size() % 3) == 1) {
        bin = "00" + bin;
    }
    int i;
    string first, second, third = "";
    string trigram, planet;
    
    for (i = 0; i <= bin.size(); i++) {
        if ((i % 3 == 0) && (first != "")) {
            trigram = "";
            planet = "";
            if (first == "1") {
                if (second == "1") {
                    if (third == "1") {
                        trigram = "☰";
                        planet = "♃";
                    }
                    else {
                        trigram = "☴";
                        planet = "☾";
                    }
                }
                else {
                    if (third == "1") {
                        trigram = "☲";
                        planet = "☉";
                    }
                    else {
                        trigram = "☶";
                        planet = "♂";
                    }
                }
            }
            else {
                if (second == "1") {
                    if (third == "1") {
                        trigram = "☱";
                        planet = "♃";
                    }
                    else {
                        trigram = "☵";
                        planet = "♄";
                    }
                }
                else {
                    if (third == "1") {
                        trigram = "☳";
                        planet = "☿";
                    }
                    else {
                        trigram = "☷";
                        planet = "♀";
                    }
                }
            }
            trigrams.push_back(trigram);
            planets.push_back(planet);
        }
        
        if (i < bin.size()) {
            if (i % 3 == 0)
                first = bin[i];
            else if (i % 3 == 1)
                second = bin[i];
            else if (i % 3 == 2)
                third = bin[i];
        }
    }
    
    for (i = 0; i < trigrams.size(); i++) {
        cout << trigrams[i] << " ";
    }
    
    cout << endl;
    
    for (i = 0; i < planets.size(); i++) {
        cout << planets[i] << " ";
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    long input;
    while (true) {
        cout << "Enter a decimal number less than 9,223,372,036,854,775,807 to convert to binary:\n";
        cin >> input;
        if (input == -1) {
            break;
        }
        string binary;
        
        binary = DecimalToBinary(input);
        BinaryToTrigrams(binary);
        
    }
    return 0;
}
