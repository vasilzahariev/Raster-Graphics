#include "../SaveCommand.h"

SaveCommand::SaveCommand(Session* const session)
    : m_session(session) {
}

std::string SaveCommand::executor() {
    m_session->saveChanges();

    return "Save was successful";
}
