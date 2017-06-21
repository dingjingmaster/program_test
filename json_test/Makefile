CC = gcc


objs = ./src/cJSON.o 						\
			 ./test/json_test_main.o

# 	数学库
libs = -lm


target = json_test


$(target) : $(objs)
	$(CC) -o $@ $^ $(libs)

%.o : %.c
	$(CC) -o $@ -c $<


.PHONY : clean

clean:
	rm -fr $(objs)
	rm -fr $(target)
	clear

