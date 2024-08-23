`ifndef		NOINC
`include	"riscv_configs.v"
`endif


module riscv_dmem(
	input							i_clk,
	input							i_dmem_wr_en,
	input	[  		  `XLEN-1:0]	i_dmem_data,
	input	[`DMEM_ADDR_BIT-3:0]	i_dmem_addr,
	input	[  		`XLEN/8-1:0]	i_dmem_byte_sel,
	output	[  		  `XLEN-1:0]	o_dmem_data
);
	reg		[`XLEN-1:0]	dmem_arr[0:2**(`DMEM_ADDR_BIT-2)-1];

`ifdef	DMEM_INIT
	reg	[8*128-1:0] FILE_DATA_MIF;
	initial	begin
		$value$plusargs("data_mif=%s", FILE_DATA_MIF);
		$readmemh(FILE_DATA_MIF, dmem_arr);
	end
`endif

//`ifdef	DMEM_INIT
//	initial		$readmemh(`DMEM_INIT_FILE, dmem_arr);
//`endif

	//Memory Read(output is not switching during write)
	assign		o_dmem_data = (i_dmem_wr_en) ? o_dmem_data : dmem_arr[i_dmem_addr];

	//Memory Write(to distinguish sb, sh, sw)
	integer i;
	always @(posedge i_clk) begin
		if(i_dmem_wr_en) begin
			for(i = 0; i < `XLEN/8; i = i+1) begin
				if(i_dmem_byte_sel[i]) begin
					dmem_arr[i_dmem_addr][8*i+:8] <= i_dmem_data[8*i+:8];
				end
			end 
		end 
		else begin
			dmem_arr[i_dmem_addr]	<= dmem_arr[i_dmem_addr];
		end 
	end 

endmodule
