/**
 * The Instruction class represents a Instruction object. 
 * Information about the instruction is stored and can be retrieved.
 * 
 * @author Mayra Dantas de Azevedo
 *
 */


public class Instruction {

	private int opcode;
	private int OF1;
	private int OF2;
	private int OF3;
	private int OD;
	
	/**
	 * Get the opcode
	 * @return The opcode
	 */
	public int getOpcode() {
		return opcode;
	}
	
	/**
	 * Update opcode
	 * @param opcode The opcode to set
	 */
	public void setOpcode(int opcode) {
		this.opcode = opcode;
	}
	
	/**
	 * Get the OF1
	 * @return The OF1
	 */
	public int getOF1() {
		return OF1;
	}
	
	/**
	 * Update OF1
	 * @param oF1 The OF1 to set
	 */
	public void setOF1(int oF1) {
		OF1 = oF1;
	}
	
	/**
	 * Get the OF2
	 * @return The OF2
	 */
	public int getOF2() {
		return OF2;
	}
	
	/**
	 * Update OF2
	 * @param oF2 The OF2 to set
	 */
	public void setOF2(int oF2) {
		OF2 = oF2;
	}
	
	/**
	 * Get the OF3
	 * @return The OF3
	 */
	public int getOF3() {
		return OF3;
	}
	
	/**
	 * Update OF3
	 * @param oF3 The OF3 to set
	 */
	public void setOF3(int oF3) {
		OF3 = oF3;
	}
	
	/**
	 * Get the OD
	 * @return The OD
	 */
	public int getOD() {
		return OD;
	}
	
	/**
	 * Update OD
	 * @param oD The OD to set
	 */
	public void setOD(int oD) {
		OD = oD;
	}
	
	
}
