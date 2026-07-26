transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -sv -work work +incdir+C:/Users/Rahul/Documents/ENTC\ S5/Digital\ System\ Design/Single\ Bus\ Architecture {C:/Users/Rahul/Documents/ENTC S5/Digital System Design/Single Bus Architecture/special_regs.sv}
vlog -sv -work work +incdir+C:/Users/Rahul/Documents/ENTC\ S5/Digital\ System\ Design/Single\ Bus\ Architecture {C:/Users/Rahul/Documents/ENTC S5/Digital System Design/Single Bus Architecture/reg_file.sv}
vlog -sv -work work +incdir+C:/Users/Rahul/Documents/ENTC\ S5/Digital\ System\ Design/Single\ Bus\ Architecture {C:/Users/Rahul/Documents/ENTC S5/Digital System Design/Single Bus Architecture/cpu.sv}
vlog -sv -work work +incdir+C:/Users/Rahul/Documents/ENTC\ S5/Digital\ System\ Design/Single\ Bus\ Architecture {C:/Users/Rahul/Documents/ENTC S5/Digital System Design/Single Bus Architecture/control_unit.sv}
vlog -sv -work work +incdir+C:/Users/Rahul/Documents/ENTC\ S5/Digital\ System\ Design/Single\ Bus\ Architecture {C:/Users/Rahul/Documents/ENTC S5/Digital System Design/Single Bus Architecture/bus_mux.sv}
vlog -sv -work work +incdir+C:/Users/Rahul/Documents/ENTC\ S5/Digital\ System\ Design/Single\ Bus\ Architecture {C:/Users/Rahul/Documents/ENTC S5/Digital System Design/Single Bus Architecture/alu.sv}

vlog -sv -work work +incdir+C:/Users/Rahul/Documents/ENTC\ S5/Digital\ System\ Design/Single\ Bus\ Architecture {C:/Users/Rahul/Documents/ENTC S5/Digital System Design/Single Bus Architecture/tb_cpu.sv}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  tb_cpu

add wave *
view structure
view signals
run -all
