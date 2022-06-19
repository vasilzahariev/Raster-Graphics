#include "../SessionMaster.h"

SessionMaster::SessionMaster()
	: m_activeSession(nullptr) {
}

Session* SessionMaster::getActiveSession() const {
	if (m_activeSession == nullptr)
		throw SessionException("There is no active session");

	return m_activeSession;
}

void SessionMaster::switchSession(const int id) {
	if (m_activeSession != nullptr && m_activeSession->getId() == id)
		throw SessionException("Already in session with ID: " + std::to_string(id));

	for (std::vector<Session>::iterator session = m_sessions.begin(); session != m_sessions.end(); ++session) {
		if (session->getId() == id) {
			m_activeSession = &(*session);

			return;
		}
	}

	throw SessionException("Invalid Session Id");
}

void SessionMaster::addSession(const Session& session) {
	m_sessions.push_back(session);

	m_activeSession = &m_sessions[m_sessions.size() - 1];
}

void SessionMaster::closeActiveSession() {
	if (m_activeSession == nullptr)
		throw SessionException("There is no active session");

	size_t sessionIndex = getSessionIndex(m_activeSession);

	m_sessions.erase(m_sessions.begin() + sessionIndex);

	m_activeSession = m_sessions.size() == 0 ? nullptr : &m_sessions[0];
}

bool SessionMaster::checkIfFileAlreadyExists(std::string_view fileLocation) const {
	for (std::vector<Session>::const_iterator sessionIt = m_sessions.begin(); sessionIt != m_sessions.end(); ++sessionIt)
		if (sessionIt->containsFile(fileLocation))
			return true;
	
	return false;
}

size_t SessionMaster::getSessionIndex(const Session* const session) const {
	for (size_t index = 0; index < m_sessions.size(); ++index)
		if (m_sessions[index].getId() == session->getId())
			return index;

	throw SessionException("Session does not exist");
}
