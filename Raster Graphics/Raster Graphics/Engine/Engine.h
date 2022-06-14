#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>

#include "../Session/SessionMaster.h"
#include "../Command/CommandParser.h"

class Engine {
public:
	static Engine& getInstance();

	void run();

private:
	Engine();
	Engine(const Engine& other) = delete;
	Engine& operator=(const Engine& other) = delete;

	SessionMaster m_sessionMaster;
};

#endif // !ENGINE_H
