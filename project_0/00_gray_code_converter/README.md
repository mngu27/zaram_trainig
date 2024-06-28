# Gray Code Converter
## Operation Principle
- Consecutive numbers differ in only one bit position
- Bin -> Gray
	- G[N-1] 	= B[N-1]
	- G[i]		= B[i+1] ^ B[i] (N-1>i>=G0)

- Gray -> Bin
	- B[N-1] 	= G[N-1]
	- B[i]		= B[i+1] ^ G[i] (N-1>i>=0)

## Verilog Code
### DUT
```verilog
	module gray_to_bin
	(
	input	[2:0]	i_data,
	output	[2:0]	o_data
	);


	assign o_data[0] = o_data[1] ^ i_data[0];
	assign o_data[1] = o_data[2] ^ i_data[1];
	assign o_data[2] = i_data[2];

	endmodule
```

