
// Segment 1 / track 1 / Left
// Segment numbering
//       A
//     ______
//    |      |
//  F |      | B
//    |___G__|
//    |      |
//  E |      | B _
//    |______|  |_| DP
//       D 
#define A1 22
#define B1 24
#define C1 26
#define D1 28
#define E1 30
#define F1 32
#define G1 34
#define DP1 36
// Which segment they are
#define SEG1_1 38
#define SEG1_2 40
#define SEG1_3 42
#define SEG1_4 44

// Segment 2 / track 2 / Right
// Segment numbering
//       A
//     ______
//    |      |
//  F |      | B
//    |___G__|
//    |      |
//  E |      | B _
//    |______|  |_| DP
//       D 
#define A2 23
#define B2 25
#define C2 27
#define D2 29
#define E2 31
#define F2 33
#define G2 35
#define DP2 37
// Which segment they are
#define SEG2_1 39
#define SEG2_2 41
#define SEG2_3 43
#define SEG2_4 45

// Debug RGB
#define LED_R A0
#define LED_G A1
#define LED_B A2

// The pressure sensor
#define PRESSURE_SENSOR A5

// The button we press to launch the karts
#define LAUNCH_BTN

// The valves the control the air
#define ARM_VALVE
#define LAUNCH_VALVE
#define RELEASE_VALVE

// The detectors that detect when a kart passes a line
#define FINISH_LINE_LEFT
#define FINISH_LINE_RIGHT