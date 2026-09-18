parent1: parent1.c
	gcc parent1.c -o parent1

parent2: parent2.c
	gcc parent2.c -o parent2

parent3: parent3.c
	gcc parent3.c -o parent3

parent4: parent4.c
	gcc parent4.c -o parent4
child: child.c
	gcc child.c -o child

dup2_errno: dup2_errno.c
	gcc dup2_errno.c -o dup2_errno

run_parent1: parent1
	./parent1

run_parent2: parent2
	./parent2

run_parent3: parent3
	./parent3

run_parent4: parent4
	./parent4
run_child: child.c
	./child

run_dup2_errno: dup2_errno
	./dup2_errno