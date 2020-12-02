#include "Pipeline.h"

Pipeline::Pipeline(int size){
	if (size <= 0){
		throw std::invalid_argument("invalid matrix size!");
	} 
	_size = size;
	_matrix = new APipelineElement**[size];
	for (int i = 0; i < size; i++){
		_matrix[i] = new APipelineElement * [size] {nullptr};
	}
}

Pipeline::~Pipeline() {
	for (int i = 0; i < _size; i++){
		for (int j = 0; j < _size; j++){
			if (_matrix[i][j] != nullptr){
				delete _matrix[i][j];
			}
		}
		delete[]  _matrix[i];
	}
	delete[] _matrix;
}

const APipelineElement* Pipeline::GetElement(int x, int y) const {
	if (x < 0 || x >= _size || y < 0 || y >= _size){
		throw std::invalid_argument("invalid index in argument");
	}
	return _matrix[x][y];
}

bool Pipeline::IsPipelineOK() const{
	for (int i = 0; i < _size; i++){
		for (int j = 0; j < _size; j++)
		{
			
			if (_matrix[i][j] == nullptr){
				continue;
			}
			if (!_matrix[i][j]->IscorrectlyConnected(this)){
				return false;
			}
		}
	}
	return true;
}

void Pipeline::SetElement(APipelineElement* element){
	if (element == nullptr){
		throw std::invalid_argument("nullptr in argument");
	}
	_matrix[element->_x][element->_y] = element;
}



