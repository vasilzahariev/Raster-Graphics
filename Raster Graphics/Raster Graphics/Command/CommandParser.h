#pragma once

#include <string>
#include <string_view>
#include <vector>

#include "Command.h"
#include "../Exceptions/CommandException.h"
#include "../Session/SessionMaster.h"
#include "../Factories/CommandFactory.h"

class CommandParser {
public:
	static Command* parseCommandLine(std::string line, SessionMaster* sessionMaster);

private:
	CommandParser() = delete;
	CommandParser(const CommandParser&) = delete;
	CommandParser& operator=(const CommandParser&) = delete;

	static void checkIfLineIsEmpty(std::string& line);

	static void checkIfNumberOfQuotesIsCorrect(std::string::const_iterator symbol, const std::string::const_iterator end, bool status = true);
	
	static void removeAdditionalSpaces(std::string::iterator symbol, std::string& line, bool status = false);

	static void extractArgsFromCommandLine(const std::string& line, std::vector<std::string>& args);

	static void extractArgFromLine(const std::string& line, std::vector<std::string>& args, size_t& start, const size_t index);
};
