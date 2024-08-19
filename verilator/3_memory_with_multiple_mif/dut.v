// ---------------------------------------------------
// RISC-V Integer Bit & Memory Specification
// ---------------------------------------------------
`define XLEN			32 
`define DMEM_ADDR_BIT	10
`define IMEM_ADDR_BIT	10
`define DMEM_INIT

module dut(
	input							i_clk,
	input							i_dmem_wr_en,
	input	[`DMEM_ADDR_BIT-3:0]	i_dmem_addr,
	input	[		  `XLEN-1:0]	i_dmem_data,
	input	[		`XLEN/8-1:0]	i_dmem_byte_sel,
	output	[		  `XLEN-1:0]	o_dmem_data
);

	reg		[`XLEN-1:0]	dmem_arr[0:2**(`DMEM_ADDR_BIT-2)-1];

`ifdef	DMEM_INIT
	reg	[8*32-1:0]	FILE_DATA_MIF;
	initial begin
		$value$plusargs("data_mif=%s", FILE_DATA_MIF);
		$readmemh(FILE_DATA_MIF, dmem_arr);
	end 
`endif

	// Memory Read(Output is not switching during write)
	assign o_dmem_data = dmem_arr[i_dmem_addr];

	// Memory Write(to support sb, sh, sw)
	// i_dmem_byte_sel = sb:4'b0001, sh:4'b0011, sw:4'b1111
	integer		i;
	always @(posedge i_clk) begin
		if(i_dmem_wr_en) begin
			for(i = 0; i <`XLEN/8; i++) begin
				if(i_dmem_byte_sel[i]) begin
					dmem_arr[i_dmem_addr][8*i+:8] <= i_dmem_data[8*i+:8];
				end 
			end 
		end
		else begin
			dmem_arr[i_dmem_addr] <= dmem_arr[i_dmem_addr];
		end 
	end

endmodule


