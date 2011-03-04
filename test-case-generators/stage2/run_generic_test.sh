echo "New implementation"
time ./new_generic.sh $1 $2
echo "Old implementation"
time ./old_generic.sh $1 $2
