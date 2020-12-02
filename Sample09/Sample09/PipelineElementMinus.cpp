#include "Pipeline.h"

PipelineElementMinus::PipelineElementMinus(int x, int y, IPipeline* pipeline) {
	if (x < 0 || x >= pipeline->_size || y < 0 || y >= pipeline->_size){
		throw std::invalid_argument("invalid index in argument");
	}
	_x = x;
	_y = y;
	pipeline->SetElement(this);
}
PipelineElementMinus::~PipelineElementMinus() {
}

bool PipelineElementMinus::IscorrectlyConnected(const IPipeline* pipeline) const {
	if (_x == 0 || _x == pipeline->_size - 1 || pipeline->_matrix[_x-1][_y] == nullptr || pipeline->_matrix[_x + 1][_y] == nullptr
		|| dynamic_cast<const PipelineElementI*>(pipeline->_matrix[_x - 1][_y]) || dynamic_cast<const PipelineElementI*>(pipeline->_matrix[_x + 1][_y])
		|| pipeline->_matrix[_x - 1][_y] == nullptr || pipeline->_matrix[_x + 1][_y] == nullptr){

		return false;
	}
	return true;
}