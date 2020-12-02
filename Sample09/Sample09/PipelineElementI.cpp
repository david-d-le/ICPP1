#include "Pipeline.h"

PipelineElementI::PipelineElementI(int x, int y, IPipeline* pipeline) {
	if (x < 0 || x >= pipeline->_size || y < 0 || y >= pipeline->_size) {
		throw std::invalid_argument("invalid index in argument");
	}
	_x = x;
	_y = y;
	pipeline->SetElement(this);
}
PipelineElementI::~PipelineElementI() {
}

bool PipelineElementI::IscorrectlyConnected(const IPipeline* pipeline) const {
	if (_y == 0 || _y == pipeline->_size - 1
		|| dynamic_cast<const PipelineElementT*>(pipeline->_matrix[_x][_y + 1]) || dynamic_cast<const PipelineElementMinus*>(pipeline->_matrix[_x][_y + 1])
		|| dynamic_cast<const PipelineElementMinus*>(pipeline->_matrix[_x][_y - 1])
		|| pipeline->_matrix[_x][_y - 1] == nullptr || pipeline->_matrix[_x][_y + 1] == nullptr) {
		return false;
	}
	return true;
}