#ifndef __ENABOT_CONTROL_H__
#define __ENABOT_CONTROL_H__

#include <termios.h>
#include <signal.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <fstream>

#include <list>

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/String.h>

#include <actionlib/server/simple_action_server.h>//header is the standard action library to implement an action server node

#include <control_msgs/FollowJointTrajectoryAction.h>////The header is generated from the stored action files

#include "enabot_comm.h"


struct robotState
{
	float j[MAX_JOINT_NUM];		// joint position
	float duration;	// duration for motion; needed for actionServer
};

namespace dual_arm_robot
{

	// the struct stores information about the current robots state:
	// joint positions, cartesian position and error code

	class enabot_control
	{

		private:

			bool flag_stop_requested;

			robotState r_setPointState;
			robotState r_targetState;
			robotState l_setPointState;
			robotState l_targetState;

			int JointsNum;
			double cycleTime; /* in ms */

			//control data def	
			float r_controlData[MAX_JOINT_NUM];	/* final control data */
			float r_executeData[MAX_JOINT_NUM];
			float l_controlData[MAX_JOINT_NUM];	/* final control data */
			float l_executeData[MAX_JOINT_NUM];
			float r_executeData_old[MAX_JOINT_NUM];
			float l_executeData_old[MAX_JOINT_NUM];
			float neck_controlData[2];

			RobComm Comm;

			ros::NodeHandle nh;
			sensor_msgs::JointState r_msgJointsCurrent;	/* the current joints */
			sensor_msgs::JointState l_msgJointsCurrent;	/* the current joints */
			ros::Publisher  pubJoints; /* publishes the current joint positions  */

			void MotionGeneration();
			void CommunicationHW();
			void L_CommunicationROS();
			void R_CommunicationROS();
			
			
		public:
			~enabot_control();
			void init();
			void mainLoop();				
	};

}


#endif
