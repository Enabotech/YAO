#include <enabot_comm.h>

RobComm::RobComm() {
}

RobComm::~RobComm() {
}

#ifdef __RIGHT_ARM__
//***************************************************************************
void RobComm::SetRightJoints(float * j)
{

    int i;
    for(i = 0; i < MAX_JOINT_NUM; i++)
    {
	Rx_buf_right[i] = j[i];
	//ROS_INFO("I sent [%.2lf]", Rx_buf_right[i]);
    }
}
#endif


#ifdef __LEFT_ARM__
//***************************************************************************
void RobComm::SetLeftJoints(float * j)
{

    int i;
    for(i = 0; i < MAX_JOINT_NUM; i++)
    {
	Rx_buf_left[i] = j[i];
	//ROS_INFO("I sent [%.2lf]", Rx_buf_left[i]);
    }	
}
#endif


//***************************************************************************
void RobComm::GetJoints(float * j)
{


}
