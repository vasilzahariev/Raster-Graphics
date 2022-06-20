#include "../SaveCommand.h"

SaveCommand::SaveCommand(Session* const session)
    : m_session(session) {
}

size_t SaveCommand::getNumberOfArgs() {
    return nArgs;
}

std::string SaveCommand::execute() {
    m_session->saveChanges();

    return "Save was successful";
}
