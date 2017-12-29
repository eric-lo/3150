SUBDIRS = 3-ProcessUser \
	4-ProcessKernel \
	5-Signal \
	6-Memory \
	7-Threading \
	8-Synchronization \
	9-File \
	12-VirtualMemory \


all:
	for dir in $(SUBDIRS) ; \
	do \
		make -C $$dir; \
	done


clean:
	for dir in $(SUBDIRS) ; \
	do \
		make -C $$dir clean; \
	done
