echo "New implementation"
time ./new_human.sh $1 /dev/null
echo "Old implementation"
time ./old_human.sh $1 /dev/null
