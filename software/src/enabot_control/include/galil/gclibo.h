/*! \file gclibo.h
*
* Open-source convenience functions for Galil C Lib.
* Please email softwarefeedback@galil.com with suggestions for useful/missing functions.
*
*/
#ifndef I_007AD0AF_C956_4B96_ADE2_AD04FAFFEE99
#define I_007AD0AF_C956_4B96_ADE2_AD04FAFFEE99

//set library visibility for gcc and msvc
#if BUILDING_GCLIB && HAVE_VISIBILITY
#define GCLIB_DLL_EXPORTED __attribute__((__visibility__("default")))
#elif BUILDING_GCLIB && defined _MSC_VER
#define GCLIB_DLL_EXPORTED __declspec(dllexport)
#elif defined _MSC_VER
#define GCLIB_DLL_EXPORTED __declspec(dllimport)
#else
#define GCLIB_DLL_EXPORTED
#endif

#include "gclib.h" //Galil's C Library

#ifdef _WIN32
#define GCALL __stdcall
#else
#define GCALL  /* nothing */
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MALLOCBUF G_HUGE_BUFFER //!< Malloc used for large program and array uploads.
#define MAXPROG MALLOCBUF //!< Maximum size for a program.
#define MAXARRAY MALLOCBUF //!< Maximum size for an array table upload.
#define POLLINGINTERVAL 100 //!< Interval, in miliseconds, for polling commands, e.g. GMotionComplete().
#define G_USE_GCAPS //!< Use the GCAPS server in GAddresses(), GAssign(), GIpRequests(), and GVersion(). To avoid GCAPS, comment out this line and recompile, http://galil.com/sw/pub/all/doc/gclib/html/gclibo.html

	//! Uses GUtility() and @ref G_UTIL_SLEEP to provide a blocking sleep call which can be useful for timing-based chores.
	GCLIB_DLL_EXPORTED void GCALL GSleep(unsigned int timeout_ms);
	/*!<
	*  \param timeout_ms The timeout, in milliseconds, to block before returning.
	*
	*  See GMotionComplete() for an example.
	*/


	//! Uses GUtility(), @ref G_UTIL_VERSION and @ref G_UTIL_GCAPS_VERSION to provide the library and @ref gcaps version numbers.
	GCLIB_DLL_EXPORTED GReturn GCALL GVersion(GCStringOut ver, GSize ver_len);
	/*!<
	*  \param ver Buffer to hold the output string. Buffer will be null terminated, even if the data must be truncated to do so.
	*  \param ver_len Length of buffer.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  The version number of gclib is provided first. If the @ref gcaps server can be found, 
	*  its version will be provided after a space.
	*
	*  Example with gcaps version.
	*
	*      154.190.329 1.0.0.82
	*  
	*  Example with gclib version only.
	*  
	*      154.190.329
	*  
	*  \note GVersion() will take up to 1 second to look for @ref gcaps.
	*
	*  See x_examples.cpp for an example.
	*/

	//! Uses GUtility(), @ref G_UTIL_GCAPS_ADDRESSES or @ref G_UTIL_ADDRESSES to provide a listing of all available connection addresses.
	GCLIB_DLL_EXPORTED GReturn GCALL GAddresses(GCStringOut addresses, GSize addresses_len);
	/*!<
	*  \note Serial ports are listed, e.g. COM1. Upon open, it may be necesary to specify a baud rate for the controller, e.g. `--baud 19200`.
	*        Default baud is 115200. See GOpen().
	*
	*  \param addresses Buffer to hold the output string. Buffer will be null terminated, even if the data must be truncated to do so. See below for more information.
	*  \param addresses_len Length of buffer.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  If @ref gcaps is available, the listing will come from the server via  @ref G_UTIL_GCAPS_ADDRESSES. 
	*  In the abscence of the server, gclib will use @ref G_UTIL_ADDRESSES to generate the list.
	*
	*  * Ethernet controllers will be listed as *ip_address, revision_report, network_adaptor_name, network_adaptor_ip_address*.
	*  If an IP address is unreachable via ping, the address will be in parentheses.
	*  * PCI controllers will be listed by their identifier, e.g. GALILPCI1.
	*  * Serial ports will be listed by their identifier, e.g. COM1.
	*
	*
	*      10.1.3.91, DMC4020 Rev 1.2e, LAN, 10.1.3.10
	*      192.168.0.63, DMC4040 Rev 1.2f, Static, 192.168.0.41
	*      (192.0.0.42), RIO47102 Rev 1.1j, Static, 192.168.0.41
	*      10.1., RIO47102 Rev 1.1j, Static, 192.168.0.41
	*      GALILPCI1
	*      COM1
	*      COM2
	*
	*  \note GAddresses() will take up to 1 second to look for @ref gcaps.
	*
	*  See x_examples.cpp for an example.
	*/

	//! Uses GUtility() and @ref G_UTIL_INFO to provide a useful connection string.
	GCLIB_DLL_EXPORTED GReturn GCALL GInfo(GCon g, GCStringOut info, GSize info_len);
	/*!<
	*  \param g Connection's handle.
	*  \param info Buffer to hold the output string. Buffer will be null terminated, even if the data must be truncated to do so.
	*  \param info_len Length of buffer.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  The response is *address, revision_report, serial_number*. For example:
	*
	*      COM2, RIO47102 Rev 1.1j, 37290
	*
	*  See x_examples.cpp for an example.
	*/


	//! Uses GUtility() and @ref G_UTIL_TIMEOUT_OVERRIDE to set the library timeout.
	GCLIB_DLL_EXPORTED GReturn GCALL GTimeout(GCon g, short timeout_ms);
	/*!<
	*  \param g Connection's handle.
	*  \param timeout_ms The value to be used for the timeout. Use `G_USE_INITIAL_TIMEOUT` to set the timeout back to the initial GOpen() value, `--timeout`.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_gcommand.cpp and x_gread_gwrite.cpp for examples.
	*/


	//! Wrapper around GCommand for use when the return value is not desired.
	GCLIB_DLL_EXPORTED GReturn GCALL GCmd(GCon g, GCStringIn command);
	/*!<
	*  The returned data is still checked for error, e.g. `?` or timeout, but is not brought out through the prototype.
	*
	*  \param g Connection's handle.
	*  \param command Null-terminated command string to send to the controller.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_gcommand.cpp for an example.
	*/


	//! Wrapper around GCommand that trims the response.
	GCLIB_DLL_EXPORTED GReturn GCALL GCmdT(GCon g, GCStringIn command, GCStringOut trimmed_response, GSize response_len, GCStringOut* front);
	/*!<
	*  For use when the return value is desired, is ASCII (not binary), and the response should be trimmed of trailing colon, whitespace, and optionally leading space.
	*
	*  \param g Connection's handle.
	*  \param command Null-terminated command string to send to the controller.
	*  \param trimmed_response The trimmed response from the controller. Trailing space is trimmed by null terminating any trailing spaces, carriage returns, or line feeds.
	*  \param response_len The length of the trimmed_response buffer.
	*  \param front If non-null, upon return *front will point to the first non-space character in trimmed_response.
	*          This allows trimming the front of the string without modifying the user's buffer pointer, which may be allocated on the heap.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_gcommand.cpp for an example.
	*/


	//! Wrapper around GCommand that provides the return value of a command parsed into an int.
	GCLIB_DLL_EXPORTED GReturn GCALL GCmdI(GCon g, GCStringIn command, int* value);
	/*!<
	*  Use this function to get most values including TP, RP, TE, Digital I/O states, etc.
	*
	*  \param g Connection's handle.
	*  \param command Null-terminated command string to send to the controller.
	*  \param value Pointer to an int that will be filled with the return value.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_gcommand.cpp for an example.
	*/


	//! Wrapper around GCommand that provides the return value of a command parsed into a double.
	GCLIB_DLL_EXPORTED GReturn GCALL GCmdD(GCon g, GCStringIn command, double* value);
	/*!<
	*  Use this function to retrieve the full Galil 4.2 range, e.g. for a variable value with fractional data,
	*  or the value of an Analog input or Output.
	*
	*  \param g Connection's handle.
	*  \param command Null-terminated command string to send to the controller.
	*  \param value Pointer to a double that will be filled with the return value.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_gcommand.cpp for an example.
	*/


	//! Blocking call that returns once all axes specified have completed their motion.
	GCLIB_DLL_EXPORTED GReturn GCALL GMotionComplete(GCon g, GCStringIn axes);
	/*!<
	*  \note This function uses a profiled motion indicator, not the position of the encoder. E.G. see the difference between AM (profiled) and MC (encoder-based).
	*
	*  Although using the _BGm operand is the most generally compatible method,
	*  there are higher-performance ways to check for motion complete by using
	*  the data record, or interrupts. See examples x_dr_motioncomplete() and x_ei_motioncomplete().
	*
	*  \param g Connection's handle.
	*  \param axes A null-terminated string containing a multiple-axes mask. Every character in the string should be a valid argument to MG_BGm, i.e. XYZWABCDEFGHST.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_gmotioncomplete.cpp for an example.
	*/


	//! Sets the asynchronous data record to a user-specified period via `DR`.
	GCLIB_DLL_EXPORTED GReturn GCALL GRecordRate(GCon g, double period_ms);
	/*!<
	*  Takes TM and product type into account and sets the `DR` period to the period requested by the user, if possible.
	*
	*  \param g Connection's handle.
	*  \param period_ms Period, in milliseconds, to set up for the asynchronous data record.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_grecord.cpp for an example.
	*/


	//! Program download from file.
	GCLIB_DLL_EXPORTED GReturn GCALL GProgramDownloadFile(GCon g, GCStringIn file_path, GCStringIn preprocessor);
	/*!<
	*  \param g Connection's handle.
	*  \param file_path Null-terminated string containing the path to the program file.
	*  \param preprocessor Options string for preprocessing the program before sending it to the controller. See GProgramDownload().
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_programs.cpp for an example.
	*/


	//! Program upload to file.
	GCLIB_DLL_EXPORTED GReturn GCALL GProgramUploadFile(GCon g, GCStringIn file_path);
	/*!<
	*  \param g Connection's handle.
	*  \param file_path Null-terminated string containing the path to the program file, file will be overwritten if it exists.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_programs.cpp for an example.
	*/


	//! Array download from file.
	GCLIB_DLL_EXPORTED GReturn GCALL GArrayDownloadFile(GCon g, GCStringIn file_path);
	/*!<
	*  Downloads a csv file containing array data at `file_path`. If the arrays don't exist, they will be dimensioned.
	*
	*  \param g Connection's handle.
	*  \param file_path Null-terminated string containing the path to the array file.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_arrays.cpp for an example.
	*/


	//! Array upload to file.
	GCLIB_DLL_EXPORTED GReturn GCALL GArrayUploadFile(GCon g, GCStringIn file_path, GCStringIn names);
	/*!<
	*  Uploads the entire controller array table or a subset and saves the data as a csv file specified by `file_path`.
	*
	*  \param g Connection's handle.
	*  \param file_path Null-terminated string containing the path to the array file, file will be overwritten if it exists.
	*  \param names Null-terminated string containing the arrays to upload, delimited with space. "" or null uploads all arrays listed in LA.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  See x_arrays.cpp for an example.
	*/

	
	//! Uses GUtility(), @ref G_UTIL_GCAPS_IPREQUEST or @ref G_UTIL_IPREQUEST to provide a list of all Galil controllers requesting IP addresses via BOOT-P or DHCP.
	GCLIB_DLL_EXPORTED GReturn GCALL GIpRequests(GCStringOut requests, GSize requests_len);
	/*!<
	*  \param requests The buffer to hold the list of requesting controllers. Data will be null terminated, even if the data must be truncated to do so. See below for more information.
	*  \param requests_len The length of the requests buffer.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values.
	*
	*  GIpRequests() will block about 5 seconds while listening for requests.
	*
	*  If @ref gcaps is available, the listing will come from the server via  @ref G_UTIL_GCAPS_IPREQUEST.
	*  In the abscence of the server, gclib will use @ref G_UTIL_IPREQUEST to generate the list.
	*
	*  \attention When not using @ref gcaps, Linux/OS X users must be root to use GIpRequests() and have UDP access to bind and listen on port 67.
	*
	*  Each line of the returned data will be of the form *model, serial_number, MAC_address, network_adaptor_name, network_adaptor_ip_address*. For example:
	*
	*      DMC4000, 291, 00:50:4C:20:01:23, LAN, 10.1.3.10
	*      RIO47000, 37290, 00:50:4C:28:91:AA, Static, 192.168.0.41
	*
	*  \note GIpRequests() will take up to 1 second to look for @ref gcaps.
	*
	*  See x_examples.cpp for an example.
	*/


	//! Uses GUtility(), @ref G_UTIL_GCAPS_ASSIGN or @ref G_UTIL_ASSIGN to assign an IP address over the Ethernet to a controller at a given MAC address.
	GCLIB_DLL_EXPORTED GReturn GCALL GAssign(char* ip, char* mac);
	/*!< 
	*  \param ip The null-terminated ip address to assign. The hardware should not yet have an IP address.
	*  \param mac The null-terminated MAC address of the hardware.
	*
	*  \return The success status or error code of the function. See gclib_errors.h for possible values. 
	*
	*  
	*  On Linux and Mac, the desired IP address will be pinged prior to the assigment. If the ping is returned, GAssign() will return @ref G_GCLIB_UTILITY_IP_TAKEN.
	*
	*  If @ref gcaps is available, the assign will be performed from the server via  @ref G_UTIL_GCAPS_ASSIGN. 
	*  In the abscence of the server, gclib will use @ref G_UTIL_ASSIGN to assign.
	*
	*  \attention When not using @ref gcaps, Linux/OS X users must be root to use GAssign() and have UDP access to send on port 68.
	*
	*  \note GAssign() will take up to 1 second to look for @ref gcaps.
	*
	*  See x_examples.cpp for an example.
	*/
		

	//! Provides a human-readable description string for return codes.
	GCLIB_DLL_EXPORTED void GCALL GError(GReturn rc, GCStringOut error, GSize error_len);
	/*!<
	*  \param rc The return code to lookup.
	*  \param error The buffer to fill with the error text. Buffer will be null terminated, even if the data must be truncated to do so.
	*  \param error_len The length of the error buffer.
	*
	*  See x_examples.cpp for an example.
	*/

#ifdef __cplusplus
} //extern "C"
#endif

#endif //I_007AD0AF_C956_4B96_ADE2_AD04FAFFEE99
