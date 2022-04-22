#include <Arduino.h>
#include "Config/pins.h"
#include "SevenSegment/sevenSegment.h"
#include "Config/pins.h"

int pins[] = {A,B,C,D,E,F,G,DP};


int numbers[10][8] = {
	{1,1,1,1,1,1,0,0}, // 0
	{0,1,1,0,0,0,0,0}, // 1
	{1,1,0,1,1,0,1,0}, // 2
    {1,1,1,1,0,0,1,0}, // 3
    {0,1,1,0,0,1,1,0}, // 4
    {1,0,1,1,0,1,1,0}, // 5
    {0,0,1,1,1,1,1,0}, // 6
    {1,1,1,0,0,0,0,0}, // 7
    {1,1,1,1,1,1,1,0}, // 8
    {1,1,1,0,0,1,1,0}  // 9
};

int patterns[][8] = {
    {1,0,0,1,0,0,1,0},
    {0,1,1,0,1,1,0,0}
};

char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'n', 'o', 'p', 'r'};

int letterBit[][8] = {
    {1,1,1,0,1,1,1,0}, // A
    {0,0,1,1,1,1,1,0}, // b
    {0,0,0,1,1,0,1,0}, // c
    {0,1,1,1,1,0,1,0}, // d
    {1,0,0,1,1,1,1,0}, // E
    {1,0,0,0,1,1,1,0}, // F
    {1,0,1,1,1,1,1,0}, // G
    {0,1,1,0,1,1,1,0}, // H
    {0,0,0,0,1,1,0,0}, // I
    {0,1,1,1,0,0,0,0}, // J
    {0,0,0,1,1,1,0,0}, // L
    {0,0,1,0,1,0,1,0}, // n
    {0,0,1,1,1,0,1,0}, // o
    {1,1,0,0,1,1,1,0}, // P
    {0,0,0,0,1,0,1,0}  // r
};

/**
 * @brief This is to init the seven segment displays
 * 
 */
void sevenSegment::init(){
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(DP, OUTPUT);

    // Segment 1
    pinMode(SEG1_1, OUTPUT);
    pinMode(SEG1_2, OUTPUT);
    pinMode(SEG1_3, OUTPUT);
    pinMode(SEG1_4, OUTPUT);

    // Segment 2
    pinMode(SEG2_1, OUTPUT);
    pinMode(SEG2_2, OUTPUT);
    pinMode(SEG2_3, OUTPUT);
    pinMode(SEG2_4, OUTPUT);
}

/**
 * @brief Write the time on the seven segment displays
 * 
 * @param num double
 * @param kart The kart that this time goes to
 */
void sevenSegment::writeTime(double num, kart kart){
    String str = String(num, 5);
    char ch[10];
    str.toCharArray(ch, 10);
    for(int i = 0; i<4; i++){
        if(ch[i] == '.'){continue;}
        writeNum(ch[i]-'0', kart, i+1, ch[i+1] == '.' ? false:true);
    }
}

/**
 * @brief Write any number to any part of the seven segment
 * 
 * @param num The number you wish to display
 * @param kart The kart side you wish to display
 * @param place The place value of the chosen display
 * @param dec If there is a decimal on the given number (defaults to false)
 */
void sevenSegment::writeNum(int num, kart kart, int place, boolean dec = false){
    if(kart == LEFT){
        digitalWrite(SEG1_1, LOW);
        digitalWrite(SEG1_2, LOW);
        digitalWrite(SEG1_3, LOW);
        digitalWrite(SEG1_4, LOW);
        if(place == 1){
            digitalWrite(SEG1_1, HIGH);
        }else if(place == 2){
            digitalWrite(SEG1_2, HIGH);
        }else if(place == 3){
            digitalWrite(SEG1_3, HIGH);
        }else{
            digitalWrite(SEG1_4, HIGH);
        } 
    }else{
        digitalWrite(SEG2_1, LOW);
        digitalWrite(SEG2_2, LOW);
        digitalWrite(SEG2_3, LOW);
        digitalWrite(SEG2_4, LOW);
        if(place == 1){
            digitalWrite(SEG2_1, HIGH);
        }else if(place == 2){
            digitalWrite(SEG2_2, HIGH);
        }else if(place == 3){
            digitalWrite(SEG2_3, HIGH);
        }else{
            digitalWrite(SEG2_4, HIGH);
        }
    }

    for(int i = 0; i<8; i++){
            digitalWrite(pins[i], numbers[num][i] == 1 ? LOW:HIGH);
        }

    if(dec){digitalWrite(pins[7], LOW);}
}

/**
 * @brief Writes a list to the displays
 * 
 * @param list This list is an integer value of 0 or 1 that tells which part of the segment to light up
 */
void sevenSegment::writeList(int list[8]){
    for(int i=0;i<4;i++){
        digitalWrite(pins[i], list[i] == 1 ? LOW:HIGH);
    }
}

/**
 * @brief Write a word to the segments
 * 
 * @param word The four letter string you wish to write
 * @param kart Which side you wish to write it
 */
void sevenSegment::writeWord(String word, kart kart){
    char let[4];
    word.toCharArray(let, 4);

    int let_int[4];
    for(int i=0; i<4; i++){
        for(byte a=0; a<(sizeof(letters)/sizeof(letters[0])); a++){
            if(letters[a] == let[i]){
                let_int[i] = a;
                break;
            }
        }
    }

    for(int b=0; b<4; b++){
        writeNum(let_int[b], kart, b);
    }

}

