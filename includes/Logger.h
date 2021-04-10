/*
 * Logger.h
 *
 *  Created on: Mar 29, 2021
 *      Author: keith
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include <fstream>
#include <mutex>
#include "../includes/constants.h"

//TODONE please implement Logger.cpp
//TODONE please make this class threadsafe
//TODONE please make all critical sections as small as possible
//TODONE please use lock_guards

class Logger {
public:
	/***
	 * creates a logger object, if lt=FILE then log to the file given by fn
	 * if lt=LOG_CONSOLE the send log info to console via cout
	 * @param lt either LOG_FILE or LOG_CONSOLE
	 * @param fn if above is LOG_FILE then this is where info logged to
	 *           otherwise it is not used
	 */
	Logger(LOG_TYPE lt, std::string fn=FILENAME);
	
	/***
	 * Information to log, either to a file or to console
	 * @param info to log
	 */
	void Log(std::string info);
	
	/***
	 * close any open streams
	 */
	virtual ~Logger();
	
private:
	LOG_TYPE lt;
	//if using LOG_TYPE::LOG_FILE then fn is the file where info is written, 
	//and fs is the stream used to access it.  Otherwise both ignored
	std::string fn;	
	std::ofstream fs;
	
	//used to make instance of this class threadsafe
	std::mutex mtx;
};

#endif /* LOGGER_H_ */
