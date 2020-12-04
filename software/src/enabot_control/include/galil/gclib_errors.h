/*! \file gclib_errors.h
*
* Defines values for the Galil C Library return codes and error strings.
*
*/
#ifndef I_0DD3687F_47D0_454B_ADB2_CBAB0ED46FCE
#define I_0DD3687F_47D0_454B_ADB2_CBAB0ED46FCE

#define G_NO_ERROR 0  //!< Return value if function succeeded. 
#define G_NO_ERROR_S "no error"

#define G_GCLIB_ERROR -1 //!< General library error. Indicates internal API caught an unexpected error. Contact Galil support if this error is returned, softwaresupport@galil.com.
#define G_GCLIB_ERROR_S "gclib unexpected error"

#define G_GCLIB_UTILITY_ERROR -2 //!< An invalid request value was specified to GUtility.
#define G_GCLIB_UTILITY_ERROR_S "invalid request value or bad arguments were specified to GUtility()"

#define G_GCLIB_UTILITY_IP_TAKEN -3 //!< The IP cannot be assigned because ping returned a reply. 
#define G_GCLIB_UTILITY_IP_TAKEN_S "ip address is already taken by a device on the network"

#define G_GCLIB_NON_BLOCKING_READ_EMPTY -4 //!< GMessage, GInterrupt, and GRecord can be called with a zero timeout. If there wasn't data waiting in memory, this error is returned.
#define G_GCLIB_NON_BLOCKING_READ_EMPTY_S "data was not waiting for a zero-timeout read"

#define G_TIMEOUT -1100 //!< Operation timed out. Timeout is set by the --timeout option in GOpen() and can be overriden by GSetting().
#define G_TIMEOUT_S "device timed out"

#define G_OPEN_ERROR -1101 //!< Device could not be opened. E.G. Serial port or PCI device already open.
#define G_OPEN_ERROR_S "device failed to open"

#define G_INVALID_PREPROCESSOR_OPTIONS -1204 //!< GProgramDownload was called with a bad preprocessor directive.
#define G_INVALID_PREPROCESSOR_OPTIONS_S "preprocessor did not recognize options"

#define G_COMMAND_CALLED_WITH_ILLEGAL_COMMAND -1106 //!< GCommand() was called with an illegal command, e.g. ED, DL or QD.
#define G_COMMAND_CALLED_WITH_ILLEGAL_COMMAND_S "illegal command passed to command call"

#define G_DATA_RECORD_ERROR -1107 //!< Data record error, e.g. DR attempted on serial connection.
#define G_DATA_RECORD_ERROR_S "data record error"

#define G_UNSUPPORTED_FUNCTION -1109 //!< Function cannot be called on this bus. E.G. GInterrupt() on serial.
#define G_UNSUPPORTED_FUNCTION_S "function not supported on this communication bus"

#define G_FIRMWARE_LOAD_NOT_SUPPORTED -1110 //!< Firmware is not supported on this bus, e.g. Ethernet for the DMC-21x3 series.
#define G_FIRMWARE_LOAD_NOT_SUPPORTED_S "firmware cannot be loaded on this communication bus to this hardware"

#define G_ARRAY_NOT_DIMENSIONED -1200 //!< Array operation was called on an array that was not in the controller's array table, see LA command.
#define G_ARRAY_NOT_DIMENSIONED_S "array not dimensioned on controller or wrong size"

#define G_ILLEGAL_DATA_IN_PROGRAM -1202 //!< Data to download not valid, e.g. \ in data.
#define G_ILLEGAL_DATA_IN_PROGRAM_S "illegal ASCII character in program"

#define G_UNABLE_TO_COMPRESS_PROGRAM_TO_FIT -1203 //!< Program preprocessor could not compress the program within the user's constraints.
#define G_UNABLE_TO_COMPRESS_PROGRAM_TO_FIT_S "program cannot be compressed to fit on the controller"

#define G_BAD_RESPONSE_QUESTION_MARK -10000 //!< Operation received a ?, indicating controller has a TC error.
#define G_BAD_RESPONSE_QUESTION_MARK_S "question mark returned by controller"

#define G_BAD_VALUE_RANGE -10002 //!< Bad value or range, e.g. GCon *g* variable passed to function was bad.
#define G_BAD_VALUE_RANGE_S "value passed to function was bad or out of range"

#define G_BAD_FULL_MEMORY -10003 //!< Not enough memory for an operation, e.g. all connections allowed for a process already taken.
#define G_BAD_FULL_MEMORY_S "operation could not complete because of a memory error"

#define G_BAD_LOST_DATA -10004 //!< Lost data, e.g. GCommand() response buffer was too small for the controller's response.
#define G_BAD_LOST_DATA_S "data was lost due to buffer or fifo limitations"

#define G_BAD_FILE -10005 //!< Bad file path, bad file contents, or bad write.
#define G_BAD_FILE_S "file was not found, contents are invalid, or write failed"

#define G_BAD_ADDRESS -10006 //!< Bad address
#define G_BAD_ADDRESS_S "a bad address was specified in open"

#define G_GCAPS_OPEN_ERROR -20000 //!< gcaps connection couldn't open. Server is not running or is not reachable.
#define G_GCAPS_OPEN_ERROR_S "gcaps connection could not be opened"

#endif //I_0DD3687F_47D0_454B_ADB2_CBAB0ED46FCE
