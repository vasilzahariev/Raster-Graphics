#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include <string_view>
#include <vector>

#include "Command.h"
#include "../Exceptions/CommandException.h"
#include "../Session/SessionMaster.h"
#include "../Command/CommandFactory.h"

class CommandParser {
public:
	CommandParser() = delete;
	CommandParser(const CommandParser&) = delete;
	CommandParser& operator=(const CommandParser&) = delete;

	static Command* parseCommandLine(std::string line, SessionMaster* sessionMaster);

private:
	static bool checkIfNumberOfQuotesIsCorrect(std::string_view line);
	
	static void removeAdditionalSpaces(std::string& line);

	static void extractArgsFromCommandLine(std::string_view line, std::vector<std::string_view>& args);
};

#endif // !COMMANDPARSER_H
