echo "Compiling the program....."
echo "gcc Driver.c Sort.c"
gcc Driver.c Sort.c
echo "Program compiled successfully!"
echo "Starting program execution....."
echo "./a.out" 
echo
./a.out
echo
echo "Graphing out the results....."
echo 'python3 plot.py "Element-to-Element-Comparisons-Only" 0'
python3 plot.py "Element-to-Element-Comparisons-Only" 0