#include "teste.h"
#include "operatii.h"
#include <assert.h>

void test()
{

	testPass();
	testDispensabile();
	testRepetari();
	testEliminari();
	cout << "Testele au reusit!\n";
}

void testDispensabile()
{
	assert(posDispensabile("AAAAAAABBBBBBBBOOOOOOOOOOO",26) == 7);
	assert(posDispensabile("AAAAAHZZZZZZZ1111203aaaaa",25) == 5);
	assert(posDispensabile("AAABBBCCCDDDEEEEFFGGGHHHHHHIII",30) == 9);
	assert(posDispensabile("AAA1234567890BBBCCC2023",23) == 3);
	assert(posDispensabile("aaabbccc1111111111112340EEFFF",29) == 7);
}

void testRepetari()
{
	assert(catTimpSeRepeta("AAAAAAABBBBBBBBOOOOOBBBOOO",'B',7,26) == 8);
	assert(catTimpSeRepeta("AAAAAAHZZZAAZZ1111203aaaaa", 'A',0,26) == 6);
	assert(catTimpSeRepeta("AAABABCCCDDDEEAEFFGGGHHAAHHIII", 'A',0,30) == 3);

}

void testEliminari()
{	
	int count = 0;
	string s = "AAAAAAABBBBBBBBOOOOOOOOOOO";
	elimina(s, count);
	assert(s == "AAAAABBBBBBOOOOOOOO");
	assert(count == 7);
	elimina(s, count);
	assert(s == "AAAABBBBOOOOOO");
	assert(count == 12);
	s = "AAABBBCCCDDDEEEEFFGGGHHHHHHIII";
	count = 0;
	elimina(s, count);
	assert(s == "AABBCCDDEEEFFGGHHHHII");
	assert(count == 9);
}

void testPass()
{
	assert(pass("AAAAAAABBBBBBBBOOOOOOOOOOO") == 11);
	assert(pass("AAAAAHZZZZZZZ1111203aaaaa") == 9);
	assert(pass("AAABBBCCCDDDEEEEFFGGGHHHHHHIII") == 11);
	assert(pass("AAA1234567890BBBCCC2023") == 3);
	assert(pass("OOOOOOOOO") == 3);
	assert(pass("aaabbccc1111111111112340EEFFF") == 9);
	assert(pass("AAAbc") == 2);
	assert(pass("AAAb1") == 2);
	assert(pass("Aaabc") == 1);
	assert(pass("Aaaac") == 2);
	assert(pass("****") == 3);
	assert(pass("abbb") == 3);
	assert(pass("abcd") == 2);
	assert(pass("abc1") == 2);
	assert(pass("12EfgHU") == 0);
}