#pragma once

#include <Windows.h>
#include <string>
#include <cstdarg>

class Logger
{
public:
	Logger(const char* prefix)
	{
		m_printPrefix = prefix;

		FILE* logFile = LogFile(nullptr);
		if (logFile == nullptr)
		{
			fopen_s(&logFile, "mod_loader_log.txt", "w");
			LogFile(logFile);
		}
	}

	void Log(std::string msg, ...)
	{
		va_list args;
		va_start(args, msg);
		vprintf(std::string(m_printPrefix + " > " + msg + "\n").c_str(), args);
		if (LogFile(nullptr) != nullptr)
		{
			vfprintf(LogFile(nullptr), std::string(m_printPrefix + " > " + msg + "\n").c_str(), args);
			fflush(LogFile(nullptr));
		}
		va_end(args);
	}

	void Close()
	{
		if (LogFile(nullptr) != nullptr)
		{
			fclose(LogFile(nullptr));
		}
	}

	~Logger()
	{
		Close();
	}

private:
	std::string m_printPrefix = "";

	static FILE* LogFile(FILE* newLogFile)
	{
		static FILE* logFile = nullptr;
		if (newLogFile != nullptr)
		{
			logFile = newLogFile;
		}
		return logFile;
	}
};