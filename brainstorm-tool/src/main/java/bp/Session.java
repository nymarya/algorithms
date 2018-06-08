package bp;

import java.util.List;

/**
 * Session
 */
public class Session {

	User owner;
	String description;
	SessionPhase phase;
	int votingLimit = 3;
	List<Idea> ideas;
	List<User> participants;
	
	/**
	 * 
	 * @param owner
	 */
	public Session(User owner, String description) {
	}

	public SessionPhase nextPhase() {
		return null;
	}

	public SessionPhase getPhase() {
		return null;
	}

	public boolean addIdea(Idea idea) {
		return false;
	}

	public List<Idea> getIdeas() {
		return null;
	}

	public List<Idea> rankIdeas() {
		return null;
	}

	public boolean addParticipant(User participant) {
		return false;
	}

	public boolean removeParticipant(User participant) {
		return false;
	}

	public List<User> getParticipants() {
		return null;
	}

	public User getOwner() {
		return owner;
	}

	public void setOwner(User owner) {
		this.owner = owner;
	}

}