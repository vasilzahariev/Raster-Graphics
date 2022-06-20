#include "../CommandParser.h"

Command* CommandParser::parseCommandLine(std::string line, SessionMaster* sessionMaster) {
	checkIfLineIsEmpty(line);
	std::vector<std::string> args;

	checkIfNumberOfQuotesIsCorrect(line.begin(), line.end());
	removeAdditionalSpaces(line.begin(), line);
	extractArgsFromCommandLine(line, args);

	return CommandFactory::createCommand(args, sessionMaster);
}

void CommandParser::checkIfLineIsEmpty(std::string& line) {
	if (line.empty())
		throw NotAnException("Skip");
}

void CommandParser::checkIfNumberOfQuotesIsCorrect(std::string::const_iterator symbol, const std::string::const_iterator end, bool status) {
	if (symbol == end && !status)
		throw CommandException("The Number of quotes is incorrect");
	else if (symbol != end)
		checkIfNumberOfQuotesIsCorrect(++symbol, end, status);
}

void CommandParser::removeAdditionalSpaces(std::string::iterator symbol, std::string& line, bool status) {
	if (symbol == line.end()) {
		if (*(symbol - 1) == ' ')
			line.erase(symbol - 1);

		return;
	}
	else if (*symbol == ' ' && status) line.erase(symbol);
	else {
		status = (*symbol == ' ');
		++symbol;
	}

	removeAdditionalSpaces(symbol, line, status);
}

void CommandParser::extractArgsFromCommandLine(const std::string& line, std::vector<std::string>& args) {
	size_t start = 0;
	bool isQuote = false;

	for (size_t index = 0; index < line.size(); ++index) {
		if (line[index] == '\"') isQuote = !isQuote;

		if ((line[index] == ' ' && !isQuote) || index == line.size() - 1)
			extractArgFromLine(line, args, start, index);
	}

	if (args.size() == 0)
		throw CommandException("Invalid type of command");
}

void CommandParser::extractArgFromLine(const std::string& line, std::vector<std::string>& args, size_t& start, const size_t index) {
	std::string arg = line.substr(start, index - start + (index == line.size() - 1 ? 1 : 0));
	std::replace_if(arg.begin(), arg.end(), [](char c) { return c == '\"'; }, '\0');
	args.push_back(arg);

	start = index + 1;
}
