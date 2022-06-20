#pragma once

#include <iostream>
#include <string>

#include "../Session/SessionMaster.h"
#include "../Command/CommandParser.h"

class Engine {
public:
	static Engine& getInstance();

	void run(std::istream& in = std::cin, std::ostream& out = std::cout);

private:
	Engine();
	Engine(const Engine& other) = delete;
	Engine& operator=(const Engine& other) = delete;

	SessionMaster m_sessionMaster;
	std::istream* m_in;
	std::ostream* m_out;
	std::string m_line;
	Command* m_cmd;

private:
	void mainEngineLoop();

	void setInAndOut(std::istream& in, std::ostream& out);

	void checkIfTheStreamsAreCorrect() const;
	void printInputSymbol() const;
	void readLine();
	void parseAndExecuteCommand();
	void checkIfCommandIsCorrect() const;
	void printToOut(std::string_view output);
	void checkForUnsavedChanges();
};
