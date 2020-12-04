/*! \file gclib_record.h
*  Defines a union for data records.
*  Each supported controller has a struct member in the union with named record types.
*  Offsets into the data record can also be used by referencing the member `byte_array`.
*/

#ifndef I_210405D9_D9EF_484F_8258_BB29A1BBA217
#define I_210405D9_D9EF_484F_8258_BB29A1BBA217


//typedefs to keep the layout of the structs clean and matching the Galil user manual docs
typedef unsigned char UB; //unsigned byte
typedef unsigned short UW; //unsigned word
typedef short SW; //signed word
typedef int SL; //signed long
typedef unsigned int UL; //unsigned long


#if defined(_MSC_VER) || defined(__GNUC__) || defined(__BORLANDC__)
#define PACKOK
#endif


#ifdef PACKOK
#pragma pack(1)
#else
#error "Need to set structure packing for compiler"
#endif


#define GALILDATARECORDMAXLENGTH 512 //!< Max size for any Galil data record, equal to dual port ram size of PCI.

//! Data record struct for DMC-4000 controllers, including 4000, 4200, 4103, and 500x0.
struct GDataRecord4000
{

	/*Offset   type name        description*/

	/*00*/	    UB	header_0; //!<1st Byte of Header.
	/*01*/	    UB	header_1; //!<2nd Byte of Header.
	/*02*/	    UB	header_2; //!<3rd Byte of Header.
	/*03*/	    UB	header_3; //!<4th Byte of Header.

	/*04-05*/  	UW	sample_number; //!<sample number.

	/*06*/	    UB	input_bank_0; //!<general input bank 0 (inputs 1-8).
	/*07*/	    UB	input_bank_1; //!<general input bank 1 (inputs 9-16).
	/*08*/	    UB	input_bank_2; //!<general input bank 2 (inputs 17-24).
	/*09*/	    UB	input_bank_3; //!<general input bank 3 (inputs 25-32).
	/*10*/    	UB	input_bank_4; //!<general input bank 4 (inputs 33-40).
	/*11*/	    UB	input_bank_5; //!<general input bank 5 (inputs 41-48).
	/*12*/	    UB	input_bank_6; //!<general input bank 6 (inputs 49-56).
	/*13*/   	UB	input_bank_7; //!<general input bank 7 (inputs 57-64).
	/*14*/   	UB	input_bank_8; //!<general input bank 8 (inputs 65-72).
	/*15*/	    UB	input_bank_9; //!<general input bank 9 (inputs 73-80).

	/*16*/    	UB	output_bank_0; //!<general output bank 0 (outputs 1-8).
	/*17*/	    UB	output_bank_1; //!<general output bank 1 (outputs 9-16).
	/*18*/   	UB	output_bank_2; //!<general output bank 2 (outputs 17-24).
	/*19*/	    UB	output_bank_3; //!<general output bank 3 (outputs 25-32).
	/*20*/   	UB	output_bank_4; //!<general output bank 4 (outputs 33-40).
	/*21*/	    UB	output_bank_5; //!<general output bank 5 (outputs 41-48).
	/*22*/	    UB	output_bank_6; //!<general output bank 6 (outputs 49-56).
	/*23*/	    UB	output_bank_7; //!<general output bank 7 (outputs 57-64).
	/*24*/  	UB	output_bank_8; //!<general output bank 8 (outputs 65-72).
	/*25*/  	UB	output_bank_9; //!<general output bank 9 (outputs 73-80).

	/*26-27*/	SW  reserved_0; //!<Reserved.
	/*28-29*/	SW 	reserved_2; //!<Reserved.
	/*30-31*/	SW 	reserved_4; //!<Reserved.
	/*32-33*/	SW	reserved_6; //!<Reserved.
	/*34-35*/	SW	reserved_8; //!<Reserved.
	/*36-37*/	SW	reserved_10; //!<Reserved.
	/*38-39*/	SW	reserved_12; //!<Reserved.
	/*40-41*/	SW	reserved_14; //!<Reserved.

	/*42*/	    UB	ethernet_status_a; //!<Ethernet Handle A Status.
	/*43*/   	UB	ethernet_status_b; //!<Ethernet Handle B Status.
	/*44*/	    UB	ethernet_status_c; //!<Ethernet Handle C Status.
	/*45*/   	UB	ethernet_status_d; //!<Ethernet Handle D Status.
	/*46*/  	UB	ethernet_status_e; //!<Ethernet Handle E Status.
	/*47*/	    UB	ethernet_status_f; //!<Ethernet Handle F Status.
	/*48*/  	UB	ethernet_status_g; //!<Ethernet Handle G Status.
	/*49*/  	UB	ethernet_status_h; //!<Ethernet Handle H Status.

	/*50*/	    UB	error_code; //!<error code.
	/*51*/  	UB	thread_status; //!<thread status
	/*52-55*/	UL	amplifier_status; //!<Amplifier Status.

	/*56-59*/	UL	contour_segment_count; //!<Segment Count for Contour Mode.
	/*60-61*/	UW	contour_buffer_available; //!<Buffer space remaining, Contour Mode.

	/*62-63*/	UW	s_plane_segment_count; //!<segment count of coordinated move for S plane.
	/*64-65*/	UW	s_plane_move_status; //!<coordinated move status for S plane.
	/*66-69*/	SL	s_distance; //!<distance traveled in coordinated move for S plane.
	/*70-71*/	UW	s_plane_buffer_available; //!<Buffer space remaining, S Plane.

	/*72-73*/	UW	t_plane_segment_count; //!<segment count of coordinated move for T plane.
	/*74-75*/	UW	t_plane_move_status; //!<Coordinated move status for T plane.
	/*76-79*/	SL	t_distance; //!<distance traveled in coordinated move for T plane.
	/*80-81*/	UW	t_plane_buffer_available; //!<Buffer space remaining, T Plane.

	/*82-83*/	UW	axis_a_status; //!<A axis status.
	/*84*/	    UB	axis_a_switches; //!<A axis switches.
	/*85*/	    UB	axis_a_stop_code; //!<A axis stop code.
	/*86-89*/	SL	axis_a_reference_position; //!<A axis reference position.
	/*90-93*/	SL	axis_a_motor_position; //!<A axis motor position.
	/*94-97*/	SL	axis_a_position_error; //!<A axis position error.
	/*98-101*/	SL	axis_a_aux_position; //!<A axis auxiliary position.
	/*102-105*/	SL	axis_a_velocity; //!<A axis velocity.
	/*106-109*/	SL 	axis_a_torque; //!<A axis torque.
	/*110-111*/	UW  axis_a_analog_in; //!<A axis analog input.
	/*112*/	    UB	axis_a_halls; //!<A Hall Input Status.
	/*113*/  	UB	axis_a_reserved; //!<Reserved.
	/*114-117*/	SL	axis_a_variable; //!<A User-defined variable (ZA).

	/*118-119*/	UW	axis_b_status; //!<B axis status.
	/*120*/	    UB	axis_b_switches; //!<B axis switches.
	/*121*/	    UB	axis_b_stop_code; //!<B axis stop code.
	/*122-125*/	SL	axis_b_reference_position; //!<B axis reference position.
	/*126-129*/	SL	axis_b_motor_position; //!<B axis motor position.
	/*130-133*/	SL	axis_b_position_error; //!<B axis position error.
	/*134-137*/	SL	axis_b_aux_position; //!<B axis auxiliary position.
	/*138-141*/	SL	axis_b_velocity; //!<B axis velocity.
	/*142-145*/	SL	axis_b_torque; //!<B axis torque.
	/*146-147*/	UW  axis_b_analog_in; //!<B axis analog input.
	/*148*/   	UB	axis_b_halls; //!<B Hall Input Status.
	/*149*/	    UB	axis_b_reserved; //!<Reserved.
	/*150-153*/	SL	axis_b_variable; //!<B User-defined variable (ZA).

	/*154-155*/	UW	axis_c_status; //!<C axis status.
	/*156*/  	UB	axis_c_switches; //!<C axis switches.
	/*157*/ 	UB	axis_c_stop_code; //!<C axis stop code.
	/*158-161*/	SL	axis_c_reference_position; //!<C axis reference position.
	/*162-165*/	SL	axis_c_motor_position; //!<C axis motor position.
	/*166-169*/	SL	axis_c_position_error; //!<C axis position error.
	/*170-173*/	SL	axis_c_aux_position; //!<C axis auxiliary position.
	/*174-177*/	SL	axis_c_velocity; //!<C axis velocity.
	/*178-181*/	SL	axis_c_torque; //!<C axis torque.
	/*182-183*/	UW 	axis_c_analog_in; //!<C axis analog input.
	/*184*/	    UB	axis_c_halls; //!<C Hall Input Status.
	/*185*/	    UB	axis_c_reserved; //!<Reserved.
	/*186-189*/	SL	axis_c_variable; //!<C User-defined variable (ZA).

	/*190-191*/	UW	axis_d_status; //!<D axis status.
	/*192*/	    UB	axis_d_switches; //!<D axis switches.
	/*193*/  	UB	axis_d_stop_code; //!<D axis stop code.
	/*194-197*/	SL	axis_d_reference_position; //!<D axis reference position.
	/*198-201*/	SL	axis_d_motor_position; //!<D axis motor position.
	/*202-205*/	SL	axis_d_position_error; //!<D axis position error.
	/*206-209*/	SL	axis_d_aux_position; //!<D axis auxiliary position.
	/*210-213*/	SL	axis_d_velocity; //!<D axis velocity.
	/*214-217*/	SL	axis_d_torque; //!<D axis torque.
	/*218-219*/ UW  axis_d_analog_in; //!<D axis analog input.
	/*220*/  	UB	axis_d_halls; //!<D Hall Input Status.
	/*221*/ 	UB	axis_d_reserved; //!<Reserved.
	/*222-225*/	SL	axis_d_variable; //!<D User-defined variable (ZA).

	/*226-227*/	UW	axis_e_status; //!<E axis status.
	/*228*/	    UB	axis_e_switches; //!<E axis switches.
	/*229*/	    UB	axis_e_stop_code; //!<E axis stop code.
	/*230-233*/	SL	axis_e_reference_position; //!<E axis reference position.
	/*234-237*/	SL	axis_e_motor_position; //!<E axis motor position.
	/*238-241*/	SL	axis_e_position_error; //!<E axis position error.
	/*242-245*/	SL	axis_e_aux_position; //!<E axis auxiliary position.
	/*246-249*/	SL	axis_e_velocity; //!<E axis velocity.
	/*250-253*/	SL	axis_e_torque; //!<E axis torque.
	/*254-255*/	UW  axis_e_analog_in; //!<E axis analog input.
	/*256*/  	UB	axis_e_halls; //!<E Hall Input Status.
	/*257*/	    UB	axis_e_reserved; //!<Reserved.
	/*258-261*/	SL	axis_e_variable; //!<E User-defined variable (ZA).

	/*262-263*/	UW	axis_f_status; //!<F axis status.
	/*264*/	    UB	axis_f_switches; //!<F axis switches.
	/*265*/	    UB	axis_f_stop_code; //!<F axis stop code.
	/*266-269*/	SL	axis_f_reference_position; //!<F axis reference position.
	/*270-273*/	SL	axis_f_motor_position; //!<F axis motor position.
	/*274-277*/	SL	axis_f_position_error; //!<F axis position error.
	/*278-281*/	SL	axis_f_aux_position; //!<F axis auxiliary position.
	/*282-285*/	SL	axis_f_velocity; //!<F axis velocity.
	/*286-289*/	SL	axis_f_torque; //!<F axis torque.
	/*290-291*/	UW	axis_f_analog_in; //!<F axis analog input.
	/*292*/	    UB	axis_f_halls; //!<F Hall Input Status.
	/*293*/	    UB	axis_f_reserved; //!<Reserved.
	/*294-297*/	SL	axis_f_variable; //!<F User-defined variable (ZA).

	/*298-299*/	UW	axis_g_status; //!<G axis status.
	/*300*/  	UB	axis_g_switches; //!<G axis switches.
	/*301*/ 	UB	axis_g_stop_code; //!<G axis stop code.
	/*302-305*/	SL	axis_g_reference_position; //!<G axis reference position.
	/*306-309*/	SL	axis_g_motor_position; //!<G axis motor position.
	/*310-313*/	SL	axis_g_position_error; //!<G axis position error.
	/*314-317*/	SL	axis_g_aux_position; //!<G axis auxiliary position.
	/*318-321*/	SL	axis_g_velocity; //!<G axis velocity.
	/*322-325*/	SL	axis_g_torque; //!<G axis torque.
	/*326-327*/ UW  axis_g_analog_in; //!<G axis analog input.
	/*328*/	    UB	axis_g_halls; //!<G Hall Input Status.
	/*329*/	    UB	axis_g_reserved; //!<Reserved.
	/*330-333*/	SL	axis_g_variable; //!<G User-defined variable (ZA).

	/*334-335*/	UW	axis_h_status; //!<H axis status.
	/*336*/  	UB	axis_h_switches; //!<H axis switches.
	/*337*/	    UB	axis_h_stop_code; //!<H axis stop code.
	/*338-341*/	SL	axis_h_reference_position; //!<H axis reference position.
	/*342-345*/	SL	axis_h_motor_position; //!<H axis motor position.
	/*346-349*/	SL	axis_h_position_error; //!<H axis position error.
	/*350-353*/	SL	axis_h_aux_position; //!<H axis auxiliary position.
	/*354-357*/	SL	axis_h_velocity; //!<H axis velocity.
	/*358-361*/	SL	axis_h_torque; //!<H axis torque.
	/*362-363*/	UW  axis_h_analog_in; //!<H axis analog input.
	/*364*/	    UB	axis_h_halls; //!<H Hall Input Status.
	/*365*/  	UB	axis_h_reserved; //!<Reserved.
	/*366-369*/	SL	axis_h_variable; //!<H User-defined variable (ZA).
}; //DataRecord4000

//! Data record struct for DMC-52000 controller. Same as DMC-4000, with bank indicator added at byte 40.
struct GDataRecord52000
{

	/*Offset   type name        description*/

	/*00*/	    UB	header_0; //!<1st Byte of Header.
	/*01*/	    UB	header_1; //!<2nd Byte of Header.
	/*02*/	    UB	header_2; //!<3rd Byte of Header.
	/*03*/	    UB	header_3; //!<4th Byte of Header.

	/*04-05*/  	UW	sample_number; //!<sample number.

	/*06*/	    UB	input_bank_0; //!<general input bank 0 (inputs 1-8).
	/*07*/	    UB	input_bank_1; //!<general input bank 1 (inputs 9-16).
	/*08*/	    UB	input_bank_2; //!<general input bank 2 (inputs 17-24).
	/*09*/	    UB	input_bank_3; //!<general input bank 3 (inputs 25-32).
	/*10*/    	UB	input_bank_4; //!<general input bank 4 (inputs 33-40).
	/*11*/	    UB	input_bank_5; //!<general input bank 5 (inputs 41-48).
	/*12*/	    UB	input_bank_6; //!<general input bank 6 (inputs 49-56).
	/*13*/   	UB	input_bank_7; //!<general input bank 7 (inputs 57-64).
	/*14*/   	UB	input_bank_8; //!<general input bank 8 (inputs 65-72).
	/*15*/	    UB	input_bank_9; //!<general input bank 9 (inputs 73-80).

	/*16*/    	UB	output_bank_0; //!<general output bank 0 (outputs 1-8).
	/*17*/	    UB	output_bank_1; //!<general output bank 1 (outputs 9-16).
	/*18*/   	UB	output_bank_2; //!<general output bank 2 (outputs 17-24).
	/*19*/	    UB	output_bank_3; //!<general output bank 3 (outputs 25-32).
	/*20*/   	UB	output_bank_4; //!<general output bank 4 (outputs 33-40).
	/*21*/	    UB	output_bank_5; //!<general output bank 5 (outputs 41-48).
	/*22*/	    UB	output_bank_6; //!<general output bank 6 (outputs 49-56).
	/*23*/	    UB	output_bank_7; //!<general output bank 7 (outputs 57-64).
	/*24*/  	UB	output_bank_8; //!<general output bank 8 (outputs 65-72).
	/*25*/  	UB	output_bank_9; //!<general output bank 9 (outputs 73-80).

	/*26-27*/	SW  reserved_0; //!<Reserved.
	/*28-29*/	SW 	reserved_2; //!<Reserved.
	/*30-31*/	SW 	reserved_4; //!<Reserved.
	/*32-33*/	SW	reserved_6; //!<Reserved.
	/*34-35*/	SW	reserved_8; //!<Reserved.
	/*36-37*/	SW	reserved_10; //!<Reserved.
	/*38-39*/	SW	reserved_12; //!<Reserved.
	/*40*/      UB  ethercat_bank; //!< EtherCAT Bank Indicator.
	/*41*/   	UB	reserved_14; //!<Reserved.

	/*42*/	    UB	ethernet_status_a; //!<Ethernet Handle A Status.
	/*43*/   	UB	ethernet_status_b; //!<Ethernet Handle B Status.
	/*44*/	    UB	ethernet_status_c; //!<Ethernet Handle C Status.
	/*45*/   	UB	ethernet_status_d; //!<Ethernet Handle D Status.
	/*46*/  	UB	ethernet_status_e; //!<Ethernet Handle E Status.
	/*47*/	    UB	ethernet_status_f; //!<Ethernet Handle F Status.
	/*48*/  	UB	ethernet_status_g; //!<Ethernet Handle G Status.
	/*49*/  	UB	ethernet_status_h; //!<Ethernet Handle H Status.

	/*50*/	    UB	error_code; //!<error code.
	/*51*/  	UB	thread_status; //!<thread status
	/*52-55*/	UL	amplifier_status; //!<Amplifier Status.

	/*56-59*/	UL	contour_segment_count; //!<Segment Count for Contour Mode.
	/*60-61*/	UW	contour_buffer_available; //!<Buffer space remaining, Contour Mode.

	/*62-63*/	UW	s_plane_segment_count; //!<segment count of coordinated move for S plane.
	/*64-65*/	UW	s_plane_move_status; //!<coordinated move status for S plane.
	/*66-69*/	SL	s_distance; //!<distance traveled in coordinated move for S plane.
	/*70-71*/	UW	s_plane_buffer_available; //!<Buffer space remaining, S Plane.

	/*72-73*/	UW	t_plane_segment_count; //!<segment count of coordinated move for T plane.
	/*74-75*/	UW	t_plane_move_status; //!<Coordinated move status for T plane.
	/*76-79*/	SL	t_distance; //!<distance traveled in coordinated move for T plane.
	/*80-81*/	UW	t_plane_buffer_available; //!<Buffer space remaining, T Plane.

	/*82-83*/	UW	axis_a_status; //!<A axis status.
	/*84*/	    UB	axis_a_switches; //!<A axis switches.
	/*85*/	    UB	axis_a_stop_code; //!<A axis stop code.
	/*86-89*/	SL	axis_a_reference_position; //!<A axis reference position.
	/*90-93*/	SL	axis_a_motor_position; //!<A axis motor position.
	/*94-97*/	SL	axis_a_position_error; //!<A axis position error.
	/*98-101*/	SL	axis_a_aux_position; //!<A axis auxiliary position.
	/*102-105*/	SL	axis_a_velocity; //!<A axis velocity.
	/*106-109*/	SL 	axis_a_torque; //!<A axis torque.
	/*110-111*/	UW  axis_a_analog_in; //!<A axis analog input.
	/*112*/	    UB	axis_a_halls; //!<A Hall Input Status.
	/*113*/  	UB	axis_a_reserved; //!<Reserved.
	/*114-117*/	SL	axis_a_variable; //!<A User-defined variable (ZA).

	/*118-119*/	UW	axis_b_status; //!<B axis status.
	/*120*/	    UB	axis_b_switches; //!<B axis switches.
	/*121*/	    UB	axis_b_stop_code; //!<B axis stop code.
	/*122-125*/	SL	axis_b_reference_position; //!<B axis reference position.
	/*126-129*/	SL	axis_b_motor_position; //!<B axis motor position.
	/*130-133*/	SL	axis_b_position_error; //!<B axis position error.
	/*134-137*/	SL	axis_b_aux_position; //!<B axis auxiliary position.
	/*138-141*/	SL	axis_b_velocity; //!<B axis velocity.
	/*142-145*/	SL	axis_b_torque; //!<B axis torque.
	/*146-147*/	UW  axis_b_analog_in; //!<B axis analog input.
	/*148*/   	UB	axis_b_halls; //!<B Hall Input Status.
	/*149*/	    UB	axis_b_reserved; //!<Reserved.
	/*150-153*/	SL	axis_b_variable; //!<B User-defined variable (ZA).

	/*154-155*/	UW	axis_c_status; //!<C axis status.
	/*156*/  	UB	axis_c_switches; //!<C axis switches.
	/*157*/ 	UB	axis_c_stop_code; //!<C axis stop code.
	/*158-161*/	SL	axis_c_reference_position; //!<C axis reference position.
	/*162-165*/	SL	axis_c_motor_position; //!<C axis motor position.
	/*166-169*/	SL	axis_c_position_error; //!<C axis position error.
	/*170-173*/	SL	axis_c_aux_position; //!<C axis auxiliary position.
	/*174-177*/	SL	axis_c_velocity; //!<C axis velocity.
	/*178-181*/	SL	axis_c_torque; //!<C axis torque.
	/*182-183*/	UW 	axis_c_analog_in; //!<C axis analog input.
	/*184*/	    UB	axis_c_halls; //!<C Hall Input Status.
	/*185*/	    UB	axis_c_reserved; //!<Reserved.
	/*186-189*/	SL	axis_c_variable; //!<C User-defined variable (ZA).

	/*190-191*/	UW	axis_d_status; //!<D axis status.
	/*192*/	    UB	axis_d_switches; //!<D axis switches.
	/*193*/  	UB	axis_d_stop_code; //!<D axis stop code.
	/*194-197*/	SL	axis_d_reference_position; //!<D axis reference position.
	/*198-201*/	SL	axis_d_motor_position; //!<D axis motor position.
	/*202-205*/	SL	axis_d_position_error; //!<D axis position error.
	/*206-209*/	SL	axis_d_aux_position; //!<D axis auxiliary position.
	/*210-213*/	SL	axis_d_velocity; //!<D axis velocity.
	/*214-217*/	SL	axis_d_torque; //!<D axis torque.
	/*218-219*/ UW  axis_d_analog_in; //!<D axis analog input.
	/*220*/  	UB	axis_d_halls; //!<D Hall Input Status.
	/*221*/ 	UB	axis_d_reserved; //!<Reserved.
	/*222-225*/	SL	axis_d_variable; //!<D User-defined variable (ZA).

	/*226-227*/	UW	axis_e_status; //!<E axis status.
	/*228*/	    UB	axis_e_switches; //!<E axis switches.
	/*229*/	    UB	axis_e_stop_code; //!<E axis stop code.
	/*230-233*/	SL	axis_e_reference_position; //!<E axis reference position.
	/*234-237*/	SL	axis_e_motor_position; //!<E axis motor position.
	/*238-241*/	SL	axis_e_position_error; //!<E axis position error.
	/*242-245*/	SL	axis_e_aux_position; //!<E axis auxiliary position.
	/*246-249*/	SL	axis_e_velocity; //!<E axis velocity.
	/*250-253*/	SL	axis_e_torque; //!<E axis torque.
	/*254-255*/	UW  axis_e_analog_in; //!<E axis analog input.
	/*256*/  	UB	axis_e_halls; //!<E Hall Input Status.
	/*257*/	    UB	axis_e_reserved; //!<Reserved.
	/*258-261*/	SL	axis_e_variable; //!<E User-defined variable (ZA).

	/*262-263*/	UW	axis_f_status; //!<F axis status.
	/*264*/	    UB	axis_f_switches; //!<F axis switches.
	/*265*/	    UB	axis_f_stop_code; //!<F axis stop code.
	/*266-269*/	SL	axis_f_reference_position; //!<F axis reference position.
	/*270-273*/	SL	axis_f_motor_position; //!<F axis motor position.
	/*274-277*/	SL	axis_f_position_error; //!<F axis position error.
	/*278-281*/	SL	axis_f_aux_position; //!<F axis auxiliary position.
	/*282-285*/	SL	axis_f_velocity; //!<F axis velocity.
	/*286-289*/	SL	axis_f_torque; //!<F axis torque.
	/*290-291*/	UW	axis_f_analog_in; //!<F axis analog input.
	/*292*/	    UB	axis_f_halls; //!<F Hall Input Status.
	/*293*/	    UB	axis_f_reserved; //!<Reserved.
	/*294-297*/	SL	axis_f_variable; //!<F User-defined variable (ZA).

	/*298-299*/	UW	axis_g_status; //!<G axis status.
	/*300*/  	UB	axis_g_switches; //!<G axis switches.
	/*301*/ 	UB	axis_g_stop_code; //!<G axis stop code.
	/*302-305*/	SL	axis_g_reference_position; //!<G axis reference position.
	/*306-309*/	SL	axis_g_motor_position; //!<G axis motor position.
	/*310-313*/	SL	axis_g_position_error; //!<G axis position error.
	/*314-317*/	SL	axis_g_aux_position; //!<G axis auxiliary position.
	/*318-321*/	SL	axis_g_velocity; //!<G axis velocity.
	/*322-325*/	SL	axis_g_torque; //!<G axis torque.
	/*326-327*/ UW  axis_g_analog_in; //!<G axis analog input.
	/*328*/	    UB	axis_g_halls; //!<G Hall Input Status.
	/*329*/	    UB	axis_g_reserved; //!<Reserved.
	/*330-333*/	SL	axis_g_variable; //!<G User-defined variable (ZA).

	/*334-335*/	UW	axis_h_status; //!<H axis status.
	/*336*/  	UB	axis_h_switches; //!<H axis switches.
	/*337*/	    UB	axis_h_stop_code; //!<H axis stop code.
	/*338-341*/	SL	axis_h_reference_position; //!<H axis reference position.
	/*342-345*/	SL	axis_h_motor_position; //!<H axis motor position.
	/*346-349*/	SL	axis_h_position_error; //!<H axis position error.
	/*350-353*/	SL	axis_h_aux_position; //!<H axis auxiliary position.
	/*354-357*/	SL	axis_h_velocity; //!<H axis velocity.
	/*358-361*/	SL	axis_h_torque; //!<H axis torque.
	/*362-363*/	UW  axis_h_analog_in; //!<H axis analog input.
	/*364*/	    UB	axis_h_halls; //!<H Hall Input Status.
	/*365*/  	UB	axis_h_reserved; //!<Reserved.
	/*366-369*/	SL	axis_h_variable; //!<H User-defined variable (ZA).
}; //DataRecord52000

//! Data record struct for DMC-1806 controller.
/*!
The 18x6 Data record is the same as 4000 except the following.
-# No header bytes. Firmware strips it in DR. Software removes it from QR.
-# No Ethernet status (bytes 42-49).
-# No amplfifier status (bytes 52-55).
-# No axis-specific hall input status.
*/
struct GDataRecord1806
{
	/*Offset   type name        description*/

	/*00-01*/  	UW	sample_number; //!<sample number.

	/*02*/	    UB	input_bank_0; //!<general input bank 0 (inputs 1-8).
	/*03*/	    UB	input_bank_1; //!<general input bank 1 (inputs 9-16).
	/*04*/	    UB	input_bank_2; //!<general input bank 2 (inputs 17-24).
	/*05*/	    UB	input_bank_3; //!<general input bank 3 (inputs 25-32).
	/*06*/    	UB	input_bank_4; //!<general input bank 4 (inputs 33-40).
	/*07*/	    UB	input_bank_5; //!<general input bank 5 (inputs 41-48).
	/*08*/	    UB	input_bank_6; //!<general input bank 6 (inputs 49-56).
	/*09*/   	UB	input_bank_7; //!<general input bank 7 (inputs 57-64).
	/*10*/   	UB	input_bank_8; //!<general input bank 8 (inputs 65-72).
	/*11*/	    UB	input_bank_9; //!<general input bank 9 (inputs 73-80).

	/*12*/    	UB	output_bank_0; //!<general output bank 0 (outputs 1-8).
	/*13*/	    UB	output_bank_1; //!<general output bank 1 (outputs 9-16).
	/*14*/   	UB	output_bank_2; //!<general output bank 2 (outputs 17-24).
	/*15*/	    UB	output_bank_3; //!<general output bank 3 (outputs 25-32).
	/*16*/   	UB	output_bank_4; //!<general output bank 4 (outputs 33-40).
	/*17*/	    UB	output_bank_5; //!<general output bank 5 (outputs 41-48).
	/*18*/	    UB	output_bank_6; //!<general output bank 6 (outputs 49-56).
	/*19*/	    UB	output_bank_7; //!<general output bank 7 (outputs 57-64).
	/*20*/  	UB	output_bank_8; //!<general output bank 8 (outputs 65-72).
	/*21*/  	UB	output_bank_9; //!<general output bank 9 (outputs 73-80).

	/*22-23*/	SW  reserved_0; //!<Reserved.
	/*24-25*/	SW 	reserved_2; //!<Reserved.
	/*26-27*/	SW 	reserved_4; //!<Reserved.
	/*28-29*/	SW	reserved_6; //!<Reserved.
	/*30-31*/	SW	reserved_8; //!<Reserved.
	/*32-33*/	SW	reserved_10; //!<Reserved.
	/*34-35*/	SW	reserved_12; //!<Reserved.
	/*36-37*/	SW	reserved_14; //!<Reserved.

	/*38*/	    UB	reserved_16; //!<Reserved.
	/*39*/   	UB	reserved_17; //!<Reserved.
	/*40*/	    UB	reserved_18; //!<Reserved.
	/*41*/   	UB	reserved_19; //!<Reserved.
	/*42*/  	UB	reserved_20; //!<Reserved.
	/*43*/	    UB	reserved_21; //!<Reserved.
	/*44*/  	UB	reserved_22; //!<Reserved.
	/*45*/  	UB	reserved_23; //!<Reserved.

	/*46*/	    UB	error_code; //!<error code.
	/*47*/  	UB	thread_status; //!<thread status.
	/*48-51*/	UL	reserved_24; //!<Reserved.

	/*52-55*/	UL	contour_segment_count; //!<Segment Count for Contour Mode.
	/*56-57*/	UW	contour_buffer_available; //!<Buffer space remaining, Contour Mode.

	/*58-59*/	UW	s_plane_segment_count; //!<segment count of coordinated move for S plane.
	/*60-61*/	UW	s_plane_move_status; //!<coordinated move status for S plane.
	/*62-65*/	SL	s_distance; //!<distance traveled in coordinated move for S plane.
	/*66-67*/	UW	s_plane_buffer_available; //!<Buffer space remaining, S Plane.

	/*68-69*/	UW	t_plane_segment_count; //!<segment count of coordinated move for T plane.
	/*70-71*/	UW	t_plane_move_status; //!<Coordinated move status for T plane.
	/*72-75*/	SL	t_distance; //!<distance traveled in coordinated move for T plane.
	/*76-77*/	UW	t_plane_buffer_available; //!<Buffer space remaining, T Plane.

	/*78-79*/	UW	axis_a_status; //!<A axis status.
	/*80*/	    UB	axis_a_switches; //!<A axis switches.
	/*81*/	    UB	axis_a_stop_code; //!<A axis stop code.
	/*82-85*/	SL	axis_a_reference_position; //!<A axis reference position.
	/*86-89*/	SL	axis_a_motor_position; //!<A axis motor position.
	/*90-93*/	SL	axis_a_position_error; //!<A axis position error.
	/*94-97*/	SL	axis_a_aux_position; //!<A axis auxiliary position.
	/*98-101*/	SL	axis_a_velocity; //!<A axis velocity.
	/*102-105*/	SL 	axis_a_torque; //!<A axis torque.
	/*106-107*/	UW  axis_a_analog_in; //!<A axis analog input.
	/*108*/	    UB	axis_a_reserved_0; //!<Reserved.
	/*109*/  	UB	axis_a_reserved_1; //!<Reserved.
	/*110-113*/	SL	axis_a_variable; //!<A User-defined variable (ZA).

	/*114-115*/	UW	axis_b_status; //!<B axis status.
	/*116*/	    UB	axis_b_switches; //!<B axis switches.
	/*117*/	    UB	axis_b_stop_code; //!<B axis stop code.
	/*118-121*/	SL	axis_b_reference_position; //!<B axis reference position.
	/*122-125*/	SL	axis_b_motor_position; //!<B axis motor position.
	/*126-129*/	SL	axis_b_position_error; //!<B axis position error.
	/*130-133*/	SL	axis_b_aux_position; //!<B axis auxiliary position.
	/*134-137*/	SL	axis_b_velocity; //!<B axis velocity.
	/*138-141*/	SL	axis_b_torque; //!<B axis torque.
	/*142-143*/	UW  axis_b_analog_in; //!<B axis analog input.
	/*144*/   	UB	axis_b_reserved_0; //!<Reserved.
	/*145*/	    UB	axis_b_reserved_1; //!<Reserved.
	/*146-149*/	SL	axis_b_variable; //!<B User-defined variable (ZA).

	/*150-151*/	UW	axis_c_status; //!<C axis status.
	/*152*/  	UB	axis_c_switches; //!<C axis switches.
	/*153*/ 	UB	axis_c_stop_code; //!<C axis stop code.
	/*154-157*/	SL	axis_c_reference_position; //!<C axis reference position.
	/*158-161*/	SL	axis_c_motor_position; //!<C axis motor position.
	/*162-165*/	SL	axis_c_position_error; //!<C axis position error.
	/*166-169*/	SL	axis_c_aux_position; //!<C axis auxiliary position.
	/*170-173*/	SL	axis_c_velocity; //!<C axis velocity.
	/*174-177*/	SL	axis_c_torque; //!<C axis torque.
	/*178-179*/	UW 	axis_c_analog_in; //!<C axis analog input.
	/*180*/	    UB	axis_c_reserved_0; //!<Reserved.
	/*181*/	    UB	axis_c_reserved_1; //!<Reserved.
	/*182-185*/	SL	axis_c_variable; //!<C User-defined variable (ZA).

	/*186-187*/	UW	axis_d_status; //!<D axis status.
	/*188*/	    UB	axis_d_switches; //!<D axis switches.
	/*189*/  	UB	axis_d_stop_code; //!<D axis stop code.
	/*190-193*/	SL	axis_d_reference_position; //!<D axis reference position.
	/*194-197*/	SL	axis_d_motor_position; //!<D axis motor position.
	/*198-201*/	SL	axis_d_position_error; //!<D axis position error.
	/*202-205*/	SL	axis_d_aux_position; //!<D axis auxiliary position.
	/*206-209*/	SL	axis_d_velocity; //!<D axis velocity.
	/*210-213*/	SL	axis_d_torque; //!<D axis torque.
	/*214-215*/ UW  axis_d_analog_in; //!<D axis analog input.
	/*216*/  	UB	axis_d_reserved_0; //!<Reserved.
	/*217*/ 	UB	axis_d_reserved_1; //!<Reserved.
	/*218-221*/	SL	axis_d_variable; //!<D User-defined variable (ZA).

	/*222-223*/	UW	axis_e_status; //!<E axis status.
	/*224*/	    UB	axis_e_switches; //!<E axis switches.
	/*225*/	    UB	axis_e_stop_code; //!<E axis stop code.
	/*226-229*/	SL	axis_e_reference_position; //!<E axis reference position.
	/*230-233*/	SL	axis_e_motor_position; //!<E axis motor position.
	/*234-237*/	SL	axis_e_position_error; //!<E axis position error.
	/*238-241*/	SL	axis_e_aux_position; //!<E axis auxiliary position.
	/*242-245*/	SL	axis_e_velocity; //!<E axis velocity.
	/*256-249*/	SL	axis_e_torque; //!<E axis torque.
	/*250-251*/	UW  axis_e_analog_in; //!<E axis analog input.
	/*252*/  	UB	axis_e_reserved_0; //!<Reserved.
	/*253*/	    UB	axis_e_reserved_1; //!<Reserved.
	/*254-257*/	SL	axis_e_variable; //!<E User-defined variable (ZA).

	/*258-259*/	UW	axis_f_status; //!<F axis status.
	/*260*/	    UB	axis_f_switches; //!<F axis switches.
	/*261*/	    UB	axis_f_stop_code; //!<F axis stop code.
	/*262-265*/	SL	axis_f_reference_position; //!<F axis reference position.
	/*266-269*/	SL	axis_f_motor_position; //!<F axis motor position.
	/*270-273*/	SL	axis_f_position_error; //!<F axis position error.
	/*274-277*/	SL	axis_f_aux_position; //!<F axis auxiliary position.
	/*278-281*/	SL	axis_f_velocity; //!<F axis velocity.
	/*282-285*/	SL	axis_f_torque; //!<F axis torque.
	/*286-287*/	UW	axis_f_analog_in; //!<F axis analog input.
	/*288*/	    UB	axis_f_reserved_0; //!<Reserved.
	/*289*/	    UB	axis_f_reserved_1; //!<Reserved.
	/*290-293*/	SL	axis_f_variable; //!<F User-defined variable (ZA).

	/*294-295*/	UW	axis_g_status; //!<G axis status.
	/*296*/  	UB	axis_g_switches; //!<G axis switches.
	/*297*/ 	UB	axis_g_stop_code; //!<G axis stop code.
	/*298-301*/	SL	axis_g_reference_position; //!<G axis reference position.
	/*302-305*/	SL	axis_g_motor_position; //!<G axis motor position.
	/*306-309*/	SL	axis_g_position_error; //!<G axis position error.
	/*310-313*/	SL	axis_g_aux_position; //!<G axis auxiliary position.
	/*314-317*/	SL	axis_g_velocity; //!<G axis velocity.
	/*318-321*/	SL	axis_g_torque; //!<G axis torque.
	/*322-323*/ UW  axis_g_analog_in; //!<G axis analog input.
	/*324*/	    UB	axis_g_reserved_0; //!<Reserved.
	/*325*/	    UB	axis_g_reserved_1; //!<Reserved.
	/*326-329*/	SL	axis_g_variable; //!<G User-defined variable (ZA).

	/*330-331*/	UW	axis_h_status; //!<H axis status.
	/*332*/  	UB	axis_h_switches; //!<H axis switches.
	/*333*/	    UB	axis_h_stop_code; //!<H axis stop code.
	/*334-337*/	SL	axis_h_reference_position; //!<H axis reference position.
	/*338-341*/	SL	axis_h_motor_position; //!<H axis motor position.
	/*342-345*/	SL	axis_h_position_error; //!<H axis position error.
	/*346-349*/	SL	axis_h_aux_position; //!<H axis auxiliary position.
	/*350-353*/	SL	axis_h_velocity; //!<H axis velocity.
	/*354-357*/	SL	axis_h_torque; //!<H axis torque.
	/*358-359*/	UW  axis_h_analog_in; //!<H axis analog input.
	/*360*/	    UB	axis_h_reserved_0; //!<Reserved.
	/*361*/  	UB	axis_h_reserved_1; //!<Reserved.
	/*362-365*/	SL	axis_h_variable; //!<H User-defined variable (ZA).
}; //DataRecord1806

//! Data record struct for DMC-2103 controllers.
struct GDataRecord2103
{

	/*Offset   type name        description*/

	/*00*/	    UB	header_0; //!<1st Byte of Header.
	/*01*/	    UB	header_1; //!<2nd Byte of Header.
	/*02*/	    UB	header_2; //!<3rd Byte of Header.
	/*03*/	    UB	header_3; //!<4th Byte of Header.

	/*04-05*/  	UW	sample_number; //!<sample number.

	/*06*/	    UB	input_bank_0; //!<general input bank 0 (inputs 1-8).
	/*07*/	    UB	input_bank_1; //!<general input bank 1 (inputs 9-16).
	/*08*/	    UB	input_bank_2; //!<general input bank 2 (inputs 17-24).
	/*09*/	    UB	input_bank_3; //!<general input bank 3 (inputs 25-32).
	/*10*/    	UB	input_bank_4; //!<general input bank 4 (inputs 33-40).
	/*11*/	    UB	input_bank_5; //!<general input bank 5 (inputs 41-48).
	/*12*/	    UB	input_bank_6; //!<general input bank 6 (inputs 49-56).
	/*13*/   	UB	input_bank_7; //!<general input bank 7 (inputs 57-64).
	/*14*/   	UB	input_bank_8; //!<general input bank 8 (inputs 65-72).
	/*15*/	    UB	input_bank_9; //!<general input bank 9 (inputs 73-80).

	/*16*/    	UB	output_bank_0; //!<general output bank 0 (outputs 1-8).
	/*17*/	    UB	output_bank_1; //!<general output bank 1 (outputs 9-16).
	/*18*/   	UB	output_bank_2; //!<general output bank 2 (outputs 17-24).
	/*19*/	    UB	output_bank_3; //!<general output bank 3 (outputs 25-32).
	/*20*/   	UB	output_bank_4; //!<general output bank 4 (outputs 33-40).
	/*21*/	    UB	output_bank_5; //!<general output bank 5 (outputs 41-48).
	/*22*/	    UB	output_bank_6; //!<general output bank 6 (outputs 49-56).
	/*23*/	    UB	output_bank_7; //!<general output bank 7 (outputs 57-64).
	/*24*/  	UB	output_bank_8; //!<general output bank 8 (outputs 65-72).
	/*25*/  	UB	output_bank_9; //!<general output bank 9 (outputs 73-80).

	/*26*/	    UB	error_code; //!<error code.
	/*27*/  	UB	general_status; //!<general status

	/*28-29*/	UW	s_plane_segment_count; //!<segment count of coordinated move for S plane.
	/*30-31*/	UW	s_plane_move_status; //!<coordinated move status for S plane.
	/*32-35*/	SL	s_distance; //!<distance traveled in coordinated move for S plane.

	/*36-37*/	UW	t_plane_segment_count; //!<segment count of coordinated move for T plane.
	/*38-39*/	UW	t_plane_move_status; //!<Coordinated move status for T plane.
	/*40-43*/	SL	t_distance; //!<distance traveled in coordinated move for T plane.

	/*44-45*/	UW	axis_a_status; //!<A axis status.
	/*46*/	    UB	axis_a_switches; //!<A axis switches.
	/*47*/	    UB	axis_a_stop_code; //!<A axis stop code.
	/*48-51*/	SL	axis_a_reference_position; //!<A axis reference position.
	/*52-55*/	SL	axis_a_motor_position; //!<A axis motor position.
	/*56-59*/	SL	axis_a_position_error; //!<A axis position error.
	/*60-63*/	SL	axis_a_aux_position; //!<A axis auxiliary position.
	/*64-67*/	SL	axis_a_velocity; //!<A axis velocity.
	/*68-69*/	SW 	axis_a_torque; //!<A axis torque.
	/*70-71*/	UW  axis_a_analog_in; //!<A axis analog input.

	/*72-73*/	UW	axis_b_status; //!<B axis status.
	/*74*/	    UB	axis_b_switches; //!<B axis switches.
	/*75*/	    UB	axis_b_stop_code; //!<B axis stop code.
	/*76-79*/	SL	axis_b_reference_position; //!<B axis reference position.
	/*80-83*/	SL	axis_b_motor_position; //!<B axis motor position.
	/*84-87*/	SL	axis_b_position_error; //!<B axis position error.
	/*88-91*/	SL	axis_b_aux_position; //!<B axis auxiliary position.
	/*92-95*/	SL	axis_b_velocity; //!<B axis velocity.
	/*96-97*/	SW	axis_b_torque; //!<B axis torque.
	/*98-99*/	UW  axis_b_analog_in; //!<B axis analog input.

	/*100-101*/	UW	axis_c_status; //!<C axis status.
	/*102*/  	UB	axis_c_switches; //!<C axis switches.
	/*103*/ 	UB	axis_c_stop_code; //!<C axis stop code.
	/*104-107*/	SL	axis_c_reference_position; //!<C axis reference position.
	/*108-111*/	SL	axis_c_motor_position; //!<C axis motor position.
	/*112-115*/	SL	axis_c_position_error; //!<C axis position error.
	/*116-119*/	SL	axis_c_aux_position; //!<C axis auxiliary position.
	/*120-123*/	SL	axis_c_velocity; //!<C axis velocity.
	/*124-125*/	SW	axis_c_torque; //!<C axis torque.
	/*126-127*/	UW 	axis_c_analog_in; //!<C axis analog input.

	/*128-129*/	UW	axis_d_status; //!<D axis status.
	/*130*/	    UB	axis_d_switches; //!<D axis switches.
	/*131*/  	UB	axis_d_stop_code; //!<D axis stop code.
	/*132-135*/	SL	axis_d_reference_position; //!<D axis reference position.
	/*136-139*/	SL	axis_d_motor_position; //!<D axis motor position.
	/*140-143*/	SL	axis_d_position_error; //!<D axis position error.
	/*144-147*/	SL	axis_d_aux_position; //!<D axis auxiliary position.
	/*148-151*/	SL	axis_d_velocity; //!<D axis velocity.
	/*152-153*/	SW	axis_d_torque; //!<D axis torque.
	/*154-155*/ UW  axis_d_analog_in; //!<D axis analog input.

	/*156-157*/	UW	axis_e_status; //!<E axis status.
	/*158*/	    UB	axis_e_switches; //!<E axis switches.
	/*159*/	    UB	axis_e_stop_code; //!<E axis stop code.
	/*160-163*/	SL	axis_e_reference_position; //!<E axis reference position.
	/*164-167*/	SL	axis_e_motor_position; //!<E axis motor position.
	/*168-171*/	SL	axis_e_position_error; //!<E axis position error.
	/*172-175*/	SL	axis_e_aux_position; //!<E axis auxiliary position.
	/*176-179*/	SL	axis_e_velocity; //!<E axis velocity.
	/*180-181*/	SW	axis_e_torque; //!<E axis torque.
	/*182-183*/	UW  axis_e_analog_in; //!<E axis analog input.

	/*184-185*/	UW	axis_f_status; //!<F axis status.
	/*186*/	    UB	axis_f_switches; //!<F axis switches.
	/*187*/	    UB	axis_f_stop_code; //!<F axis stop code.
	/*188-191*/	SL	axis_f_reference_position; //!<F axis reference position.
	/*192-195*/	SL	axis_f_motor_position; //!<F axis motor position.
	/*196-199*/	SL	axis_f_position_error; //!<F axis position error.
	/*200-203*/	SL	axis_f_aux_position; //!<F axis auxiliary position.
	/*204-207*/	SL	axis_f_velocity; //!<F axis velocity.
	/*208-209*/	SW	axis_f_torque; //!<F axis torque.
	/*210-211*/	UW	axis_f_analog_in; //!<F axis analog input.

	/*212-213*/	UW	axis_g_status; //!<G axis status.
	/*214*/  	UB	axis_g_switches; //!<G axis switches.
	/*215*/ 	UB	axis_g_stop_code; //!<G axis stop code.
	/*216-219*/	SL	axis_g_reference_position; //!<G axis reference position.
	/*220-223*/	SL	axis_g_motor_position; //!<G axis motor position.
	/*224-227*/	SL	axis_g_position_error; //!<G axis position error.
	/*228-231*/	SL	axis_g_aux_position; //!<G axis auxiliary position.
	/*232-235*/	SL	axis_g_velocity; //!<G axis velocity.
	/*236-237*/	SW	axis_g_torque; //!<G axis torque.
	/*238-239*/ UW  axis_g_analog_in; //!<G axis analog input.

	/*240-241*/	UW	axis_h_status; //!<H axis status.
	/*242*/  	UB	axis_h_switches; //!<H axis switches.
	/*243*/	    UB	axis_h_stop_code; //!<H axis stop code.
	/*244-247*/	SL	axis_h_reference_position; //!<H axis reference position.
	/*248-251*/	SL	axis_h_motor_position; //!<H axis motor position.
	/*252-255*/	SL	axis_h_position_error; //!<H axis position error.
	/*256-259*/	SL	axis_h_aux_position; //!<H axis auxiliary position.
	/*260-263*/	SL	axis_h_velocity; //!<H axis velocity.
	/*264-265*/	SW	axis_h_torque; //!<H axis torque.
	/*266-267*/	UW  axis_h_analog_in; //!<H axis analog input.
}; //DataRecord2013

//!  
//! Data record struct for DMC-1802 controllers.
/*!
The 18x2 Data record is the Same as 2103 except the following.
-# No header bytes. Software removes it from QR.
-# No analog in axis data.
*/
struct GDataRecord1802
{

	/*Offset   type name        description*/

	/*00-01*/  	UW	sample_number; //!<sample number.

	/*02*/	    UB	input_bank_0; //!<general input bank 0 (inputs 1-8).
	/*03*/	    UB	input_bank_1; //!<general input bank 1 (inputs 9-16).
	/*04*/	    UB	input_bank_2; //!<general input bank 2 (inputs 17-24).
	/*05*/	    UB	input_bank_3; //!<general input bank 3 (inputs 25-32).
	/*06*/    	UB	input_bank_4; //!<general input bank 4 (inputs 33-40).
	/*07*/	    UB	input_bank_5; //!<general input bank 5 (inputs 41-48).
	/*08*/	    UB	input_bank_6; //!<general input bank 6 (inputs 49-56).
	/*09*/   	UB	input_bank_7; //!<general input bank 7 (inputs 57-64).
	/*10*/   	UB	input_bank_8; //!<general input bank 8 (inputs 65-72).
	/*11*/	    UB	input_bank_9; //!<general input bank 9 (inputs 73-80).

	/*12*/    	UB	output_bank_0; //!<general output bank 0 (outputs 1-8).
	/*13*/	    UB	output_bank_1; //!<general output bank 1 (outputs 9-16).
	/*14*/   	UB	output_bank_2; //!<general output bank 2 (outputs 17-24).
	/*15*/	    UB	output_bank_3; //!<general output bank 3 (outputs 25-32).
	/*16*/   	UB	output_bank_4; //!<general output bank 4 (outputs 33-40).
	/*17*/	    UB	output_bank_5; //!<general output bank 5 (outputs 41-48).
	/*18*/	    UB	output_bank_6; //!<general output bank 6 (outputs 49-56).
	/*19*/	    UB	output_bank_7; //!<general output bank 7 (outputs 57-64).
	/*20*/  	UB	output_bank_8; //!<general output bank 8 (outputs 65-72).
	/*21*/  	UB	output_bank_9; //!<general output bank 9 (outputs 73-80).

	/*22*/	    UB	error_code; //!<error code.
	/*23*/  	UB	general_status; //!<general status

	/*24-25*/	UW	s_plane_segment_count; //!<segment count of coordinated move for S plane.
	/*26-27*/	UW	s_plane_move_status; //!<coordinated move status for S plane.
	/*28-31*/	SL	s_distance; //!<distance traveled in coordinated move for S plane.

	/*32-33*/	UW	t_plane_segment_count; //!<segment count of coordinated move for T plane.
	/*34-35*/	UW	t_plane_move_status; //!<Coordinated move status for T plane.
	/*36-39*/	SL	t_distance; //!<distance traveled in coordinated move for T plane.

	/*40-41*/	UW	axis_a_status; //!<A axis status.
	/*42*/	    UB	axis_a_switches; //!<A axis switches.
	/*43*/	    UB	axis_a_stop_code; //!<A axis stop code.
	/*44-47*/	SL	axis_a_reference_position; //!<A axis reference position.
	/*48-51*/	SL	axis_a_motor_position; //!<A axis motor position.
	/*52-55*/	SL	axis_a_position_error; //!<A axis position error.
	/*56-59*/	SL	axis_a_aux_position; //!<A axis auxiliary position.
	/*60-63*/	SL	axis_a_velocity; //!<A axis velocity.
	/*64-65*/	SW 	axis_a_torque; //!<A axis torque.
	/*66*/	    UB	axis_a_reserved_0; //!<Reserved.
	/*67*/      UB	axis_a_reserved_1; //!<Reserved.
	
	/*68-69*/   UW	axis_b_status; //!<B axis status.
	/*70*/	    UB	axis_b_switches; //!<B axis switches.
	/*71*/	    UB	axis_b_stop_code; //!<B axis stop code.
	/*72-75*/	SL	axis_b_reference_position; //!<B axis reference position.
	/*76-79*/	SL	axis_b_motor_position; //!<B axis motor position.
	/*80-83*/	SL	axis_b_position_error; //!<B axis position error.
	/*84-87*/	SL	axis_b_aux_position; //!<B axis auxiliary position.
	/*88-91*/	SL	axis_b_velocity; //!<B axis velocity.
	/*92-93*/	SW	axis_b_torque; //!<B axis torque.
	/*94*/	    UB	axis_b_reserved_0; //!<Reserved.
	/*95*/      UB	axis_b_reserved_1; //!<Reserved.

	/*96-97*/	UW	axis_c_status; //!<C axis status.
	/*98*/  	UB	axis_c_switches; //!<C axis switches.
	/*99*/		UB	axis_c_stop_code; //!<C axis stop code.
	/*100-103*/	SL	axis_c_reference_position; //!<C axis reference position.
	/*104-107*/	SL	axis_c_motor_position; //!<C axis motor position.
	/*108-111*/	SL	axis_c_position_error; //!<C axis position error.
	/*112-115*/	SL	axis_c_aux_position; //!<C axis auxiliary position.
	/*116-119*/	SL	axis_c_velocity; //!<C axis velocity.
	/*120-121*/	SW	axis_c_torque; //!<C axis torque.
	/*122*/	    UB	axis_c_reserved_0; //!<Reserved.
	/*123*/     UB	axis_c_reserved_1; //!<Reserved.

	/*124-125*/	UW	axis_d_status; //!<D axis status.
	/*126*/	    UB	axis_d_switches; //!<D axis switches.
	/*127*/  	UB	axis_d_stop_code; //!<D axis stop code.
	/*128-131*/	SL	axis_d_reference_position; //!<D axis reference position.
	/*132-135*/	SL	axis_d_motor_position; //!<D axis motor position.
	/*136-139*/	SL	axis_d_position_error; //!<D axis position error.
	/*140-143*/	SL	axis_d_aux_position; //!<D axis auxiliary position.
	/*144-147*/	SL	axis_d_velocity; //!<D axis velocity.
	/*148-149*/	SW	axis_d_torque; //!<D axis torque.
	/*150*/	    UB	axis_d_reserved_0; //!<Reserved.
	/*151*/     UB	axis_d_reserved_1; //!<Reserved.

}; //DataRecord1802

//! Data record struct for DMC-30010 controllers. 
struct GDataRecord30000
{

	/*Offset   type name        description*/

	/*00*/	    UB	header_0; //!<1st Byte of Header.
	/*01*/	    UB	header_1; //!<2nd Byte of Header.
	/*02*/	    UB	header_2; //!<3rd Byte of Header.
	/*03*/	    UB	header_3; //!<4th Byte of Header.

	/*04-05*/  	UW	sample_number; //!<sample number.

	/*06*/	    UB	input_bank_0; //!<general input bank 0 (inputs 1-8).
	/*07*/	    UB	input_bank_1; //!<general input bank 1 (inputs 9-16).

	/*08*/    	UB	output_bank_0; //!<general output bank 0 (outputs 1-8).
	/*09*/	    UB	output_bank_1; //!<general output bank 1 (outputs 9-16).

	/*10*/	    UB	error_code; //!<error code.
	/*11*/  	UB	thread_status; //!<thread status.

	/*12-13*/	UW	input_analog_2; //!< Analog input 2. 1 is in axis data, see axis_a_analog_in.

	/*14-15*/	UW	output_analog_1; //!< Analog output 1.
	/*16-17*/	UW	output_analog_2; //!< Analog output 2.

	/*18-21*/	UL	amplifier_status; //!<Amplifier Status.

	/*22-25*/	UL	contour_segment_count; //!<Segment Count for Contour Mode.
	/*26-27*/	UW	contour_buffer_available; //!<Buffer space remaining, Contour Mode.

	/*28-29*/	UW	s_plane_segment_count; //!<segment count of coordinated move for S plane.
	/*30-31*/	UW	s_plane_move_status; //!<coordinated move status for S plane.
	/*32-35*/	SL	s_distance; //!<distance traveled in coordinated move for S plane.
	/*36-37*/	UW	s_plane_buffer_available; //!<Buffer space remaining, S Plane.

	/*38-39*/	UW	axis_a_status; //!<A axis status.
	/*40*/	    UB	axis_a_switches; //!<A axis switches.
	/*41*/	    UB	axis_a_stop_code; //!<A axis stop code.
	/*42-45*/	SL	axis_a_reference_position; //!<A axis reference position.
	/*46-49*/	SL	axis_a_motor_position; //!<A axis motor position.
	/*50-53*/	SL	axis_a_position_error; //!<A axis position error.
	/*54-57*/	SL	axis_a_aux_position; //!<A axis auxiliary position.
	/*58-61*/	SL	axis_a_velocity; //!<A axis velocity.
	/*62-65*/	SL 	axis_a_torque; //!<A axis torque.
	/*66-67*/	UW  axis_a_analog_in; //!<A axis analog input.
	/*68*/	    UB	axis_a_halls; //!<A Hall Input Status.
	/*69*/  	UB	axis_a_reserved; //!<Reserved.
	/*70-73*/	SL	axis_a_variable; //!<A User-defined variable (ZA).
}; //DataRecord30000

//! Data record struct for RIO-471xx and RIO-472xx PLCs. Includes encoder fields.
struct GDataRecord47000_ENC
{

	/*Offset   type name        description*/

	/*00*/	    UB	header_0; //!< 1st Byte of Header.
	/*01*/	    UB	header_1; //!< 2nd Byte of Header.
	/*02*/	    UB	header_2; //!< 3rd Byte of Header.
	/*03*/	    UB	header_3; //!< 4th Byte of Header.

	/*04-05*/  	UW	sample_number; //!< Sample number.
	/*06*/	    UB	error_code; //!< Error code.
	/*07*/  	UB	general_status; //!< General status.

	/*08-09*/	UW	output_analog_0; //!< Analog output 0.
	/*10-11*/	UW	output_analog_1; //!< Analog output 1.
	/*12-13*/	UW	output_analog_2; //!< Analog output 2.
	/*14-15*/	UW	output_analog_3; //!< Analog output 3.
	/*16-17*/	UW	output_analog_4; //!< Analog output 4.
	/*18-19*/	UW	output_analog_5; //!< Analog output 5.
	/*20-21*/	UW	output_analog_6; //!< Analog output 6.
	/*22-23*/	UW	output_analog_7; //!< Analog output 7.

	/*24-25*/	UW	input_analog_0; //!< Analog input 0.
	/*26-27*/	UW	input_analog_1; //!< Analog input 1.
	/*28-29*/	UW	input_analog_2; //!< Analog input 2.
	/*30-31*/	UW	input_analog_3; //!< Analog input 3.
	/*32-33*/	UW	input_analog_4; //!< Analog input 4.
	/*34-35*/	UW	input_analog_5; //!< Analog input 5.
	/*36-37*/	UW	input_analog_6; //!< Analog input 6.
	/*38-39*/	UW	input_analog_7; //!< Analog input 7.

	/*40-41*/	UW	output_bank_0; //!< Digital outputs 0-15;

	/*42-43*/	UW	input_bank_0; //!< Digital inputs 0-15;

	/*44-47*/	UL	pulse_count_0; //!< Pulse counter (see PC).
	/*48-51*/	SL	zc_variable; //!< ZC User-defined variable (see ZC). 
	/*52-55*/	SL	zd_variable; //!< ZD User-defined variable (see ZD).

	/*56-59*/	SL	encoder_0; //!< Encoder channel 0. Data only valid for parts with -BISS, -QUAD, or -SSI.
	/*60-63*/	SL	encoder_1; //!< Encoder channel 1. Data only valid for parts with -BISS, -QUAD, or -SSI.
	/*64-67*/	SL	encoder_2; //!< Encoder channel 2. Data only valid for parts with -BISS, -QUAD, or -SSI.
	/*68-71*/	SL	encoder_3; //!< Encoder channel 3. Data only valid for parts with -BISS, -QUAD, or -SSI.

}; //GDataRecord47000_ENC

//! Data record struct for RIO-47300. Includes encoder fields.
struct GDataRecord47300_ENC
{

	/*Offset   type name        description*/

	/*00*/	    UB	header_0; //!< 1st Byte of Header.
	/*01*/	    UB	header_1; //!< 2nd Byte of Header.
	/*02*/	    UB	header_2; //!< 3rd Byte of Header.
	/*03*/	    UB	header_3; //!< 4th Byte of Header.

	/*04-05*/  	UW	sample_number; //!< Sample number.
	/*06*/	    UB	error_code; //!< Error code.
	/*07*/  	UB	general_status; //!< General status.

	/*08-09*/	UW	output_analog_0; //!< Analog output 0.
	/*10-11*/	UW	output_analog_1; //!< Analog output 1.
	/*12-13*/	UW	output_analog_2; //!< Analog output 2.
	/*14-15*/	UW	output_analog_3; //!< Analog output 3.
	/*16-17*/	UW	output_analog_4; //!< Analog output 4.
	/*18-19*/	UW	output_analog_5; //!< Analog output 5.
	/*20-21*/	UW	output_analog_6; //!< Analog output 6.
	/*22-23*/	UW	output_analog_7; //!< Analog output 7.

	/*24-25*/	UW	input_analog_0; //!< Analog input 0.
	/*26-27*/	UW	input_analog_1; //!< Analog input 1.
	/*28-29*/	UW	input_analog_2; //!< Analog input 2.
	/*30-31*/	UW	input_analog_3; //!< Analog input 3.
	/*32-33*/	UW	input_analog_4; //!< Analog input 4.
	/*34-35*/	UW	input_analog_5; //!< Analog input 5.
	/*36-37*/	UW	input_analog_6; //!< Analog input 6.
	/*38-39*/	UW	input_analog_7; //!< Analog input 7.

	/*40-41*/	UW	output_bank_0; //!< Digital outputs 0-15;
	/*42-43*/	UW	output_bank_1; //!< Digital outputs 16-23;

	/*44-45*/	UW	input_bank_0; //!< Digital inputs 0-15;
	/*46-47*/	UW	input_bank_1; //!< Digital inputs 16-23;

	/*48-51*/	UL	pulse_count_0; //!< Pulse counter (see PC).
	/*52-55*/	SL	zc_variable; //!< ZC User-defined variable (see ZC). 
	/*56-59*/	SL	zd_variable; //!< ZD User-defined variable (see ZD).

	/*60-63*/	SL	encoder_0; //!< Encoder channel 0. Data only valid for parts with -BISS, -QUAD, or -SSI.
	/*64-67*/	SL	encoder_1; //!< Encoder channel 1. Data only valid for parts with -BISS, -QUAD, or -SSI.
	/*68-71*/	SL	encoder_2; //!< Encoder channel 2. Data only valid for parts with -BISS, -QUAD, or -SSI.
	/*72-75*/	SL	encoder_3; //!< Encoder channel 3. Data only valid for parts with -BISS, -QUAD, or -SSI.

}; //GDataRecord47300_ENC

//! Data record struct for RIO-47300 with 24EX I/O daughter board.
struct GDataRecord47300_24EX
{

	/*Offset   type name        description*/

	/*00*/	    UB	header_0; //!< 1st Byte of Header.
	/*01*/	    UB	header_1; //!< 2nd Byte of Header.
	/*02*/	    UB	header_2; //!< 3rd Byte of Header.
	/*03*/	    UB	header_3; //!< 4th Byte of Header.

	/*04-05*/  	UW	sample_number; //!< Sample number.
	/*06*/	    UB	error_code; //!< Error code.
	/*07*/  	UB	general_status; //!< General status.

	/*08-09*/	UW	output_analog_0; //!< Analog output 0.
	/*10-11*/	UW	output_analog_1; //!< Analog output 1.
	/*12-13*/	UW	output_analog_2; //!< Analog output 2.
	/*14-15*/	UW	output_analog_3; //!< Analog output 3.
	/*16-17*/	UW	output_analog_4; //!< Analog output 4.
	/*18-19*/	UW	output_analog_5; //!< Analog output 5.
	/*20-21*/	UW	output_analog_6; //!< Analog output 6.
	/*22-23*/	UW	output_analog_7; //!< Analog output 7.

	/*24-25*/	UW	input_analog_0; //!< Analog input 0.
	/*26-27*/	UW	input_analog_1; //!< Analog input 1.
	/*28-29*/	UW	input_analog_2; //!< Analog input 2.
	/*30-31*/	UW	input_analog_3; //!< Analog input 3.
	/*32-33*/	UW	input_analog_4; //!< Analog input 4.
	/*34-35*/	UW	input_analog_5; //!< Analog input 5.
	/*36-37*/	UW	input_analog_6; //!< Analog input 6.
	/*38-39*/	UW	input_analog_7; //!< Analog input 7.

	/*40-41*/	UW	output_bank_0; //!< Digital outputs 0-15.
	/*42-43*/	UW	output_bank_1; //!< Digital outputs 16-23.

	/*44-45*/	UW	input_bank_0; //!< Digital inputs 0-15.
	/*46-47*/	UW	input_bank_1; //!< Digital inputs 16-23.

	/*48-51*/	UL	pulse_count_0; //!< Pulse counter (see PC)8.
	/*52-55*/	SL	zc_variable; //!< ZC User-defined variable (see ZC). 
	/*56-59*/	SL	zd_variable; //!< ZD User-defined variable (see ZD).

	/*60-61*/	UW output_bank_2; //!< Digital outputs 24-39. Data only valid for parts with 24EXOUT.
	/*62-63*/	UW output_back_3; //!< Digital outputs 40-47. Data only valid for parts with 24EXOUT.

	/*64-65*/	UW input_bank_2; //!< Digital inputs 24-39. Data only valid for parts with 24EXIN.
	/*66-67*/	UW input_bank_3; //!< Digital inputs 40-47. Data only valid for parts with 24EXIN.

}; //GDataRecord47300_24EX


//! Data record union, containing all structs and a generic byte array accessor.
/*!
*  Named structs can be used to access typed data by name.
*  Offsets into the data record can also be used by referencing the member `byte_array`.
*
*  \code{.cpp}
*  //Getting the sample counter for the DMC-4000.
*  cout << data_record->dmc4000.sample_number << '\n'; //access by 4000 product
*  cout << * ((unsigned short *) (data_record->byte_array + 4)) << '\n'; //access by pointer arithmetic
*  \endcode
*/
union GDataRecord
{

	struct GDataRecord4000 dmc4000;//!< The DMC-4000 data record.
	struct GDataRecord4000 dmc4103; //!< The DMC-4103 data record.
	struct GDataRecord4000 dmc50000;//!< The DMC-50000 data record.

	struct GDataRecord52000 dmc52000;//!< The DMC-52000 data record.

	struct GDataRecord30000 dmc30000;//!< The DMC-30000 data record.

	struct GDataRecord2103 dmc2103; //!< The DMC-21x3 data record.

	struct GDataRecord1806 dmc1806; //!< The DMC-1806 data record.

	struct GDataRecord1802 dmc1802; //!< The DMC-1802 data record.

	struct GDataRecord47000_ENC rio47000; //!< The RIO-471xx & 472xx data record, including encoder support.
	struct GDataRecord47300_ENC rio47300; //!< The RIO 473xx data record, including encoder support.
	struct GDataRecord47300_24EX rio47300_24ex; //!< The RIO 473xx data record, with 24EXOUT/24EXIN support.

	unsigned char byte_array[GALILDATARECORDMAXLENGTH]; //!< Generic byte array for offsets.
};


#ifdef PACKOK
#pragma pack() //return pack to default
#else
#error "Need to return structure packing for compiler"
#endif

#endif //I_210405D9_D9EF_484F_8258_BB29A1BBA217