package bp;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

/**
 * IdeaTest
 */
public class IdeaTest {
  Idea idea;
  User user1, user2;

  @Before
  public void setUp() {
    user1 = new User("fulano");
    user2 = new User("cicrano");
    this.idea = new Idea(user1, "An idea");
  }

  @Test
  public void countVotes() {
  }

  @Test
  public void shouldConsiderVote() {
  }
  
}