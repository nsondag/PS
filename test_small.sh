echo "----1 number-----"

./push_swap 2 | ./checker 2
./push_swap 2 | wc -l

echo "----2 numbers----"

./push_swap 1 2 | ./checker 1 2
./push_swap 1 2 | wc -l

./push_swap 2 1 | ./checker 2 1
./push_swap 2 1 | wc -l

echo "----3 numbers----"

./push_swap 1 2 3 | ./checker 1 2 3
./push_swap 1 2 3 | wc -l

./push_swap 1 3 2 | ./checker 1 3 2
./push_swap 1 3 2 | wc -l

./push_swap 2 3 1 | ./checker 2 3 1
./push_swap 2 3 1 | wc -l

./push_swap 2 1 3 | ./checker 2 1 3
./push_swap 2 1 3 | wc -l

./push_swap 3 1 2 | ./checker 3 1 2
./push_swap 3 1 2 | wc -l

./push_swap 3 2 1 | ./checker 3 2 1
./push_swap 3 2 1 | wc -l

echo "----4 numbers----"

./push_swap 2 3 4 5 | ./checker 2 3 4 5
./push_swap 2 3 4 5 | wc -l

./push_swap 2 3 5 4 | ./checker 2 3 5 4
./push_swap 2 3 5 4 | wc -l

./push_swap 2 4 3 5 | ./checker 2 4 3 5
./push_swap 2 4 3 5 | wc -l

./push_swap 2 4 5 3 | ./checker 2 4 5 3
./push_swap 2 4 5 3 | wc -l

./push_swap 2 5 3 4 | ./checker 2 5 3 4
./push_swap 2 5 3 4 | wc -l

./push_swap 2 5 4 3 | ./checker 2 5 4 3
./push_swap 2 5 4 3 | wc -l

./push_swap 3 2 4 5 | ./checker 3 2 4 5 
./push_swap 3 2 4 5 | wc -l

./push_swap 3 2 5 4 | ./checker 3 2 5 4
./push_swap 3 2 5 4 | wc -l

./push_swap 3 4 2 5 | ./checker 3 4 2 5
./push_swap 3 4 2 5 | wc -l

./push_swap 3 4 5 2 | ./checker 3 4 5 2
./push_swap 3 4 5 2 | wc -l

./push_swap 3 5 2 4 | ./checker 3 5 2 4
./push_swap 3 5 2 4 | wc -l

./push_swap 3 5 4 2 | ./checker 3 5 4 2
./push_swap 3 5 4 2 | wc -l

./push_swap 4 2 3 5 | ./checker 4 2 3 5
./push_swap 4 2 3 5 | wc -l

./push_swap 4 2 5 3 | ./checker 4 2 5 3
./push_swap 4 2 5 3 | wc -l

./push_swap 4 3 2 5 | ./checker 4 3 2 5
./push_swap 4 3 2 5 | wc -l

./push_swap 4 3 5 2 | ./checker 4 3 5 2
./push_swap 4 3 5 2 | wc -l

./push_swap 4 5 2 3 | ./checker 4 5 2 3
./push_swap 4 5 2 3 | wc -l

./push_swap 4 5 3 2 | ./checker 4 5 3 2
./push_swap 4 5 3 2 | wc -l

./push_swap 5 2 3 4 | ./checker 5 2 3 4
./push_swap 5 2 3 4 | wc -l

./push_swap 5 2 4 3 | ./checker 5 2 4 3
./push_swap 5 2 4 3 | wc -l

./push_swap 5 3 2 4 | ./checker 5 3 2 4
./push_swap 5 3 2 4 | wc -l

./push_swap 5 3 4 2 | ./checker 5 3 4 2
./push_swap 5 3 4 2 | wc -l

./push_swap 5 4 2 3 | ./checker 5 4 2 3
./push_swap 5 4 2 3 | wc -l

./push_swap 5 4 3 2 | ./checker 5 4 3 2
./push_swap 5 4 3 2 | wc -l

echo "----5 numbers----"

./push_swap 1 2 3 4 5 | ./checker 1 2 3 4 5
./push_swap 1 2 3 4 5 | wc -l

./push_swap 1 2 3 5 4 | ./checker 1 2 3 5 4
./push_swap 1 2 3 5 4 | wc -l

./push_swap 1 2 4 3 5 | ./checker 1 2 4 3 5
./push_swap 1 2 4 3 5 | wc -l

./push_swap 1 2 4 5 3 | ./checker 1 2 4 5 3
./push_swap 1 2 4 5 3 | wc -l

./push_swap 1 2 5 3 4 | ./checker 1 2 5 3 4
./push_swap 1 2 5 3 4 | wc -l

./push_swap 1 2 5 4 3 | ./checker 1 2 5 4 3
./push_swap 1 2 5 4 3 | wc -l

./push_swap 1 3 2 4 5 | ./checker 1 3 2 4 5
./push_swap 1 3 2 4 5 | wc -l

./push_swap 1 3 2 5 4 | ./checker 1 3 2 5 4
./push_swap 1 3 2 5 4 | wc -l

./push_swap 1 3 4 2 5 | ./checker 1 3 4 2 5
./push_swap 1 3 4 2 5 | wc -l

./push_swap 1 3 4 5 2 | ./checker 1 3 4 5 2
./push_swap 1 3 4 5 2 | wc -l

./push_swap 1 3 5 2 4 | ./checker 1 3 5 2 4
./push_swap 1 3 5 2 4 | wc -l

./push_swap 1 3 5 4 2 | ./checker 1 3 5 4 2
./push_swap 1 3 5 4 2 | wc -l

./push_swap 1 4 2 3 5 | ./checker 1 4 2 3 5
./push_swap 1 4 2 3 5 | wc -l

./push_swap 1 4 2 5 3 | ./checker 1 4 2 5 3
./push_swap 1 4 2 5 3 | wc -l

./push_swap 1 4 3 2 5 | ./checker 1 4 3 2 5
./push_swap 1 4 3 2 5 | wc -l

./push_swap 1 4 3 5 2 | ./checker 1 4 3 5 2
./push_swap 1 4 3 5 2 | wc -l

./push_swap 1 4 5 2 3 | ./checker 1 4 5 2 3
./push_swap 1 4 5 2 3 | wc -l

./push_swap 1 4 5 3 2 | ./checker 1 4 5 3 2
./push_swap 1 4 5 3 2 | wc -l

./push_swap 1 5 2 3 4 | ./checker 1 5 2 3 4
./push_swap 1 5 2 3 4 | wc -l

./push_swap 1 5 2 4 3 | ./checker 1 5 2 4 3
./push_swap 1 5 2 4 3 | wc -l

./push_swap 1 5 3 2 4 | ./checker 1 5 3 2 4
./push_swap 1 5 3 2 4 | wc -l

./push_swap 1 5 3 4 2 | ./checker 1 5 3 4 2
./push_swap 1 5 3 4 2 | wc -l

./push_swap 1 5 4 2 3 | ./checker 1 5 4 2 3
./push_swap 1 5 4 2 3 | wc -l

./push_swap 1 5 4 3 2 | ./checker 1 5 4 3 2
./push_swap 1 5 4 3 2 | wc -l

./push_swap 2 1 3 4 5 | ./checker 2 1 3 4 5
./push_swap 2 1 3 4 5 | wc -l

./push_swap 2 1 3 5 4 | ./checker 2 1 3 5 4
./push_swap 2 1 3 5 4 | wc -l

./push_swap 2 1 4 3 5 | ./checker 2 1 4 3 5
./push_swap 2 1 4 3 5 | wc -l

./push_swap 2 1 4 5 3 | ./checker 2 1 4 5 3
./push_swap 2 1 4 5 3 | wc -l

./push_swap 2 1 5 3 4 | ./checker 2 1 5 3 4
./push_swap 2 1 5 3 4 | wc -l

./push_swap 2 1 5 4 3 | ./checker 2 1 5 4 3
./push_swap 2 1 5 4 3 | wc -l

./push_swap 2 3 1 4 5 | ./checker 2 3 1 4 5
./push_swap 2 3 1 4 5 | wc -l

./push_swap 2 3 1 5 4 | ./checker 2 3 1 5 4
./push_swap 2 3 1 5 4 | wc -l

./push_swap 2 3 4 1 5 | ./checker 2 3 4 1 5
./push_swap 2 3 4 1 5 | wc -l

./push_swap 2 3 4 5 1 | ./checker 2 3 4 5 1
./push_swap 2 3 4 5 1 | wc -l

./push_swap 2 3 5 1 4 | ./checker 2 3 5 1 4
./push_swap 2 3 5 1 4 | wc -l

./push_swap 2 3 5 4 1 | ./checker 2 3 5 4 1
./push_swap 2 3 5 4 1 | wc -l

./push_swap 2 4 1 3 5 | ./checker 2 4 1 3 5
./push_swap 2 4 1 3 5 | wc -l

./push_swap 2 4 1 5 3 | ./checker 2 4 1 5 3
./push_swap 2 4 1 5 3 | wc -l

./push_swap 2 4 3 1 5 | ./checker 2 4 3 1 5
./push_swap 2 4 3 1 5 | wc -l

./push_swap 2 4 3 5 1 | ./checker 2 4 3 5 1
./push_swap 2 4 3 5 1 | wc -l

./push_swap 2 4 5 1 3 | ./checker 2 4 5 1 3
./push_swap 2 4 5 1 3 | wc -l

./push_swap 2 4 5 3 1 | ./checker 2 4 5 3 1
./push_swap 2 4 5 3 1 | wc -l

./push_swap 2 5 1 3 4 | ./checker 2 5 1 3 4
./push_swap 2 5 1 3 4 | wc -l

./push_swap 2 5 1 4 3 | ./checker 2 5 1 4 3
./push_swap 2 5 1 4 3 | wc -l

./push_swap 2 5 3 1 4 | ./checker 2 5 3 1 4
./push_swap 2 5 3 1 4 | wc -l

./push_swap 2 5 3 4 1 | ./checker 2 5 3 4 1
./push_swap 2 5 3 4 1 | wc -l

./push_swap 2 5 4 1 3 | ./checker 2 5 4 1 3
./push_swap 2 5 4 1 3 | wc -l

./push_swap 2 5 4 3 1 | ./checker 2 5 4 3 1
./push_swap 2 5 4 3 1 | wc -l

./push_swap 3 2 1 4 5 | ./checker 3 2 1 4 5
./push_swap 3 2 1 4 5 | wc -l


./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
./push_swap 3 2 1 5 4 | wc -l

./push_swap 3 2 4 1 5 | ./checker 3 2 4 1 5
./push_swap 3 2 4 1 5 | wc -l

./push_swap 3 2 4 5 1 | ./checker 3 2 4 5 1
./push_swap 3 2 4 5 1 | wc -l

./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
./push_swap 3 2 5 1 4 | wc -l

./push_swap 3 2 5 4 1 | ./checker 3 2 5 4 1
./push_swap 3 2 5 4 1 | wc -l

./push_swap 3 1 2 4 5 | ./checker 3 1 2 4 5
./push_swap 3 1 2 4 5 | wc -l

./push_swap 3 1 2 5 4 | ./checker 3 1 2 5 4
./push_swap 3 1 2 5 4 | wc -l

./push_swap 3 1 4 2 5 | ./checker 3 1 4 2 5
./push_swap 3 1 4 2 5 | wc -l

./push_swap 3 1 4 5 2 | ./checker 3 1 4 5 2
./push_swap 3 1 4 5 2 | wc -l

./push_swap 3 1 5 2 4 | ./checker 3 1 5 2 4
./push_swap 3 1 5 2 4 | wc -l

./push_swap 3 1 5 4 2 | ./checker 3 1 5 4 2
./push_swap 3 1 5 4 2 | wc -l

./push_swap 3 4 2 1 5 | ./checker 3 4 2 1 5
./push_swap 3 4 2 1 5 | wc -l

./push_swap 3 4 2 5 1 | ./checker 3 4 2 5 1
./push_swap 3 4 2 5 1 | wc -l

./push_swap 3 4 1 2 5 | ./checker 3 4 1 2 5
./push_swap 3 4 1 2 5 | wc -l

./push_swap 3 4 1 5 2 | ./checker 3 4 1 5 2
./push_swap 3 4 1 5 2 | wc -l

./push_swap 3 4 5 2 1 | ./checker 3 4 5 2 1
./push_swap 3 4 5 2 1 | wc -l

./push_swap 3 4 5 1 2 | ./checker 3 4 5 1 2
./push_swap 3 4 5 1 2 | wc -l

./push_swap 3 5 2 1 4 | ./checker 3 5 2 1 4
./push_swap 3 5 2 1 4 | wc -l

./push_swap 3 5 2 4 1 | ./checker 3 5 2 4 1
./push_swap 3 5 2 4 1 | wc -l

./push_swap 3 5 1 2 4 | ./checker 3 5 1 2 4
./push_swap 3 5 1 2 4 | wc -l

./push_swap 3 5 1 4 2 | ./checker 3 5 1 4 2
./push_swap 3 5 1 4 2 | wc -l

./push_swap 3 5 4 2 1 | ./checker 3 5 4 2 1
./push_swap 3 5 4 2 1 | wc -l

./push_swap 3 5 4 1 2 | ./checker 3 5 4 1 2
./push_swap 3 5 4 1 2 | wc -l

./push_swap 4 2 3 1 5 | ./checker 4 2 3 1 5
./push_swap 4 2 3 1 5 | wc -l

./push_swap 4 2 3 5 1 | ./checker 4 2 3 5 1
./push_swap 4 2 3 5 1 | wc -l

./push_swap 4 2 1 3 5 | ./checker 4 2 1 3 5
./push_swap 4 2 1 3 5 | wc -l

./push_swap 4 2 1 5 3 | ./checker 4 2 1 5 3
./push_swap 4 2 1 5 3 | wc -l

./push_swap 4 2 5 3 1 | ./checker 4 2 5 3 1
./push_swap 4 2 5 3 1 | wc -l

./push_swap 4 2 5 1 3 | ./checker 4 2 5 1 3
./push_swap 4 2 5 1 3 | wc -l

./push_swap 4 3 2 1 5 | ./checker 4 3 2 1 5
./push_swap 4 3 2 1 5 | wc -l

./push_swap 4 3 2 5 1 | ./checker 4 3 2 5 1
./push_swap 4 3 2 5 1 | wc -l

./push_swap 4 3 1 2 5 | ./checker 4 3 1 2 5
./push_swap 4 3 1 2 5 | wc -l

./push_swap 4 3 1 5 2 | ./checker 4 3 1 5 2
./push_swap 4 3 1 5 2 | wc -l

./push_swap 4 3 5 2 1 | ./checker 4 3 5 2 1
./push_swap 4 3 5 2 1 | wc -l

./push_swap 4 3 5 1 2 | ./checker 4 3 5 1 2
./push_swap 4 3 5 1 2 | wc -l

./push_swap 4 1 2 3 5 | ./checker 4 1 2 3 5
./push_swap 4 1 2 3 5 | wc -l

./push_swap 4 1 2 5 3 | ./checker 4 1 2 5 3
./push_swap 4 1 2 5 3 | wc -l

./push_swap 4 1 3 2 5 | ./checker 4 1 3 2 5
./push_swap 4 1 3 2 5 | wc -l

./push_swap 4 1 3 5 2 | ./checker 4 1 3 5 2
./push_swap 4 1 3 5 2 | wc -l

./push_swap 4 1 5 2 3 | ./checker 4 1 5 2 3
./push_swap 4 1 5 2 3 | wc -l

./push_swap 4 1 5 3 2 | ./checker 4 1 5 3 2
./push_swap 4 1 5 3 2 | wc -l

./push_swap 4 5 2 3 1 | ./checker 4 5 2 3 1
./push_swap 4 5 2 3 1 | wc -l

./push_swap 4 5 2 1 3 | ./checker 4 5 2 1 3
./push_swap 4 5 2 1 3 | wc -l

./push_swap 4 5 3 2 1 | ./checker 4 5 3 2 1
./push_swap 4 5 3 2 1 | wc -l

./push_swap 4 5 3 1 2 | ./checker 4 5 3 1 2
./push_swap 4 5 3 1 2 | wc -l

./push_swap 4 5 1 2 3 | ./checker 4 5 1 2 3
./push_swap 4 5 1 2 3 | wc -l

./push_swap 4 5 1 3 2 | ./checker 4 5 1 3 2
./push_swap 4 5 1 3 2 | wc -l

./push_swap 5 2 3 4 1 | ./checker 5 2 3 4 1
./push_swap 5 2 3 4 1 | wc -l

./push_swap 5 2 3 1 4 | ./checker 5 2 3 1 4
./push_swap 5 2 3 1 4 | wc -l

./push_swap 5 2 4 3 1 | ./checker 5 2 4 3 1
./push_swap 5 2 4 3 1 | wc -l

./push_swap 5 2 4 1 3 | ./checker 5 2 4 1 3
./push_swap 5 2 4 1 3 | wc -l

./push_swap 5 2 1 3 4 | ./checker 5 2 1 3 4
./push_swap 5 2 1 3 4 | wc -l

./push_swap 5 2 1 4 3 | ./checker 5 2 1 4 3
./push_swap 5 2 1 4 3 | wc -l

./push_swap 5 3 2 4 1 | ./checker 5 3 2 4 1
./push_swap 5 3 2 4 1 | wc -l

./push_swap 5 3 2 1 4 | ./checker 5 3 2 1 4
./push_swap 5 3 2 1 4 | wc -l

./push_swap 5 3 4 2 1 | ./checker 5 3 4 2 1
./push_swap 5 3 4 2 1 | wc -l

./push_swap 5 3 4 1 2 | ./checker 5 3 4 1 2
./push_swap 5 3 4 1 2 | wc -l

./push_swap 5 3 1 2 4 | ./checker 5 3 1 2 4
./push_swap 5 3 1 2 4 | wc -l

./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2
./push_swap 5 3 1 4 2 | wc -l

./push_swap 5 4 2 3 1 | ./checker 5 4 2 3 1
./push_swap 5 4 2 3 1 | wc -l

./push_swap 5 4 2 1 3 | ./checker 5 4 2 1 3
./push_swap 5 4 2 1 3 | wc -l

./push_swap 5 4 3 2 1 | ./checker 5 4 3 2 1
./push_swap 5 4 3 2 1 | wc -l

./push_swap 5 4 3 1 2 | ./checker 5 4 3 1 2
./push_swap 5 4 3 1 2 | wc -l

./push_swap 5 4 1 2 3 | ./checker 5 4 1 2 3
./push_swap 5 4 1 2 3 | wc -l

./push_swap 5 4 1 3 2 | ./checker 5 4 1 3 2
./push_swap 5 4 1 3 2 | wc -l

./push_swap 5 1 2 3 4 | ./checker 5 1 2 3 4
./push_swap 5 1 2 3 4 | wc -l

./push_swap 5 1 2 4 3 | ./checker 5 1 2 4 3
./push_swap 5 1 2 4 3 | wc -l

./push_swap 5 1 3 2 4 | ./checker 5 1 3 2 4
./push_swap 5 1 3 2 4 | wc -l

./push_swap 5 1 3 4 2 | ./checker 5 1 3 4 2
./push_swap 5 1 3 4 2 | wc -l

./push_swap 5 1 4 2 3 | ./checker 5 1 4 2 3
./push_swap 5 1 4 2 3 | wc -l

./push_swap 5 1 4 3 2 | ./checker 5 1 4 3 2
./push_swap 5 1 4 3 2 | wc -l
