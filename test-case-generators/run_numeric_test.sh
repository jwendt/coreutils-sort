echo "New implementation"
time ./new_numeric.sh $1 /dev/null
echo "Old implementation"
time ./old_numeric.sh $1 /dev/null
