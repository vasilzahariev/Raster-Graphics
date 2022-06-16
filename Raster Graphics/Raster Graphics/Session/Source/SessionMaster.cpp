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
