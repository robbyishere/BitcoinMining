/*
TODO:
	Learn how always blocks work
	Learn difference between Functions, Tasks, and Modules


Idea when calling equationCompute
 - Needs to be a module in order to pass parameters
 - Parameters are defined during the call
 - Parameters are the shift/right shift values (populateShiftValues can be removed)
 - Parameters can be passed down to shift and right shift modules

*/
module hash;
reg [0:1023] ins;
reg [0:31] ins_Split [0:1] [0:63];
reg [0:1] blockCount;
reg [0:31] binaryAddition [0:4];
integer i, j, k, m, n;
//equationCompute variables
reg [0:31] equationComputeData[0:3];
reg [2:0] equationNumber;
reg [5:0] wordNumber;
reg [1:0] blockNumber;
//shiftValues variables
reg [0:4] shiftValues [0:3] [0:2];
initial begin
    ins[0:607] = 608'h0100000050120119172a610421a6c3011dd330d9df07b63616c2cc1f1cd00200000000006657a9252aacd5c0b2940996ecff952228c3067cc38d4885efb5a4ac4247e9f337221b4d4c86041b;
    $display(populateShiftValues(1));
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
			ins[256:511] = 256'b0;
			ins[256] = 1'b1;
			ins[503] = 1'b1;
			blockCount = 1;
			$display("%b", ins[0:511]);
		end
		for(j=0; j<blockCount; j=j+1)begin
			$display("Block: ", j);

			//Split block into 16, 32 bit words
			for(k=0; k<16; k=k+1)begin
				ins_Split[j][k] = ins[(32*k)+(512*j)+:32];
				$display("%b", ins_Split[j][k]);
			end
			
			$display(" ");
			//Fill out rest of message schedule
			for(k=16; k<17; k=k+1)begin
				binaryAddition[0] = equationCompute(1, k-2, j);
				binaryAddition[1] = ins_Split[j][k-7];
				binaryAddition[2] = equationCompute(0, k-15, j);
				binaryAddition[3] = ins_Split[j][k-16];
				//$display("%b", binaryAddition[0]);
			end
		end
	end
end
function [31:0] equationCompute;
	input [2:0] equationNumber;
	input [5:0] wordNumber;
	input [1:0] blockNumber;
begin
	for(m=0; m<2; m=m+1)begin
		$display(rightShift(shiftValues[equationNumber][m], m, equationNumber, wordNumber, blockNumber));
	end
end
endfunction

//May be able to improve instead of checking bits individually?
function rightShift;
	input [4:0] RightShiftValue;
	input [1:0] Order;
	input [2:0] equationNumber;
	input [5:0] wordNumber;
	input [1:0] blockNumber;
	reg [31:0] Copy;
	reg [31:0] rightCopy;
	begin
		if(equationNumber == 0 | equationNumber == 1)begin
			Copy = ins_Split[blockNumber][wordNumber];
		end
		if(equationNumber == 2)begin
		end
		if(equationNumber == 3)begin
		end
		for(n=0; n<RightShiftValue; n=n+1)begin
			rightCopy[(32-RightShiftValue)+n] = Copy[n];
		end
		for(n=0; n<32-RightShiftValue; n=n+1)begin
			rightCopy[(31-RightShiftValue)-n] = 0;
		end
		equationComputeData[Order] = (Copy>>RightShiftValue) + rightCopy;
		$display(Order," %b", equationComputeData[Order]);
		rightShift = 1;
	end
endfunction

//Try and make this globally accessible for multiple hashing instances
function populateShiftValues;
	input null; //functions need to have at least one input
begin
	shiftValues[0][0] = 7;
	shiftValues[0][1] = 18;
	shiftValues[0][2] = 3;
	shiftValues[1][0] = 17;
	shiftValues[1][1] = 19;
	shiftValues[1][2] = 10;
	shiftValues[2][0] = 2;
	shiftValues[2][1] = 13;
	shiftValues[2][2] = 22;
	shiftValues[3][0] = 6;
	shiftValues[3][1] = 11;
	shiftValues[3][2] = 25;
end
endfunction
endmodule
