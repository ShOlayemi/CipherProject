module MD_CipherUser (
		input  wire        	Clk,
		input  wire        	Reset_n,
		input  wire [11:0] 	Cpu_Addr,
		input  wire        	Cpu_Sel,
		input  wire        	Cpu_Read,
		input  wire        	Cpu_Writ,
		input  wire [31:0] 	Cpu_DataWr,
		output wire [31:0] 	Cpu_DataRd
	);

	
	//-----Parameter	


	reg  [7:0]	KEY_TABLE[0:255];		// array of 256 bytes

	reg	 [3:0]		My_state;		// state machine state register
	reg 	 [7:0]	   Value;			// Value for data bus
	

	always @(posedge Clk, negedge Reset_n)
		begin
			if (Reset_n == 0) begin
				My_state <= 0; Value <= 5;
			end
			else begin

			end
		end

	endmodule	
	
		
			
			
		