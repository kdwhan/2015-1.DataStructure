# input
rm -f a.exe
src=$1;
in=$2;
expout=$3;

# show the inputs
#echo "Input in the file" $in
#cat $in
#echo "Expected Output in the file " $expout
#cat $expout
echo ""

# compile the source
cp $src lab.hpp
g++ -o a.exe -Wall main.cpp 

# run the program
./a.exe < $in > $src.oo

# check the difference between the output and the expected output
diff -i --strip-trailing-cr -w $src.oo $expout > $src.diff

# show the result
test $? -ne 0 && echo "Fail : $1" || echo "Success : $1"

