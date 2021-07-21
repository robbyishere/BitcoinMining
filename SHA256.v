/*
TODO:
	Learn how always blocks work
	How to use packed arrays?
	How to call functions?
*/
module hash;

reg [0:1023] ins;
reg [0:1] blockCount;
reg [31:0] binaryAdditionFunction [4:0];
integer i, j, k, m;

initial begin
    assign ins[0:607] = 608'h0100000050120119172a610421a6c3011dd330d9df07b63616c2cc1f1cd00200000000006657a9252aacd5c0b2940996ecff952228c3067cc38d4885efb5a4ac4247e9f337221b4d4c86041b;
    for(i=0; i<2; i=i+1) begin
	    $display("");
	    $display("Hash Step: ", i);
	    if(i == 0) begin
			assign ins[608:1023] = 416'b0;
			assign ins[640] = 1'b1;
			assign ins[1014] = 1'b1;
			assign ins[1016] = 1'b1;
			assign blockCount = 2;
			$display("%b", ins);
			assign ins[0:1023] = 1024'b0;
	    end

	    if(i == 1) begin
			assign ins[256:511] = 416'b1;
			assign ins[256] = 1'b1;
			assign ins[503] = 1'b1;
			assign blockCount = 1;
			$display("%b", ins);
			assign ins[0:1023] = 1024'b0;
		end
		for(j=0; j<blockCount; j=j+1)begin
			$display("Block: ", j);
			for(k=16; k<64; k=k+1)begin
			end
		end
	end
end
endmodule
