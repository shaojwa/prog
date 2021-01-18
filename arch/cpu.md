# read mode and protect mode
#### 8086, 1978, add read-mode, linear space = 1M)
1. linear adress is 20bit = segment_reg(16bit) << 4 + offset_bit

#### 80286, 1982, virtual memory and memory protection
1. segment base is 24bit
1. offset is 16bit
1. linear_adress is 24bit = LDT[seg_reg(16bit)](24bit) + 0ffset_bit
1. LDT, local discriptor table, item = linear_address_base + limit

#### 80386, 1985, add FS/GS
1. paging unit has been added as a second layer of address translation between the segmentation unit and the physical bus.
1. segment base is 32bit
1. offset is 32bit
1. linear_address is 32bit
1. The paging unit may be enabled or disabled; 


#### what is preserved across function calls
http://www.x86-64.org/documentation/abi.pdf (page 20)
