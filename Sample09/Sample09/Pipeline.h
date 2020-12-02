#pragma once
#ifndef PIPELINE_H
#define PIPELINE_H

#include <iostream>

struct APipelineElement;
struct IPipeline {
	virtual ~IPipeline() { }
	virtual const APipelineElement* GetElement(int x, int y) const = 0;
	virtual bool IsPipelineOK() const = 0;
	int _size;
	APipelineElement*** _matrix;
	virtual void SetElement(APipelineElement* element) = 0;
};

struct Pipeline:IPipeline {
	
	Pipeline(int size);
	~Pipeline();
	const APipelineElement* GetElement(int x, int y) const override;
	bool IsPipelineOK() const override;
	void SetElement(APipelineElement* element) override;
};

struct APipelineElement {
	virtual ~APipelineElement() { }
	virtual bool IscorrectlyConnected(const IPipeline* pipeline) const = 0;
	int _x;
	int _y;
};

class PipelineElementMinus:APipelineElement {
public:
	PipelineElementMinus(int x, int y, IPipeline* pipeline);
	~PipelineElementMinus();
	bool IscorrectlyConnected(const IPipeline* pipeline) const override;
};

class PipelineElementI:APipelineElement {
public:
	PipelineElementI(int x, int y, IPipeline* pipeline);
	~PipelineElementI();
	bool IscorrectlyConnected(const IPipeline* pipeline) const override;
};

class PipelineElementPlus:APipelineElement {
public:
	PipelineElementPlus(int x, int y, IPipeline* pipeline);
	~PipelineElementPlus();
	bool IscorrectlyConnected(const IPipeline* pipeline) const override;
};

class PipelineElementO:APipelineElement {
public:
	PipelineElementO(int x, int y, IPipeline* pipeline);
	~PipelineElementO();
	bool IscorrectlyConnected(const IPipeline* pipeline) const override;
};

class PipelineElementT:APipelineElement {
public:
	PipelineElementT(int x, int y, IPipeline* pipeline);
	~PipelineElementT();
	bool IscorrectlyConnected(const IPipeline* pipeline) const override;
};

#endif // !PIPELINE_H

