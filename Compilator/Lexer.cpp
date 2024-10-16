#include "includes.h"
#include "Lexer.h"
using namespace std;

int main()
{
	ifstream inp("input.txt");
	Lexer programm(inp);
	programm.getHashTable().printHashTable();
}