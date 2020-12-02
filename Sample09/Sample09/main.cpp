#include "Pipeline.h"
#include <fstream>

void determineElement(char curChar, int x, int y, IPipeline* pipeline) {
	switch (curChar) {
	case '-':
		new PipelineElementMinus(x, y, pipeline);
		break;
	case 'I':
		new PipelineElementI(x, y, pipeline);
		break;
	case '+':
		new PipelineElementPlus(x, y, pipeline);
		break;
	case 'O':
		new PipelineElementO(x, y, pipeline);
		break;
	case 'T':
		new PipelineElementT(x, y, pipeline);
		break;
	default:
		break;
	}
}

void load() {

	IPipeline* pipeline;

	char curChar;
	std::ifstream in{};
	std::string line;

	in.open("pipe.txt");
	int counter = 0;

	if (in.is_open())
	{
		while (!in.eof()) {
			int size;
			in >> size;
			pipeline = new Pipeline(size);
			in.get(curChar);
			for (int i = 0; i < size; i++){
				int x = 0;
				while (in.get(curChar) && curChar != '\n') {
					determineElement(curChar, x, i, pipeline);
					++x;
				}
			}
			std::cout << "matice c.:" << ++counter << ":" << pipeline->IsPipelineOK() << std::endl;
			delete pipeline;
			if (in.eof()){
				break;
			}
			in >> line;
			in.get();

		}
		in.close();
	}

}

int main(int argc, char** argv) {

	load();
	return 0;
}