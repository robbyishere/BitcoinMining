/*
TODO:
	Learn how always blocks work
	How to work with arrays
	How to call functions
*/
module hash;

reg [0:1023] ins;
reg [0:31] ins_Split [0:64];
reg [0:1] blockCount;
reg [31:0] binaryAddition [4:0];
integer i, j, k, m, temp;

initial begin
    assign ins[0:607] = 608'h0100000050120119172a610421a6c3011dd330d9df07b63616c2cc1f1cd00200000000006657a9252aacd5c0b2940996ecff952228c3067cc38d4885efb5a4ac4247e9f337221b4d4c86041b;
    for(i=0; i<2; i=i+1) begin
		$display("");
		$display("Hash Step: ", i);
		//Initialize block
		if(i == 0) begin
			ins[608:1023] = 416'b0;
			ins[640] = 1'b1;
			ins[1014] = 1'b1;
			ins[1016] = 1'b1;
			blockCount = 2;
			$display("%b", ins);
			ins[0:1023] = 1024'b0;
		end
		if(i == 1) begin
			ins[256:511] = 416'b1;
			ins[256] = 1'b1;
			ins[503] = 1'b1;
			blockCount = 1;
			$display("%b", ins);
			ins[0:1023] = 1024'b0;
		end
		//Initialize message schedule
		for(j=0; j<64; j=j+1)begin
		end
		for(j=0; j<blockCount; j=j+1)begin
			$display("Block: ", j);
			for(k=16; k<64; k=k+1)begin
				//temp = (9*32)+((k-16)*32);
				//binaryAddition[1] = ins[temp:temp+32];
				//$display("binaryAddition[1]: %b", binaryAddition[1]);
			end
		end
	end
end
endmodule
