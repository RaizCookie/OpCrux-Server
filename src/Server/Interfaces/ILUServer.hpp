#pragma once
#ifndef _ILUSERVER_HPP
#define _ILUSERVER_HPP

#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <iostream>

#include "../Bridges/BridgeMasterServer.hpp"

class ILUServer {
public:
	bool initDone;

	ILUServer() {};
	~ILUServer() {};
};

#endif