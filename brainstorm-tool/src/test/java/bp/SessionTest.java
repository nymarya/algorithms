package bp;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

/**
 * SessionTest
 */
public class SessionTest {
  User[] users = {
    new User("Fulano"),
    new User("Cicrano"),
    new User("Beltrano"),
    new User("Pessoa")
  };
  Session session = new Session(users[0], "");

  @Before
  public void setUp() {
    User u = new User("Fulano");
    this.session = new Session(users[0], "");    
  }

  /**
   * Na criação de um objeto
   */
  @Test
  public void creation() {
	  
	  // O proprietário deve ser o mesmo que foi passado em sua criação
	  assertEquals(users[0], session.getOwner());
	  
	  // Ela deve se encontrar na fase de acolhimento
	  assertEquals(SessionPhase.WELCOME, session.getPhase());
	  
	  // As lista de ideias e de participantes deve estar vazia
	  assertEquals(0, session.getIdeas().size());
	  assertEquals(0, session.getParticipants().size());
  }

  /**
   * Muda a fase da sessão
   */
  @Test
  public void nextPhase() {
	  
	  SessionPhase previousPhase = session.getPhase();
	  session.nextPhase();
	  
	  SessionPhase currentPhase = session.getPhase();
	  
	  // Se estiver na fase de acolhimento, passa para brainstorm
	  if( previousPhase.equals(SessionPhase.WELCOME) ) {
		  assertEquals( SessionPhase.BRAINSTORM, currentPhase);
	  }
	  
	  previousPhase = session.getPhase();
	  session.nextPhase();
	  
	  currentPhase = session.getPhase();
	  
	  
	  // Se estiver na fase de brainstorm, passa para votação
	  if( previousPhase.equals(SessionPhase.BRAINSTORM) ) {
		  assertEquals( SessionPhase.VOTING, currentPhase);
	  }
	  
	  previousPhase = session.getPhase();
	  session.nextPhase();
	  
	  currentPhase = session.getPhase();
	  
	  // Se estiver na fase de votação, passa para encerramento
	  if( previousPhase.equals(SessionPhase.VOTING) ) {
		  assertEquals( SessionPhase.RANK, currentPhase);
	  }
	  
	  previousPhase = session.getPhase();
	  session.nextPhase();
	  
	  currentPhase = session.getPhase();
	  
	  // Se estiver na fase de encerramento, não ocorre nada
	  if( previousPhase.equals(SessionPhase.RANK) ) {
		  assertEquals( SessionPhase.RANK, currentPhase);
	  }
	  
  }

  @Test
  public void addParticipant() {
	  
	  session = new Session(users[0], "" );
	  
	  // Se fase for de acolhimento e usuário ainda não é participante, adiciona
	  session.addParticipant(users[1]);
	  assertEquals( 1, session.getParticipants().size() );
	  assertTrue( session.getParticipants().contains(users[1]));
	  
	  session.addParticipant(users[2]);
	  assertEquals( 2, session.getParticipants().size() );
	  assertTrue( session.getParticipants().contains(users[2]));
	  
	  // A lista de participantes não muda se o usuário já for participante
	  session.addParticipant(users[1]);
	  assertEquals( 2, session.getParticipants().size() );
	  
	  // A lista de participantes não muda se a sessão não estiver na fase de acolhimento
	  session.nextPhase();
	  session.addParticipant(users[3]);
	  assertEquals( 2, session.getParticipants().size() );
	  
	  
  }
  
  /**
   * Remove participante
   */
  @Test
  public void removeParticipant() {
	  
	  
	  // Se usuário não é participante, a lista permanece a mesma
	  session.removeParticipant(users[3]);
	  assertEquals( 2, session.getParticipants().size() );
	  
	  
	  // Remove se usuário é participante 
	  session.removeParticipant(users[1]);
	  assertEquals( 1, session.getParticipants().size() );
	  assertTrue( !session.getParticipants().contains(users[1]));
	  
	  // Remove se usuário é participante 
	  session.removeParticipant(users[2]);
	  assertEquals( 0, session.getParticipants().size() );
	  assertTrue( !session.getParticipants().contains(users[2]));
	  
  }
}