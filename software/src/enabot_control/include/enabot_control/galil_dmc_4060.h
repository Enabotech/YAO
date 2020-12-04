#ifndef __GALIL_DMC_4060_H__
#define __GALIL_DMC_4060_H__

#define _CRT_SECURE_NO_WARNINGS //use traditional C calls like sprintf()
#include <iomanip>
#include <iostream> //std::cout
#include <string> //to_string, string, etc.
#include <cstdio> //sprintf, etc.
#include <cstring> //strlen, etc.
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "gclib.h"
#include "gclibo.h"

#define TEST_CONTROLLER
#define GEAR_REDUCETION_RATION 50
#define STEP_ANGLE 0.36
#define STEP_SUBDIVISION 10
#define ANGLE2PULSE (((GEAR_REDUCETION_RATION)*(STEP_SUBDIVISION))/(STEP_ANGLE))
#define PULSE2ANGLE (STEP_ANGLE/((GEAR_REDUCETION_RATION)*(STEP_SUBDIVISION)*4))

using namespace std;

inline int Angle2Pulse(float GearReducetionRatio, float StepAngle, int StepSubdivision, float Angle)
{
	return (int) ((GearReducetionRatio * StepSubdivision * Angle) / StepAngle);
}

inline void x_e(GReturn rc)
{
	if (rc != G_NO_ERROR) 
	{
		cout << "exception return: " << rc << "\n";
		return;
	}
}


template<char T>
class WordSplitSign : public string {};

template<char T>
istream& operator >> (istream& is, WordSplitSign<T>& output) {
    getline(is, output, T);
    return is;
};


//void WordSplit(string s, string *Word[]);
vector<string> strSplit(string s, const char * split);
int GetMotorState(GCon *g, int Position[], int Velocity[], int Torque[]);


int MotorControllerInit(GCon *g);
int MotorTest(GCon *g, float TarPos[]);


#endif /*__GALIL_DMC_4060_H__*/
