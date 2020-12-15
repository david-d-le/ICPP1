#pragma once

struct ANetworkElement;

template <typename T>
struct Queue {
private:
	struct El {
		T Value;
		El* Next;
		El* Previous;
	};
	El* _first;
	El* _last;
public:
	Queue() {
		_first = _last = nullptr;
	}
	Queue(const Queue& f) {
		El* it = f._first;
		while (it) {
			Insert(it->Value);
			it = it->Next;
		}
	}
	~Queue() {
		while (_first) {
			El* tmp = _first;
			_first = _first->Next;
			delete tmp;
		}
	}
	void Insert(T Value) {
		_last = new El{ Value, nullptr, _last };
		if (!_first)
			_first = _last;
		else
			_last->Previous->Next = _last;
	}
	T Remove() {
		T Value = _last->Value;
		El* tmp = _last;
		if (_last->Previous) {
			_last = _last->Previous;
			_last->Next = nullptr;
		}
		else {
			_last = nullptr;
			_first = nullptr;
		}
		delete tmp;
		return Value;
	}
	bool Contains(T Value) const {
		El* el = _first;
		while (el) {
			if (el->Value == Value)
				return true;
			el = el->Next;
		}
		return false;
	}
	using ApplyFunction = void(ANetworkElement::*) (T);
	void ProcessElements(ANetworkElement *element,ApplyFunction f) {
		El* el = _first;
		while (el) {
			(element->*f)(el->Value);
			el = el->Next;
		}
	}

	using ApplyFunction2 = void(ANetworkElement::*) ();
	void ProcessElements2(ApplyFunction2 f) {
		El* el = _first;
		while (el) {
			((el->Value)->*f)();
			el = el->Next;
		}
	}

	bool IsEmpty() const {
		return _first == nullptr;
	}
};