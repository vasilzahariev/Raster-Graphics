#include "../SaveCommand.h"

SaveCommand::SaveCommand(Session* const session)
    : m_session(session) {
}

std::string SaveCommand::execute() {
    std::string output = "";

    try {
        m_session->saveChanges();

        output = "Save was successful";
    }
    catch (std::exception err) {
        output = err.what();
    }

    return output;
}
