#include "Pipeline.h"

PipelineElementO::PipelineElementO(int x, int y, IPipeline* pipeline) {
	if (x < 0 || x >= pipeline->_size || y < 0 || y >= pipeline->_size) {
		throw std::invalid_argument("invalid index in argument");
	}
	_x = x;
	_y = y;
	pipeline->SetElement(this);
}
PipelineElementO::~PipelineElementO() {
}

bool PipelineElementO::IscorrectlyConnected(const IPipeline* pipeline) const {
	return true;
}