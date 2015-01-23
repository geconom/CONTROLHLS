############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2014 Xilinx Inc. All rights reserved.
############################################################
set_directive_inline "float_abs"
set_directive_inline "float_rsh1"
set_directive_interface -mode bram "flc" read
set_directive_interface -mode bram "flc" write
set_directive_reset "flc" lastde
set_directive_array_partition -type complete -dim 1 "flc" local_read
set_directive_array_partition -type complete -dim 1 "flc" local_write
set_directive_interface -mode ap_ctrl_hs "flc"
set_directive_interface -mode s_axilite "flc"
set_directive_unroll -factor 2 "flc/flc_label1"
