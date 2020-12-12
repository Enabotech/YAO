#ifndef __ENABOT_COMM_H__
#define __ENABOT_COMM_H__

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <galil_dmc_4060.h>

#define MAX_JOINT_NUM		7
#define MAX_LINK_NUM		7
#define __RIGHT_ARM__
//#define __LEFT_ARM__

class RobComm {
public:
	RobComm();
	virtual ~RobComm();

	//bool flagDoComm;
	int JointsNum;
	float Rx_buf_right[MAX_JOINT_NUM - 1];    
	float Rx_buf_left[MAX_JOINT_NUM - 1];                  
	float Tx_buf[MAX_JOINT_NUM*2 - 1];

	//void Init(std::string robotType);
	void SetRightJoints(float * j);
	void SetLeftJoints(float * j);
	void GetJoints(float * j);
};

#endif










