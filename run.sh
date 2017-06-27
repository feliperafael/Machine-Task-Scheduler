#!/bin/bash

path="input"

files="$path/m3/n20/m*"
echo $files

for file in $files;
do
	for seed in '10 19';
	do
		#echo $file
		./bin/Release/GeneticAlgorithm $file 1 $seed
	done
done

files="$path/m3/n30/m*"
echo $files

for file in $files;
do
	for seed in '10 19';
	do
		#echo $file
		./bin/Release/GeneticAlgorithm $file 1 $seed
	done	
done

files="$path/m10/n50/m*"
echo $files

for file in $files;
do
	for seed in '10 19';
	do
		#echo $file
		./bin/Release/GeneticAlgorithm $file 1 $seed
	done	
done

files="$path/m10/n100/m*"
echo $files

for file in $files;
do
	for seed in '10 19';
	do
		#echo $file
		./bin/Release/GeneticAlgorithm $file 1 $seed
	done
done

files="$path/m20/n50/m*"
echo $files

for file in $files;
do
	for seed in '10 19';
	do
		#echo $file
		./bin/Release/GeneticAlgorithm $file 1 $seed
	done	
done

files="$path/m20/n100/m*"
echo $files

for file in $files;
do
	for seed in '10 19';
	do
		#echo $file
		./bin/Release/GeneticAlgorithm $file 1 $seed
	done	
done
