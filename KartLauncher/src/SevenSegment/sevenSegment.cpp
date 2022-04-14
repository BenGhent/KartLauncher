#include <Arduino.h>
#include "Config/pins.h"
#include "SevenSegment/sevenSegment.h"

int numbers[10][7] = {
	{1,1,1,1,1,1,0}, // 0
	{0,1,1,0,0,0,0}, // 1
	{1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {0,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,0,0,1,1}  // 9
};

int patterns[][8] = {
    {1,0,0,1,0,0,1,0},
    {0,1,1,0,1,1,0,0}
};

void sevenSegment::init(){
    // Segment 1
    pinMode(A1, OUTPUT);
    pinMode(B1, OUTPUT);
    pinMode(C1, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(E1, OUTPUT);
    pinMode(F1, OUTPUT);
    pinMode(G1, OUTPUT);
    pinMode(DP1, OUTPUT);
    pinMode(SEG1_1, OUTPUT);
    pinMode(SEG1_2, OUTPUT);
    pinMode(SEG1_3, OUTPUT);
    pinMode(SEG1_4, OUTPUT);

    // Segment 2
    pinMode(A2, OUTPUT);
    pinMode(B2, OUTPUT);
    pinMode(C2, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(F2, OUTPUT);
    pinMode(G2, OUTPUT);
    pinMode(DP2, OUTPUT);
    pinMode(SEG2_1, OUTPUT);
    pinMode(SEG2_2, OUTPUT);
    pinMode(SEG2_3, OUTPUT);
    pinMode(SEG2_4, OUTPUT);
}

void sevenSegment::writeNum(double num, int kart){

}