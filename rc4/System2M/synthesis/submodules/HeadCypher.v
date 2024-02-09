//----------------------------------------------------------------------------------
//
// MD_CipherIP.v
//
//----------------------------------------------------------------------------------

`timescale 1 ps / 1 ps
module MD_CipherIP
	(
		input  wire        Clk,				//   clk.clk
		input  wire        Reset_n,				//   rst.reset_n
		input  wire [11:0] Cpu_Addr,			// slave.address
		input  wire        Cpu_Sel,				//      .chipselect
		input  wire        Cpu_Read,			//      .read
		input  wire        Cpu_Writ,			//      .write
		input  wire [31:0] Cpu_DataWr,			//      .writedata
		output wire [31:0] Cpu_DataRd			//      .readdata
	);

	
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

	MD_CipherUser Cipher1 (
			.Clk 	(Clk),
			.Reset_n 	(Reset_n),
			.Cpu_Addr 	(Cpu_Addr),
			.Cpu_Sel 	(Cpu_Sel),
			.Cpu_Read 	(Cpu_Read),
			.Cpu_Writ 	(Cpu_Writ),
			.Cpu_DataWr (Cpu_DataWr),
			.Cpu_DataRd (Cpu_DataRd)
	);


endmodule
