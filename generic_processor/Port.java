/**
 * The Port class represents a Port object. 
 * A port define the communication between components.
 * 
 * @author Mayra D. de Azevedo
 *
 */


public class Port {

	private Signal signal;

	/**
	 * Default constructor
	 * @param signal
	 */
	public Port(Signal signal) {
		super();
		this.signal = signal;
	}
	
	public void read() {
		
	}
	
	public void write() {
		
	}
	
	public void setEvent( boolean event) {
		signal.setEvent(event);
	}
}
