package brainstorm;

import java.util.ArrayList;
import java.util.List;

/**
 * Representa a sessão de uma reunião.
 * 
 * @author mayradazevedo
 *
 */
public class StormSession {

	
	private String goal;
	private String description;
	private StormConfig config;
	private User owner;
	private ArrayList<User> participants;
	
	public StormSession(String goal, String description, StormConfig config, User owner, 
			List<User> participants) {
		// TODO Auto-generated constructor stub
	}
}
