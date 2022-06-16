#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <vector>
#include <string>
#include <string_view>

#include "../Session/SessionMaster.h"

#include "Command.h"
#include "OpenCommand.h"
#include "HelpCommand.h"
#include "RotateCommand.h"
#include "SaveCommand.h"
#include "SaveAsCommand.h"
#include "CloseCommand.h"
#include "UndoCommand.h"
#include "GrayscaleCommand.h"
#include "MonochromeCommand.h"
#include "NegativeCommand.h"

class CommandFactory {
public:
	static Command* createCommand(std::vector<std::string_view> args, SessionMaster* sessionMaster);

private:
	CommandFactory() = delete;
	CommandFactory(const CommandFactory&) = delete;
	CommandFactory& operator=(const CommandFactory&) = delete;
};

#endif // !COMMANDFACTORY_H
