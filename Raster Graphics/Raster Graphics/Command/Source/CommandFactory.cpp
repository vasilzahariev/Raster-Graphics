#include "../CommandFactory.h"

Command* CommandFactory::createCommand(std::vector<std::string_view> args, SessionMaster* sessionMaster) {
    std::string_view commandType = args[0];

    if (commandType == "open")
        return new OpenCommand(sessionMaster, args[1]);
    else if (commandType == "rotate")
        return new RotateCommand(sessionMaster->getActiveSession(), args[1]);
    else if (commandType == "grayscale")
        return new GrayscaleCommand(sessionMaster->getActiveSession());
    else if (commandType == "monochrome")
        return new MonochromeCommand(sessionMaster->getActiveSession());
    else if (commandType == "negative")
        return new NegativeCommand(sessionMaster->getActiveSession());
    else if (commandType == "add")
        return new AddCommand(sessionMaster->getActiveSession(), args[1]);
    else if (commandType == "save")
        return new SaveCommand(sessionMaster->getActiveSession());
    else if (commandType == "saveas")
        return new SaveAsCommand(sessionMaster->getActiveSession(), args[1]);
    else if (commandType == "close")
        return new CloseCommand(sessionMaster->getActiveSession());
    else if (commandType == "undo")
        return new UndoCommand(sessionMaster->getActiveSession());
    else if (commandType == "help")
        return new HelpCommand();

    throw CommandException("Invalid command");
}
