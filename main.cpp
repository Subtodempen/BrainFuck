#include"brain.hpp"

int main(int argc, char **argv){
	if(argc >= 2){
		Interpreter interpreter(argv[1]);
		interpreter.run();
	}else
		std::cout<<"Need more arguments"<<std::endl;
	
	return 0;
}
