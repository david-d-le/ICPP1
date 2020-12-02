#include "Pipeline.h"

PipelineElementPlus::PipelineElementPlus(int x, int y, IPipeline* pipeline) {
	if (x < 0 || x >= pipeline->_size || y < 0 || y >= pipeline->_size) {
		throw std::invalid_argument("invalid index in argument");
	}
	_x = x;
	_y = y;
	pipeline->SetElement(this);
}
PipelineElementPlus::~PipelineElementPlus() {
}

bool PipelineElementPlus::IscorrectlyConnected(const IPipeline* pipeline) const {
	if (_x == 0 || _x == pipeline->_size - 1 || _y == 0 || _y == pipeline->_size - 1
		|| dynamic_cast<const PipelineElementI*>(pipeline->_matrix[_x - 1][_y]) || dynamic_cast<const PipelineElementI*>(pipeline->_matrix[_x + 1][_y])
		|| dynamic_cast<const PipelineElementT*>(pipeline->_matrix[_x][_y+1]) || dynamic_cast<const PipelineElementMinus*>(pipeline->_matrix[_x][_y + 1])
		|| dynamic_cast<const PipelineElementMinus*>(pipeline->_matrix[_x][_y - 1])
		|| pipeline->_matrix[_x][_y - 1] == nullptr || pipeline->_matrix[_x][_y + 1] == nullptr 
		|| pipeline->_matrix[_x - 1][_y] == nullptr || pipeline->_matrix[_x + 1][_y] == nullptr) {
		return false;
	}
	return true;
}