echo "New implementation"
time ./new_generic.sh $1 /dev/null
echo "Old implementation"
time ./old_generic.sh $1 /dev/null
