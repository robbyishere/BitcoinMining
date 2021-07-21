/*
TODO:
	Learn how always blocks work
	How to call functions
	Make Right Shift wrap
*/
module hash;

reg [0:1023] ins;
reg [0:31] ins_Split [0:63];
reg [0:1] blockCount;
reg [0:31] binaryAddition [0:4];
integer i, j, k, m;

initial begin
    ins[0:607] = 608'h0100000050120119172a610421a6c3011dd330d9df07b63616c2cc1f1cd00200000000006657a9252aacd5c0b2940996ecff952228c3067cc38d4885efb5a4ac4247e9f337221b4d4c86041b;
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
		end
		if(i == 1) begin
			ins[256:511] = 416'b0;
			ins[256] = 1'b1;
			ins[503] = 1'b1;
			blockCount = 1;
			$display("%b", ins[0:511]);
		end
		for(j=0; j<blockCount; j=j+1)begin
			$display("Block: ", j);

			//Split block into 16, 32 bit words
			for(k=0; k<16; k=k+1)begin
				ins_Split[k] = ins[32*k+:32];
				$display("%b", ins_Split[k]);
			end
			
			$display(" ");
			//Fill out rest of message schedule
			for(k=16; k<64; k=k+1)begin
				binaryAddition[1] = ins_Split[k-7];
				binaryAddition[3] = ins_Split[k-16];
				//$display("%b", binaryAddition[3]);
			end
			
			
		end
	end
end
endmodule
