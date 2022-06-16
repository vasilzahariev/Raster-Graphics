#include "../SaveCommand.h"

SaveCommand::SaveCommand(Session* const session)
    : m_session(session) {
}

void SaveCommand::execute() {
    m_session->saveChanges();
}

Command* SaveCommand::clone() {
    return new SaveCommand(m_session);
}
