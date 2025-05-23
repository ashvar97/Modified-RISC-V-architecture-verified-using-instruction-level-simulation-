//==============================================================================
//
// The code is generated by Intel Compiler for SystemC, version 1.6.13
// see more information at https://github.com/intel/systemc-compiler
//
//==============================================================================

//==============================================================================
//
// Module: ieee754mult ()
//
module ieee754mult // "top"
(
    input logic [31:0] A,
    input logic [31:0] B,
    input logic reset,
    output logic [31:0] result
);

// Variables generated for SystemC signals
logic A_sign;
logic B_sign;
logic Sign;
logic [7:0] A_Exponent;
logic [7:0] B_Exponent;
logic [7:0] Temp_Exponent;
logic [23:0] A_Mantissa;
logic [23:0] B_Mantissa;
logic [47:0] Temp_Mantissa;


//------------------------------------------------------------------------------
// Child module instances

FloatingPointExtractor extractA
(
  .in(A),
  .reset(reset),
  .sign(A_sign),
  .exponent(A_Exponent),
  .mantissa(A_Mantissa)
);

FloatingPointExtractor extractB
(
  .in(B),
  .reset(reset),
  .sign(B_sign),
  .exponent(B_Exponent),
  .mantissa(B_Mantissa)
);

FloatingPointMultiplier multiply
(
  .A_Mantissa(A_Mantissa),
  .B_Mantissa(B_Mantissa),
  .A_Exponent(A_Exponent),
  .B_Exponent(B_Exponent),
  .A_sign(A_sign),
  .B_sign(B_sign),
  .reset(reset),
  .Temp_Mantissa(Temp_Mantissa),
  .Temp_Exponent(Temp_Exponent),
  .Sign(Sign)
);

FloatingPointNormalizer normalize
(
  .Temp_Mantissa(Temp_Mantissa),
  .Temp_Exponent(Temp_Exponent),
  .Sign(Sign),
  .reset(reset),
  .result(result)
);

endmodule



//==============================================================================
//
// Module: FloatingPointExtractor (example.cpp:113:5)
//
module FloatingPointExtractor // "top.extractA"
(
    input logic [31:0] in,
    input logic reset,
    output logic sign,
    output logic [7:0] exponent,
    output logic [23:0] mantissa
);

//------------------------------------------------------------------------------
// Method process: extract (example.cpp:16:5) 

always_comb 
begin : extract     // example.cpp:16:5
    if (reset)
    begin
        sign = 0;
        exponent = 0;
        mantissa = 0;
    end else begin
        sign = in[31];
        exponent = in[30 : 23];
        mantissa = (24'd1 <<< 23) | in[22 : 0];
    end
end

endmodule



//==============================================================================
//
// Module: FloatingPointMultiplier (example.cpp:115:5)
//
module FloatingPointMultiplier // "top.multiply"
(
    input logic [23:0] A_Mantissa,
    input logic [23:0] B_Mantissa,
    input logic [7:0] A_Exponent,
    input logic [7:0] B_Exponent,
    input logic A_sign,
    input logic B_sign,
    input logic reset,
    output logic [47:0] Temp_Mantissa,
    output logic [7:0] Temp_Exponent,
    output logic Sign
);

//------------------------------------------------------------------------------
// Method process: multiply (example.cpp:47:5) 

always_comb 
begin : multiply     // example.cpp:47:5
    if (reset)
    begin
        Temp_Mantissa = 0;
        Temp_Exponent = 0;
        Sign = 0;
    end else begin
        Temp_Mantissa = A_Mantissa * B_Mantissa;
        Temp_Exponent = A_Exponent + B_Exponent - 127;
        Sign = A_sign ^ B_sign;
    end
end

endmodule



//==============================================================================
//
// Module: FloatingPointNormalizer (example.cpp:116:5)
//
module FloatingPointNormalizer // "top.normalize"
(
    input logic [47:0] Temp_Mantissa,
    input logic [7:0] Temp_Exponent,
    input logic Sign,
    input logic reset,
    output logic [31:0] result
);

//------------------------------------------------------------------------------
// Method process: normalize (example.cpp:73:5) 

always_comb 
begin : normalize     // example.cpp:73:5
    logic [22:0] Mantissa;
    logic [7:0] Exponent;
    Mantissa = 0;
    Exponent = 0;
    if (reset)
    begin
        result = 0;
    end else begin
        Mantissa = 0;
        Exponent = 0;
        if (Temp_Mantissa[47])
        begin
            Mantissa = Temp_Mantissa[46 : 24];
            Exponent = Temp_Exponent + 1;
        end else begin
            Mantissa = Temp_Mantissa[45 : 23];
            Exponent = Temp_Exponent;
        end
        result = {Sign, Exponent, Mantissa};
    end
end

endmodule


