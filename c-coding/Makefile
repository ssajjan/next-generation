TARGET = ISR

KDIR = /lib/modules/3.13.0-49-generic/build/
PWD := $(shell pwd)

obj-m += $(TARGET).o

can-objs := ISR.o

default:
	make -C $(KDIR) M=$(PWD) modules
