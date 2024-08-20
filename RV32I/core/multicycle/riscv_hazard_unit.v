
module riscv_hazard_unit(
    // Data Forwarding
    input   Rs1E,
    input   Rs2E,
    input   RdM,
    input   RdW,
    input   RegWriteM,
    input   RegWriteW,

    // Stalling 
    input   Rs1D,
    input   Rs2D,
    input   RdE,
    input   ResultSrcE0,

    // Control hazard flush
    input   PCSrcE,
    
    // Data Forwarding
    output  reg [1:0]   ForwardAE,
    output  reg [1:0]   ForwardBE,
    
    // Stalling
    output  reg StallF,
    output  reg StallD,
    output  reg FlushE,
    output  reg FlushD

);
wire    lwStall;

always @(*) begin
    if((Rs1E == RdM) && RegWriteM && (Rs1E != 0)) 
        ForwardAE = 2'b10;
    else if ((Rs1E == RdW) && RegWriteW && (Rs1E != 0)) 
        ForwardAE = 2'b01;
    else 
        ForwardAE = 2'b00;
end

always @(*) begin
    if((Rs2E == RdM) && RegWriteM && (Rs2E != 0)) 
        ForwardBE = 2'b10;
    else if ((Rs2E == RdW) && RegWriteW && (Rs2E != 0)) 
        ForwardBE = 2'b01;
    else 
        ForwardBE = 2'b00;
end


assign lwStall = ((Rs1D == RdE) || (Rs2D == RdE) && ResultSrcE0);

always @(*) begin
    StallF  = lwStall;
    StallD  = lwStall;
    FlushE  = lwStall || PCSrcE;
    FlushD  = PCSrcE;   
end

endmodule
