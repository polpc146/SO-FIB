all: mem1_dynamic mem2 mem1_static mem1_v2 mem1_v3 mem2_v2

mem1_dynamic: mem1.c
	gcc -o mem1_dynamic mem1.c

mem2: mem2.c
	gcc -o mem2 mem2.c

mem1_static: mem1.c
	gcc -static -o mem1_static mem1.c

mem1_v2: mem1_v2.c
	gcc -o mem1_v2 mem1_v2.c

mem1_v3: mem1_v3.c
	gcc -o mem1_v3 mem1_v3.c

mem2_v2: mem2_v2.c
	gcc -o mem2_v2 mem2_v2.c

clean:
	rm -f *.o mem1_dynamic mem2 mem1_static mem1_v2 mem1_v3 mem2_v2

