############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2014 Xilinx Inc. All rights reserved.
############################################################
set_directive_interface -mode bram "pid" read
set_directive_interface -mode bram "pid" write
set_directive_array_partition -type complete -dim 1 "pid" local_read
set_directive_array_partition -type complete -dim 1 "pid" local_write
set_directive_reset "pid" laste
set_directive_reset "pid" sum
set_directive_interface -mode ap_ctrl_hs "pid"
set_directive_interface -mode s_axilite "pid"
set_directive_unroll -factor 2 "pid/pid_label0"
