#include"brain.hpp"

Interpreter::Memory& Interpreter::Memory::operator=(unsigned char c){
	        tape[dataPointer] = c;

	        return *this;
}

Interpreter::Memory::operator unsigned char(){
	return tape[dataPointer];
}

Interpreter::Interpreter(std::string fName){
	std::string input = readFile(fName);
	code = parse(input);
}

Interpreter::~Interpreter(){}

std::string Interpreter::readFile(std::string fName){
	std::ifstream File(fName);

	if(File.is_open()){
		std::string fileCont((std::istreambuf_iterator<char>(File)), std::istreambuf_iterator<char>());
		File.close();

		return fileCont;
	}

	return"Error";
}

std::string Interpreter::parse(std::string input){
	input = clearWhite(input);
	input = clearComments(input);
	
	if(!matchBrack(input)){
		std::cout<<"error";
		
		return ""; // actualy make an error
	}
	
	return input;
}

std::string Interpreter::clearWhite(std::string input){
	std::string output;

	for(char c : input){
		if(c != ' '){
			output += c;
		}
	}
	return output;
}

std::string Interpreter::clearComments(std::string input){
	const std::string syntax = "<>[].,+-";
	std::string output;

	for(char c : input){
		if(syntax.find(c) != std::string::npos){
			output += c;
		}
	}

	return output;
}

bool Interpreter::matchBrack(std::string input){
	int total = 0;

	for(char c : input){
		if(c == '[')
			total++;
		else if(c == ']')
			total--;
	}

	if(total != 0)
		return false;
	else
		return true;
}

void Interpreter::run(){
	std::string userInput;
	int total = 0;

	for(int i=0; i <= code.size(); i++){
		switch(code[i]){
			case '>':
				memory.dataPointer++;
				break;
			case '<':
				memory.dataPointer--;
				break;
			case '+':
				memory = memory + 1;
				break;
			case '-':
				memory = memory - 1;
				break;
			case ',':
				std::cin>>userInput;

				memory = userInput[0];
				break;
			case '.':
				std::cout<<memory<<std::endl;
				break;
			case '[':
				total = 0;
				if(memory == 0){
					total++;
					while(code[i] != ']' || total != 0){
						i++;
						if(code[i] == '[')
							total++;
						else if(code[i] == ']')
							total--;
					}
				}
				
				break;
			case ']':
				total = 0;
				if(memory != 0){
					total++;
					while(code[i] != '[' || total != 0){
						i--;
						if(code[i] == ']')
							total++;
						else if(code[i] == '[')
							total--;
					}
				}
				break;
			default:
				break;
		}
	}
}
