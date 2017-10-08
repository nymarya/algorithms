/**
 * The IMem class represents a IMem object. 
 * IMem references to the instructions in the memory.
 * 
 * @author Mayra D. de Azevedo
 *
 */
package domain;


public class IMEM {

	private Port read;
	private Instruction mem[];
	
	/**
	 * 
	 */
	public void read() {
		
	}

	/**
	 * Get the read
	 * @return The read
	 */
	public Port getRead() {
		return read;
	}

	/**
	 * Update read
	 * @param read The read to set
	 */
	public void setRead(Port read) {
		this.read = read;
	}

	/**
	 * Get the mem
	 * @return The mem
	 */
	public Instruction[] getMem() {
		return mem;
	}

	/**
	 * Update mem
	 * @param mem The mem to set
	 */
	public void setMem(Instruction[] mem) {
		this.mem = mem;
	}
	
}
