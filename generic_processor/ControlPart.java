/**
 * The ControlPart class represents a ControlPart object. 
 * The control part coordinates the sequence of data movements into, out of, 
 * and between a processor's many sub-parts.
 * 
 * @author Mayra D. de Azevedo
 *
 */
package domain;

public class ControlPart {

	private Port IMem;
	private Instruction RI;
	private int CP;
	
	
	/**
	 * Decode.
	 */
	public void decoder(){
		
	}
	
	/**
	 * Read instruction.
	 */
	public void readInst() {
		
	}
	
	/**
	 * Finite state machine.
	 */
	public void FSM() {
		
	}
	
	/**
	 * 
	 */
	public void microInst() {
		
	}

	/**
	 * Get the IMem
	 * @return The IMem
	 */
	public Port getIMem() {
		return IMem;
	}

	/**
	 * Update IMem
	 * @param iMem The IMem to set
	 */
	public void setIMem(Port iMem) {
		IMem = iMem;
	}

	/**
	 * Get the RI
	 * @return The RI
	 */
	public Instruction getRI() {
		return RI;
	}

	/**
	 * Update RI
	 * @param rI The RI to set
	 */
	public void setRI(Instruction rI) {
		RI = rI;
	}

	/**
	 * Get the CP
	 * @return The CP
	 */
	public int getCP() {
		return CP;
	}

	/**
	 * Update CP
	 * @param cP The CP to set
	 */
	public void setCP(int cP) {
		CP = cP;
	}
	
	
}
