#pragma once

#include <vector>
#include <string>
#include <string_view>

#include "../Session/SessionMaster.h"

#include "../Command/Command.h"
#include "../Command/OpenCommand.h"
#include "../Command/HelpCommand.h"
#include "../Command/RotateCommand.h"
#include "../Command/SaveCommand.h"
#include "../Command/SaveAsCommand.h"
#include "../Command/CloseCommand.h"
#include "../Command/UndoCommand.h"
#include "../Command/GrayscaleCommand.h"
#include "../Command/MonochromeCommand.h"
#include "../Command/NegativeCommand.h"
#include "../Command/AddCommand.h"

class CommandFactory {
public:
	static Command* createCommand(std::vector<std::string_view> args, SessionMaster* sessionMaster);

private:
	CommandFactory() = delete;
	CommandFactory(const CommandFactory&) = delete;
	CommandFactory& operator=(const CommandFactory&) = delete;
};
