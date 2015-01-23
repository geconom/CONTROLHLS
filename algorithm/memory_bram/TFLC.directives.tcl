############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2014 Xilinx Inc. All rights reserved.
############################################################
set_directive_inline "float_abs"
set_directive_inline "float_rsh1"
set_directive_inline "float_lsh1"
set_directive_interface -mode bram "tflc" read
set_directive_interface -mode bram "tflc" write
set_directive_reset "tflc" lastde
set_directive_reset "tflc" lasty
set_directive_reset "tflc" lastu
set_directive_interface -mode ap_ctrl_hs "tflc"
set_directive_interface -mode s_axilite "tflc"
