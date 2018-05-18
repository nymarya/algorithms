package test;

import java.util.ArrayList;
import java.util.List;

import brainstorm.StormConfig;
import brainstorm.StormSession;
import brainstorm.User;

public class Tests {

	public static void main(String[] args) {
		

		//Teste 1: instaciação
		User userRachel = new User("rachel.green", "Rachel Green", "https://photo.com");
		User userMonica = new User("monica.geller", "Monica Geller", "https://photo.com");
		User userPhoebe = new User("phoebe.buffay", "Phoebe Buffay", "https://photo.com");

		List<User> participantes = new ArrayList<User>();
		participantes.add(userPhoebe);
		participantes.add(userMonica);
		participantes.add(userRachel);
				
				
		StormConfig config = new StormConfig(false, 6);
		
		StormSession session = new StormSession("Decidir quem fica com o apartamento",
				"Ideias de como decidir", config, userMonica, participantes);

	}

}
