#include <enabot_control.h>
#include <galil_dmc_4060.h>
#include <list>

//#include "armplaning_client.h"


using namespace std;

#ifdef __RIGHT_ARM__
typedef actionlib::SimpleActionServer<control_msgs::FollowJointTrajectoryAction> R_TrajectoryServer;
std::list<robotState> r_targetPointList;		// list of points to move to
#endif //__RIGHT_ARM__

#ifdef __LEFT_ARM__
typedef actionlib::SimpleActionServer<control_msgs::FollowJointTrajectoryAction> L_TrajectoryServer;
std::list<robotState> l_targetPointList;		// list of points to move to
#endif //__LEFT_ARM__

double deg2rad = (3.1415926535897931/180.0);
double rad2deg = (180.0/3.1415926535897931);
 


GCon g = 0;

#ifdef __RIGHT_ARM__
//***************************************************************************
// Processing and JointTrajectoryAction
void r_executeTrajectory(const control_msgs::FollowJointTrajectoryGoalConstPtr& r_goal, R_TrajectoryServer* r_as)
{
  robotState rs;

  float lastDuration = 0.0;


  int nrOfPoints = r_goal->trajectory.points.size();		// Number of points to add
  for(int i=0; i<nrOfPoints; i++)
  {
	  // ros values come in rad, internally we work in degree
	  rs.j[0] = r_goal->trajectory.points[i].positions[0]*rad2deg;	//j1
	  rs.j[1] = r_goal->trajectory.points[i].positions[1]*rad2deg;	//j2
	  rs.j[2] = r_goal->trajectory.points[i].positions[2]*rad2deg;	//j3
	  rs.j[3] = r_goal->trajectory.points[i].positions[3]*rad2deg;	//j4
	  rs.j[4] = r_goal->trajectory.points[i].positions[4]*rad2deg;	//j5
	  rs.j[5] = r_goal->trajectory.points[i].positions[5]*rad2deg;	//j6
	  rs.j[6] = r_goal->trajectory.points[i].positions[6]*rad2deg;	//j7

	  float dtmp = r_goal->trajectory.points[i].time_from_start.toSec();
	  rs.duration = dtmp - lastDuration;// time_from_start is adding up, these values are only for the single motion
	  lastDuration = dtmp;

	  r_targetPointList.push_back(rs);//push_back() 在list的末尾添加一个元素 

      ROS_INFO("right arm recv position: %d, %d, %d, %d, %d, %d, %d, duration: %f", \
			(int)(r_goal->trajectory.points[i].positions[0]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].positions[1]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].positions[2]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].positions[3]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].positions[4]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].positions[5]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].positions[6]*rad2deg*ANGLE2PULSE), \
			r_goal->trajectory.points[i].time_from_start.toSec());

      ROS_INFO("right arm recv velocity: %d, %d, %d, %d, %d, %d, %d, duration: %f", \
			(int)(r_goal->trajectory.points[i].velocities[0]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].velocities[1]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].velocities[2]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].velocities[3]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].velocities[4]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].velocities[5]*rad2deg*ANGLE2PULSE), \
			(int)(r_goal->trajectory.points[i].velocities[6]*rad2deg*ANGLE2PULSE), \
			r_goal->trajectory.points[i].time_from_start.toSec());
  }

  r_as->setSucceeded();

  //debug msg
 ROS_INFO("final right arm recv position: %f %f %f %f %f %f %f,duration: %f", rs.j[0],rs.j[1],rs.j[2],rs.j[3],rs.j[4],rs.j[5],rs.j[6],rs.duration);

}
#endif //__RIGHT_ARM__


#ifdef __LEFT_ARM__
//***************************************************************************
// Processing and JointTrajectoryAction
void l_executeTrajectory(const control_msgs::FollowJointTrajectoryGoalConstPtr& l_goal, R_TrajectoryServer* l_as)
{
  //double rad2deg = 180.0 / 3.141;

 robotState ls;

 float lastDuration = 0.0;

  int nrOfPoints = l_goal->trajectory.points.size();		// Number of points to add
  for(int i=0; i<nrOfPoints; i++){
	  ls.j[0] = l_goal->trajectory.points[i].positions[0]*rad2deg;	// ros values come in rad, internally we work in degree
	  ls.j[1] = l_goal->trajectory.points[i].positions[1]*rad2deg;
	  ls.j[2] = l_goal->trajectory.points[i].positions[2]*rad2deg;
	  ls.j[3] = l_goal->trajectory.points[i].positions[3]*rad2deg;
	  ls.j[4] = l_goal->trajectory.points[i].positions[4]*rad2deg;
	  ls.j[5] = l_goal->trajectory.points[i].positions[5]*rad2deg;
	  ls.j[6] = l_goal->trajectory.points[i].positions[6]*rad2deg;
	  
	  float dtmp = l_goal->trajectory.points[i].time_from_start.toSec();
	  ls.duration = dtmp - lastDuration;// time_from_start is adding up, these values are only for the single motion
	  lastDuration = dtmp;

	  l_targetPointList.push_back(ls);//push_back() 在list的末尾添加一个元素 
  }
  l_as->setSucceeded();

  //debug msg
 ROS_INFO("left arm recv: %f %f %f %f %f %f %f,duration: %f", ls.j[0],ls.j[1],ls.j[2],ls.j[3],ls.j[4],ls.j[5],ls.j[6],ls.duration);
}
#endif //__LEFT_ARM__

//*************************************************************************
void quit(int sig)
{
  ros::shutdown();
  exit(0);
}

//******************** MAIN ************************************************
int main(int argc, char** argv)
{
	ros::init(argc, argv, "enabot_mover");
	ros::NodeHandle n2;


	ROS_INFO("...connect to galil motion controller... return conde is [%d]",  MotorControllerInit(&g));

#ifdef __RIGHT_ARM__
	//Start the ActionServer for JointTrajectoryActions and GripperCommandActions from MoveIT
	R_TrajectoryServer r_tserver(n2, "enabot_mover_r/follow_joint_trajectory", boost::bind(&r_executeTrajectory, _1, &r_tserver), false);
  	ROS_INFO("TrajectoryActionServer: Starting");
  	r_tserver.start();
#endif //__RIGHT_ARM__

#ifdef __LEFT_ARM__
	L_TrajectoryServer l_tserver(n2, "enabot_mover_l/follow_joint_trajectory", boost::bind(&l_executeTrajectory, _1, &l_tserver), false);
  	ROS_INFO("TrajectoryActionServer: Starting");
  	l_tserver.start();
#endif //__LEFT_ARM__

	// Start the robot
	dual_arm_robot::enabot_control robot;
	robot.init();	
	robot.mainLoop();		//spinning is done inside the main loop			

  	signal(SIGINT,quit);	
	return(0);
}

namespace dual_arm_robot
{
	//*************************************************************************************

	enabot_control::~enabot_control(){

	}
	//*************************************************************************************
	void enabot_control::init(){
		ROS_INFO("...initing...");

		flag_stop_requested = false;
		//this deside the control msg send frequency 
		cycleTime = 20.0;// in ms
		nrOfJoints = MAX_JOINT_NUM;

#ifdef __RIGHT_ARM__
		r_setPointState.j[0] =  0.0;	// values are initialized with 6 field to be usable for rob right arm 
		r_setPointState.j[1] =  0.0;
		r_setPointState.j[2] =  0.0;
		r_setPointState.j[3] =  0.0;
		r_setPointState.j[4] =  0.0;
		r_setPointState.j[5] =  0.0;
		r_setPointState.j[6] =  0.0;
		r_setPointState.duration = 0;
#endif //__RIGHT_ARM__

#ifdef __LEFT_ARM__
		l_setPointState.j[0] =  0.0;	// values are initialized with 6 field to be usable for rob left arm 
		l_setPointState.j[1] =  0.0;
		l_setPointState.j[2] =  0.0;
		l_setPointState.j[3] =  0.0;
		l_setPointState.j[4] =  0.0;
		l_setPointState.j[5] =  0.0;
		l_setPointState.j[6] =  0.0;
		l_setPointState.duration = 0;
#endif //__LEFT_ARM__

		// when starting up (or when reading the HW joint values) the target position has to be aligned with the setPoint position
		for(int i=0; i<nrOfJoints; i++)
		{
#ifdef __RIGHT_ARM__
			r_targetState.j[i] = r_setPointState.j[i];
#endif //__RIGHT_ARM__

#ifdef __LEFT_ARM__
			l_targetState.j[i] = l_setPointState.j[i];
#endif //__LEFT_ARM__
		}
			
#ifdef __RIGHT_ARM__
        	r_targetState.duration = 0.0;	//init the timeStamp
#endif //__RIGHT_ARM__

#ifdef __LEFT_ARM__
		l_targetState.duration = 0.0;	//init the timeStamp
#endif //__LEFT_ARM__

		for(int j=0; j<=nrOfJoints; j++)
		{
#ifdef __RIGHT_ARM__
			r_controlData[j] = 0;
#endif //__RIGHT_ARM__

#ifdef __LEFT_ARM__
			l_controlData[j] = 0;
#endif //__LEFT_ARM__
		}

#ifdef __RIGHT_ARM__
		r_msgJointsCurrent.header.stamp = ros::Time::now();
		r_msgJointsCurrent.name.resize(MAX_JOINT_NUM);
		r_msgJointsCurrent.position.resize(MAX_JOINT_NUM);
		r_msgJointsCurrent.name[0] ="enabot_joint_1_r";
		r_msgJointsCurrent.position[0] = 0.0;
		r_msgJointsCurrent.name[1] ="enabot_joint_2_r";
		r_msgJointsCurrent.position[1] = 0.0;
		r_msgJointsCurrent.name[2] ="enabot_joint_7_r";
		r_msgJointsCurrent.position[2] = 0.0;
		r_msgJointsCurrent.name[3] ="enabot_joint_3_r";
		r_msgJointsCurrent.position[3] = 0.0;
		r_msgJointsCurrent.name[4] ="enabot_joint_4_r";
		r_msgJointsCurrent.position[4] = 0.0;
		r_msgJointsCurrent.name[5] ="enabot_joint_5_r";
		r_msgJointsCurrent.position[5] = 0.0;
		r_msgJointsCurrent.name[6] ="enabot_joint_6_r";
		r_msgJointsCurrent.position[6] = 0.0;
#endif //__RIGHT_ARM__

#ifdef __LEFT_ARM__
		l_msgJointsCurrent.header.stamp = ros::Time::now();
		l_msgJointsCurrent.name.resize(MAX_JOINT_NUM);
		l_msgJointsCurrent.position.resize(MAX_JOINT_NUM);
		l_msgJointsCurrent.name[0] ="enabot_joint_1_l";
		l_msgJointsCurrent.position[0] = 0.0;
		l_msgJointsCurrent.name[1] ="enabot_joint_2_l";
		l_msgJointsCurrent.position[1] = 0.0;
		l_msgJointsCurrent.name[2] ="enabot_joint_7_l";
		l_msgJointsCurrent.position[2] = 0.0;
		l_msgJointsCurrent.name[3] ="enabot_joint_3_l";
		l_msgJointsCurrent.position[3] = 0.0;
		l_msgJointsCurrent.name[4] ="enabot_joint_4_l";
		l_msgJointsCurrent.position[4] = 0.0;
		l_msgJointsCurrent.name[5] ="enabot_joint_5_l";
		l_msgJointsCurrent.position[5] = 0.0;
		l_msgJointsCurrent.name[6] ="enabot_joint_6_l";
		l_msgJointsCurrent.position[6] = 0.0;
#endif //__LEFT_ARM__

		// Publish the current joint states
		pubJoints = n.advertise<sensor_msgs::JointState>("/joint_states", 1);

	}

	//*************************************************************************************
	void enabot_control::mainLoop()
	{
  		ROS_INFO("Starting Mover Main Loop");
		
		//output angle data to a txt file
		int i = 0;
  		
 	 	for(;;)
  		{
			MotionGeneration();			// Generate the joint motion 
			CommunicationHW();			// Forward the new setpoints to the hardware

			if(flag_stop_requested)
				break;

			ros::spinOnce();

  			//ros::MultiThreadedSpinner s(2);  //多线程
  			//ros::spin(s);  

			ros::Duration(cycleTime/1000.0).sleep();		// main loop with 20 Hz.(50/1000=0.05s=50ms)
  		}

		ROS_INFO("Closing Mover Main Loop");

		if (g) x_e(GClose(g)); 
		{
			g = 0; //close g
			ROS_INFO("...dmc controller closed...");
		}
	} 
	//************************************************************************************
	//
	void enabot_control::MotionGeneration()
	{
		int i=0;
		int j=0;

		//printf("r_targetPointList.size() = %ld \n",r_targetPointList.size());
       
#ifdef __RIGHT_ARM__
		if(r_targetPointList.size() > 0)
		{
			r_targetState = r_targetPointList.front();
			r_targetPointList.pop_front();

			for(int i=0; i<nrOfJoints; i++)
			{
				r_setPointState.j[i] = r_targetState.j[i];
			}
			r_setPointState.duration = r_targetState.duration;
			
			for(j=0;j<nrOfJoints;j++)
			{
				r_controlData[j] = r_setPointState.j[j];
			}
			r_controlData[MAX_JOINT_NUM] = r_setPointState.duration;
		}

#endif

#ifdef __LEFT_ARM__
		if(l_targetPointList.size() > 0)
		{

			l_targetState = l_targetPointList.front();
			l_targetPointList.pop_front();

			for(int i=0; i<nrOfJoints; i++)
			{
				l_setPointState.j[i] = l_targetState.j[i];
			}
			l_setPointState.duration = l_targetState.duration;
			
			for(j=0;j<nrOfJoints;j++)
			{
				l_controlData[j] = l_setPointState.j[j];
			}
			l_controlData[MAX_JOINT_NUM] = l_setPointState.duration;
		}
#endif
	}
	//************************************************************************************
	// Forward the new setpoints to the hardware

	void enabot_control::CommunicationHW()
	{

		int i = 0;
		for(i=0; i<=nrOfJoints; i++)//write right arm control data
		{
#ifdef __RIGHT_ARM__
			r_executeData[i] = r_controlData[i];
#endif

#ifdef __LEFT_ARM__
			l_executeData[i] = l_controlData[i];
#endif
		}

#ifdef __RIGHT_ARM__
		if(r_executeData[0]!=r_executeData_old[0] && r_executeData[1]!=r_executeData_old[1])
		{
			
			//add send mesage command here	
			//************************************
			ROS_INFO("motor testing ... angle: [%f][%f][%f][%f][%f][%f][%f] ... return code: [%d]", \
			r_executeData[0], r_executeData[1], r_executeData[2], r_executeData[3], r_executeData[4], r_executeData[5], r_executeData[6], \
			MotorTest(&g, r_executeData));



			Comm.SetRightJoints(r_executeData);//send new target angle 
			ROS_INFO("Right arm MSG [%f][%f][%f][%f][%f][%f][%f][%f]", r_executeData[0],r_executeData[1],r_executeData[2],r_executeData[3],r_executeData[4],r_executeData[5],r_executeData[6],r_executeData[7]);

			//save the date to old
			for (int i=0;i<=nrOfJoints;i++)
			{
				r_executeData_old[i] = r_executeData[i];
			}



			R_CommunicationROS();			// Publish the joint states and error info
		}
#endif

#ifdef __LEFT_ARM__
		if(l_executeData[0]!=l_executeData_old[0] && l_executeData[1]!=l_executeData_old[1])
		{
			//add send mesage command here		
			//************************************

			Comm.SetLeftJoints(l_executeData);//send new target angle 

			//************************************


			ROS_INFO("Left arm MSG [%f][%f][%f][%f][%f][%f][%f][%f]", l_executeData[0],l_executeData[1],l_executeData[2],l_executeData[3],l_executeData[4],l_executeData[5],l_executeData[6],l_executeData[7]);

			//save the date to old
			for (int i=0;i<=nrOfJoints;i++)
			{
				l_executeData_old[i] = l_executeData[i];
			}

			L_CommunicationROS();			// Publish the joint states and error info
		}
#endif
	}

#ifdef __RIGHT_ARM__
	//************************************************************************************
	// forward the current joints to RViz etc
	void enabot_control::R_CommunicationROS()
	{
		r_msgJointsCurrent.header.stamp = ros::Time::now();
		r_msgJointsCurrent.position[0] = r_executeData[0]*deg2rad;		// Robot SER communication works in degree
		r_msgJointsCurrent.position[1] = r_executeData[1]*deg2rad;
		r_msgJointsCurrent.position[2] = r_executeData[2]*deg2rad;
		r_msgJointsCurrent.position[3] = r_executeData[3]*deg2rad;
		r_msgJointsCurrent.position[4] = r_executeData[4]*deg2rad;
		r_msgJointsCurrent.position[5] = r_executeData[5]*deg2rad;
		r_msgJointsCurrent.position[6] = r_executeData[6]*deg2rad;


/*		int Position[8], Velocity[8], Torque[8];
		GetMotorState(&g,Position,Velocity,Torque);

		ROS_INFO("...[%d][%d][%d][%d][%d][%d][%d]...\n", 		Position[0], \
															Position[1], \
															Position[2], \
															Position[3], \
															Position[4], \
															Position[5], \
															Position[6]);


		r_msgJointsCurrent.position[0] = Position[0]*PULSE2ANGLE*deg2rad;
		r_msgJointsCurrent.position[1] = Position[1]*PULSE2ANGLE*deg2rad;
		r_msgJointsCurrent.position[2] = Position[2]*PULSE2ANGLE*deg2rad;
		r_msgJointsCurrent.position[3] = Position[3]*PULSE2ANGLE*deg2rad;
		r_msgJointsCurrent.position[4] = Position[4]*PULSE2ANGLE*deg2rad;
		r_msgJointsCurrent.position[5] = Position[5]*PULSE2ANGLE*deg2rad;
		r_msgJointsCurrent.position[6] = r_executeData[6]*deg2rad;

		ROS_INFO("...[%f][%f][%f][%f][%f][%f][%f]...\n", 	r_msgJointsCurrent.position[0], \
															r_msgJointsCurrent.position[1], \
															r_msgJointsCurrent.position[2], \
															r_msgJointsCurrent.position[3], \
															r_msgJointsCurrent.position[4], \
															r_msgJointsCurrent.position[5], \
															r_msgJointsCurrent.position[6]);
*/

		pubJoints.publish(r_msgJointsCurrent);	// ROS communication works in Radian
	}
#endif

#ifdef __LEFT_ARM__
	//************************************************************************************
	// forward the current joints to RViz etc
	void enabot_control::L_CommunicationROS()
	{
		l_msgJointsCurrent.header.stamp = ros::Time::now();
		l_msgJointsCurrent.position[0] = l_executeData[0]*deg2rad;		// Robot SER communication works in degree
		l_msgJointsCurrent.position[1] = l_executeData[1]*deg2rad;
		l_msgJointsCurrent.position[2] = l_executeData[2]*deg2rad;
		l_msgJointsCurrent.position[3] = l_executeData[3]*deg2rad;
		l_msgJointsCurrent.position[4] = l_executeData[4]*deg2rad;
		l_msgJointsCurrent.position[5] = l_executeData[5]*deg2rad;
		l_msgJointsCurrent.position[6] = l_executeData[6]*deg2rad;

		pubJoints.publish(l_msgJointsCurrent);	// ROS communication works in Radian

	}
#endif

}

