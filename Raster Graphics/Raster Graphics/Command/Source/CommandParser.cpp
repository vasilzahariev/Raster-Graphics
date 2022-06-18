#include "../CommandParser.h"

Command* CommandParser::parseCommandLine(std::string line, SessionMaster* sessionMaster) {
	if (!checkIfNumberOfQuotesIsCorrect(line))
		throw CommandException("The Number of quotes is incorrect");
	
	removeAdditionalSpaces(line);

	std::vector<std::string> args;

	extractArgsFromCommandLine(line, args);

	return CommandFactory::createCommand(args, sessionMaster);
}

bool CommandParser::checkIfNumberOfQuotesIsCorrect(std::string_view line) {
	bool result = true;
	
	for (std::string_view::const_iterator symbol = line.begin(); symbol != line.end(); ++symbol)
		if (*symbol == '\"') result = !result;

	return result;
}

void CommandParser::removeAdditionalSpaces(std::string& line) {
	std::string newLine = "";
	bool wasWhiteSpace = false;

	for (std::string::iterator symbol = line.begin(); symbol != line.end(); ++symbol) {
		if (*symbol == ' ' && wasWhiteSpace) {
			continue;
		}
		else if (*symbol == ' ' && !wasWhiteSpace) {
			wasWhiteSpace = true;
		}
		else {
			wasWhiteSpace = false;
		}

		newLine.push_back(*symbol);
	}

	line = newLine;
}

void CommandParser::extractArgsFromCommandLine(std::string_view line, std::vector<std::string>& args) {
	std::string arg = "";
	bool quote = false;
	
	for (std::string_view::iterator symbol = line.begin(); symbol != line.end(); ++symbol) {
		if (*symbol == ' ' && !quote) {
			args.push_back(arg);

			arg.clear();
		}
		else if (*symbol == '\"') {
			quote = !quote;
		}
		else {
			arg.push_back(*symbol);
		}
	}

	if (arg != "") args.push_back(arg);
}
