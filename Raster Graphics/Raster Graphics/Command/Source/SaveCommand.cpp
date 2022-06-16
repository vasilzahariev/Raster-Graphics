#include "../SaveCommand.h"

SaveCommand::SaveCommand(Session* const session)
    : m_session(session) {
}

std::string SaveCommand::execute() {
    m_session->saveChanges();// TODO: Add try catch and return the proper message
}
