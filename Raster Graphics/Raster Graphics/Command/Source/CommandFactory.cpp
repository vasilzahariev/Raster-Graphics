#include "../CommandFactory.h"

Command* CommandFactory::createCommand(std::vector<std::string_view> args, SessionMaster* sessionMaster) {
    std::string_view commandType = args[0];

    if (commandType == "open")
        return new OpenCommand(sessionMaster, args[1]);
    else if (commandType == "rotate")
        return new RotateCommand(sessionMaster->getActiveSession(), args[1]);
    else if (commandType == "save")
        return new SaveCommand(sessionMaster->getActiveSession());
    else if (commandType == "saveas")
        return new SaveAsCommand(sessionMaster->getActiveSession(), args[1]);
    else if (commandType == "close")
        return new CloseCommand(sessionMaster->getActiveSession());
    else if (commandType == "help")
        return new HelpCommand();

    return nullptr;
}
