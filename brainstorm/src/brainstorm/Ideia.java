package brainstorm;

import java.util.List;

/**
 * Classe que representa uma ideia da reunião.
 * 
 * @author mayradazevedo
 *
 */
public class Ideia {
	
	private String text;
	private User author;
	private List<User> voters;
	
	/**
	 * Representa a ação de um usuário votar na ideia.
	 * @param voter Usuário que votou na ideia
	 */
	public void vote(User voter) {
		
	}
	
	/**
	 * Representa a ação de um usuário retirar voto na ideia.
	 * @param voter Usuário que retira voto na ideia
	 */
	public void unvote(User voter) {
		
	}

}
