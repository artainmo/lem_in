Test () {
	sed -n '2p' generated.map
	./../lem-in -q < generated.map | wc -l
}

echo '\033[0;36m./generator_osx --flow-one\033[0m'
./generator_osx --flow-one > generated.map
Test

echo '\033[0;36m./generator_osx --flow-ten\033[0m'
./generator_osx --flow-ten > generated.map
Test

echo '\033[0;36m./generator_osx --flow-thousand\033[0m'
./generator_osx --flow-thousand > generated.map
Test

echo '\033[0;36m./generator_osx --big\033[0m'
./generator_osx --big > generated.map
Test

echo '\033[0;36m./generator_osx --big-superposition\033[0m'
./generator_osx --big-superposition > generated.map
Test
