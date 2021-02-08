CC=gcc

ll.exe: main.o linkedlist.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $<

clean:
	rm *.o out.exe
