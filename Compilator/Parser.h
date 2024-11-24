#include <fstream>
#include <vector>
#include "Token.h"
#include <memory>
//#include "Lexer.h"
using namespace std;
struct Node {
	string data;
	vector<Node> children;
};
class Parser {
private:
	struct Node {
		string type;
		string value;
		vector<Node*> children;
		void addChild(Node*  child) {
			children.push_back(child);
		}
	};
	vector<Token> text;
	string input;
	Token lexeme;
	int stroka=1;
	int i;
	void getLexeme();
	void printparse();
	void Begin();
	void Descriptions();
	void Descr();
	void type();
	void ID();
	void varlist();
	void Op();
	void Operators();
	void expr();
	void term();
	void simpleExpr();
	void constant();
	void End();
	void match(string s);
	void match2(string s);
public:

	Parser(vector<Token> tok);
	void parse();
	~Parser() {
//		delete[] ;
	}
};
