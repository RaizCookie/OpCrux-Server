#include "ServerInfo.hpp"

#include "Common/CrossPlatform.hpp"
#include "StringUtils.hpp"

clock_t ServerInfo::appstart;
bool ServerInfo::initDone = false;
bool ServerInfo::bRunning = true;
const char* ServerInfo::baseTitle = "OpCrux Server";
std::string ServerInfo::m_authIP = "127.0.0.1";
time_t ServerInfo::StartupTime;

int ServerInfo::processID;

void ServerInfo::init() {
	if (!initDone) {
		initDone = true; //Should be up there

#ifdef WIN32
		processID = (int)((unsigned int)GetCurrentProcessId());
#else
		processID = (int)getpid();
#endif
appstart = clock();
		StartupTime = time(0);
	}
}

std::int64_t ServerInfo::startupStamp() {
	return StartupTime;
}

std::int64_t ServerInfo::uptime() {
	return timestamp() - appstart/CLOCKS_PER_SEC;
}

std::int64_t ServerInfo::timestamp() {
	return (clock() / CLOCKS_PER_SEC);
}

std::int64_t ServerInfo::uptimeMs() {
	return ((clock()/CLOCKS_PER_SEC) - (appstart/CLOCKS_PER_SEC))*1000;
}

float ServerInfo::uptime_normalized() {
	return ServerInfo::uptime() * 0.001f;
}

std::int64_t ServerInfo::time_gone(std::int64_t uptime) {
	return uptime - appstart;
}

float ServerInfo::CompareTimes(std::int64_t startTime, std::int64_t endTime) {
	return (endTime - startTime) * 0.001f;
}

std::string ServerInfo::getComputerName() {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	return getenv("COMPUTERNAME");
#endif // WINDOWS
#if defined(LINUX) || defined(MAC) || defined(__CYGWIN__)
	return getenv("HOSTNAME");
#endif // LINUX || MAC
#if defined(__unix) || defined(__unix__)
	char *temp = new char[512];
	if (gethostname(temp, 512) == 0) {
		std::string t = temp;
		delete[] temp;
		return t;
	}
#endif // UNIX
	return ("Function not supported on this operating system.");
}

std::string ServerInfo::getOsName() {
#if defined(_WIN32) || defined(_WIN64)
	return "Windows";
#elif defined(__unix) || defined(__unix__)
	return "Unix";
#elif defined(__APPLE__) || defined(__MACH__)
	return "Mac OSX";
#elif defined(__linux__)
	return "Linux";
#elif defined(__FreeBSD__)
	return "FreeBSD";
#else
	return "Other";
#endif
}

const std::string & ServerInfo::GetAuthIP() {
	return m_authIP;
}

void ServerInfo::SetAuthIP(const std::string & authIP) {
	m_authIP = authIP;
}

std::string ServerInfo::gameVersion = "1.10.64";

void ServerInfo::numericGameVersion(uint16_t * major, uint16_t * current, uint16_t * minor) {
	std::vector<std::string> str{ StringUtils::splitString(gameVersion,'.') };
	*major = std::stoi(str[0]);
	*current = std::stoi(str[1]);
	*minor = std::stoi(str[2]);
}


MasterServer * ServerInfo::masterServer = nullptr;
