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
#include "../Command/ExitCommand.h"
#include "../Command/SessionInfoCommand.h"
#include "../Command/SwitchCommand.h"

class CommandFactory {
public:
	static Command* createCommand(std::vector<std::string> args, SessionMaster* sessionMaster);

private:
	CommandFactory() = delete;
	CommandFactory(const CommandFactory&) = delete;
	CommandFactory& operator=(const CommandFactory&) = delete;

	static void argsValidator(const std::vector<std::string> args, const size_t numberOfArgs, bool(*validator)(const std::vector<std::string>& str) = nullptr);
};
