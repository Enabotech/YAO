#include <galil_dmc_4060.h>
#include <string>

//#define POS_TRACK_MODE
#define CONTOUR_MODE

int CurPos[8], Delta[8];


vector<string> strSplit(string s, const char * split)
{
    vector<string> result;
    const int sLen = s.length();
    char *cs = new char[sLen + 1];
    strcpy(cs, s.data());
    char *p;
 
    p = strtok(cs, split);
    while (p)
    {
        //printf("%s\n", p);
        string tmp(p);
        result.push_back(tmp);
        p = strtok(NULL, split);
    }
    return result;
}


int MotorControllerInit(GCon *g)
{
	char buf[G_SMALL_BUFFER/2]; //traffic buffer
	//char *buf = new char[G_SMALL_BUFFER]; //traffic buffer

	x_e(GVersion(buf, sizeof(buf))); //library version
	cout << "Library versions: " << buf << '\n';

	char ipaddr[] = "192.168.0.66";
	char macaddr[] = "00:50:4C:20:42:A0";
	x_e(GAssign(ipaddr, macaddr)); //assign an ip address to a known MAC

	x_e(GAddresses(buf, sizeof(buf))); //list available addresses
	cout << "Available addresses:\n";
	if (strlen(buf) != 0)
		cout << buf << "\n\n";
	else
		cout << "none\n\n";

	cout << "Connecting to hardware\n";
	//Basic connections
	char cmd[] = "192.168.0.66 -d -ALL";
	x_e(GOpen(cmd, g)); //connect and assign a value to g. 
	x_e(GInfo(*g, buf, sizeof(buf))); //grab connection string
	cout << buf << '\n';

	//x_e(GCmd(*g, "ER -1, -1, -1, -1, -1, -1, -1, -1"));
	x_e(GCmd(*g, "ST"));
	x_e(GCmd(*g, "MT -2, -2, -2, -2, -2, -2, -2, -2"));
	x_e(GCmd(*g, "CE  2,  2,  2,  2,  2,  2,  2,  2"));

	x_e(GCmd(*g, "DP  0,  0,  0,  0,  0,  0,  0,  0")); //The DP command sets the commanded reference position for axes configured as steppers
	x_e(GCmd(*g, "DE  0,  0,  0,  0,  0,  0,  0,  0")); //When using stepper motors, the DE command defines the main encoder position


#if POS_TRACK_MODE
	x_e(GCmd(*g, "PT  1,  1,  1,  1,  1,  1,  1,  1")); //position tracking mode

	//Positon tracking mode setting
	x_e(GCmd(*g, "DM position[7], velocity[7], torque[7]"));
	x_e(GCmd(*g, "SP 200000, 200000, 200000, 200000, 200000, 200000, 200000, 200000")); //set up speed
	x_e(GCmd(*g, "AC 500000, 500000, 500000, 500000, 500000, 500000, 500000, 500000")); //acceleration
	x_e(GCmd(*g, "DC 500000, 500000, 500000, 500000, 500000, 500000, 500000, 500000")); //deceleration
#elif defined CONTOUR_MODE
	x_e(GCmd(*g, "TM  1000"));
	x_e(GCmd(*g, "CM  ABCDEF"));
	x_e(GCmd(*g, "DT  7"));
	//x_e(GCmd(*g, "DM  delta[8], curpos[8], tarpos[8]"));
#endif

	x_e(GCmd(*g, "SH"));

	return G_NO_ERROR;
}


int x_gmotioncomplete(GCon *g, int Pulse)
{
	cout << "\n************************************************************************\n";
	cout << "Example GMotionComplete() usage\n";
	cout << "************************************************************************\n";
	
	char buf[G_SMALL_BUFFER/2]; //traffic buffer
	//char* buf = new char[G_SMALL_BUFFER]; //traffic buffer
	char* trimmed; //trimmed string pointer

	std::string strCmd = "PA " + std::to_string(Pulse);
	const char *p = strCmd.data();
	cout << "motor cmd: " << strCmd << "... pulse number: " << Pulse << '\n';

	x_e(GCmd(*g, "ST")); //stop all motion and programs

	//-------------------------------------------------------------------------
	// Independent motion
	x_e(GCmdT(*g, "RP", buf, sizeof(buf), &trimmed));
	cout << "\nPosition: " << trimmed << '\n';
	x_e(GCmd(*g, "SP 200000")); //set up speed
	x_e(GCmd(*g, "AC 500000")); //acceleration
	x_e(GCmd(*g, "DC 500000")); //deceleration
	//x_e(GCmd(*g, "PR 500000")); //Postion Relative.
	x_e(GCmd(*g, p)); //Postion Relative.
	x_e(GCmd(*g, "SH A")); //Servo Here
	cout << "Beginning independent motion... ";
	x_e(GCmd(*g, "BG A")); //Begin motion
	x_e(GMotionComplete(*g, "A")); //Block until motion is complete on axis A
	cout << "Motion Complete on A\n";
	x_e(GCmdT(*g, "RP", buf, sizeof(buf), &trimmed));
	cout << "Refer Position: " << trimmed << '\n';;
	x_e(GCmdT(*g, "TP", buf, sizeof(buf), &trimmed));
	cout << "Real Position: " << trimmed << '\n';;
/*
	//-------------------------------------------------------------------------
	// Vector motion
	x_e(GCmd(*g, "DP 0")); //define position zero on A
	x_e(GCmdT(*g, "RP", buf, sizeof(buf), &trimmed));
	cout << "\nPosition: " << trimmed << '\n';;
	x_e(GCmd(*g, "VS 200000"));  //set up vector speed, S plane
	x_e(GCmd(*g, "VA 200000")); //vector Acceleration
	x_e(GCmd(*g, "VD 200000")); //vector deceleration
	x_e(GCmd(*g, "VM AN")); //invoke vector mode, use virtual axis for 1-axis controllers
	x_e(GCmd(*g, "VP -100000, -100000")); //buffer Vector Position
	x_e(GCmd(*g, "VP -1200000,0")); //buffer Vector Position
	x_e(GCmd(*g, "VE")); //indicate Vector End
	cout << "Beginning vector motion... ";
	x_e(GCmd(*g, "BG S")); //begin S plane
	x_e(GMotionComplete(*g, "S")); //Block until motion is complete on vector plane S
	cout << "Motion Complete on vector plane S\n";
	x_e(GCmdT(*g, "RP", buf, sizeof(buf), &trimmed));
	cout << "Position: " << trimmed << '\n';;
*/
	//delete [] buf;

	return G_NO_ERROR;
}


int PosTrack(GCon *g, int PulseA, int PulseB, int PulseC, int PulseD, int PulseE, int PulseF, int PulseG)
{
	cout << "\n************************************************************************\n";
	cout << "Example PosTrack() usage\n";
	cout << "************************************************************************\n";

	std::string strCmd = "PA " + 	std::to_string(PulseA) + "," + \
									std::to_string(PulseB) + "," + \
									std::to_string(PulseC) + "," + \
									std::to_string(PulseD) + "," + \
									std::to_string(PulseE) + "," + \
									std::to_string(PulseF) + "," + \
									std::to_string(PulseG);
	const char *p = strCmd.data();
	cout << "motor cmd: " << strCmd << '\n';
	x_e(GCmd(*g, p));

	return G_NO_ERROR;
}


int ContourMotion(GCon *g, int TarPos[])
{
	cout << "\n************************************************************************\n";
	cout << "Example ContourMotion() usage\n";
	cout << "************************************************************************\n";

	for(int i=0; i<8; i++)
	{
		Delta[i] = TarPos[i] - CurPos[i];
		CurPos[i] = TarPos[i];
	}

	std::string strCmd = "CD " + std::to_string(Delta[0]) + "," + \
								 std::to_string(Delta[1]) + "," + \
								 std::to_string(Delta[2]) + "," + \
								 std::to_string(Delta[3]) + "," + \
								 std::to_string(Delta[4]) + "," + \
								 std::to_string(Delta[5]) + "," + \
								 std::to_string(Delta[6]);

	const char *p = strCmd.data();
	cout << "motor cmd: " << strCmd << '\n';
	x_e(GCmd(*g, p));

	return G_NO_ERROR;
}


int MotorTest(GCon *g, float TarPos[])
{
	//x_e(x_gread_gwrite(g)); //call examples for GRead() and GWrite().		
	//x_e(x_gcommand(g)); //call examples for GCommand().
	//x_e(x_programs(g)); //call examples for GProgramDownload() and GProgramUpload().
	//x_e(x_arrays(g)); //call examples for GArrayDownload() and GArrayUpload().
	//x_e(x_grecord(g)); //call examples for GRecord(). WARNING, this call will attempt to move motors.
	//x_e(x_gmessage(g)); //call examples for GMessage().
	//x_e(x_ginterrupt(g)); //call examples for GInterrupt().  WARNING, this call will attempt to move motors.
	//x_e(x_gmotioncomplete(g, Pulse)); //call examples for GMotionComplete. WARNING, this call will attempt to move motors.
	//x_e(x_nonblocking(g)); //call examples for using GRecord(), GMessage(), and GInterrupt() in a non-blocking mode.
	int TargetPulse[8];

	for(int i = 0; i < 8; i++)
	{
		TargetPulse[i] = (int) TarPos[i]*ANGLE2PULSE;
	}


	//PosTrack(g, PulseA, PulseB, PulseC, PulseD, PulseE, PulseF, PulseG);
	ContourMotion(g, TargetPulse);

	return G_NO_ERROR;
}


int GetMotorState(GCon *g, int Position[], int Velocity[], int Torque[])
{
	cout << "\n************************************************************************\n";
	cout << "int GetMotorState(GCon *g)\n";
	cout << "************************************************************************\n";
	
	char buf[G_SMALL_BUFFER/2];
	char* trimmed;

	x_e(GCmdT(*g, "RP", buf, sizeof(buf), &trimmed));
	cout << "Reference Position: " << trimmed << '\n';
	x_e(GCmdT(*g, "TP", buf, sizeof(buf), &trimmed));
	cout << "Real Position: " << trimmed << '\n';;

	//int result[8];
	vector<string> str = strSplit(trimmed, ", ");
	int i = 0;
	for(auto j : str)
	{
		Position[i] = stoi(j,0,10);
		//cout << str[i] << "..." << '\n';
		cout << "j: " << j << "..." << "p: " << Position[i] << "@@@";
		i++;
	}

	cout << '\n';

	return 0;
}

