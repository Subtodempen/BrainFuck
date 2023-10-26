#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

#define TAPE_SIZE 30000

class Interpreter{
	public:
		Interpreter(std::string input);
		~Interpreter();
		
		void run(); //TODO change?
	private:
		std::string code;

		struct Memory{
			std::vector<unsigned char> tape;
			int dataPointer;

			operator unsigned char();
			Memory& operator=(unsigned char c);
			Memory() : tape(TAPE_SIZE), dataPointer(0){}
			~Memory(){}
		}memory;
		std::string readFile(std::string fName);

		std::string parse(std::string input);
		std::string clearWhite(std::string input);
		std::string clearComments(std::string input);
		
		bool matchBrack(std::string input);//TODO make tgis output the location		
};
