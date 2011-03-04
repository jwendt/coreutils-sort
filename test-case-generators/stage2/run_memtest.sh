#!/bin/bash
case $1 in
-g)
	valgrind --tool=massif --massif-out-file=g.new.out.%p \
	../stage1/new_generic.sh $2
	valgrind --tool=massif --massif-out-file=g.old.out.%p \
	../stage1/old_generic.sh $2
	;;
-n)
	valgrind --tool=massif --massif-out-file=n.new.out.%p \
	../stage1/new_numeric.sh $2
	valgrind --tool=massif --massif-out-file=n.old.out.%p \
	../stage1/old_numeric.sh $2
	;;
-h)
	valgrind --tool=massif --massif-out-file=h.new.out.%p \
	../stage1/new_human.sh $2
	valgrind --tool=massif --massif-out-file=h.old.out.%p \
	../stage1/old_human.sh $2
	;;
*)
	exit
	;;
esac
