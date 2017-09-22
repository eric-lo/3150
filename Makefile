SUBDIRS = 1-c/program \
    1-c/multiple_file \
    2a-processbasic \
	2b-processinkernel \
	2e-pthread \
	3-fs \
	4a-memory-user \
	4b-memory-kernel \


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
