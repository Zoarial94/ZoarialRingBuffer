#include "ZoarialStringBuffer.h"

#include <cstring>

ZoarialStringBuffer::ZoarialStringBuffer(const uint32_t len) : LENGTH(len), buf(new char[len]) {

}

ZoarialStringBuffer::~ZoarialStringBuffer() {
	delete[] buf;
}

bool ZoarialStringBuffer::addString(const std::string& str) {
	const char* cstr = str.c_str();
	uint32_t strLen = std::strlen(cstr);
	uint32_t newEnd = (strLen + _end) % LENGTH;

	//	If the string can fit
	if (capacity() >= strLen) {
		if (newEnd < _end) {
			uint32_t spaceTilEnd = LENGTH - _end;
			std::strncpy(buf + _end, cstr, spaceTilEnd);	//	Copy to the end of the buffer
			std::strcpy(buf, cstr + spaceTilEnd);			//	Wrap around and copy what is left
		} else {
			std::strcpy(buf + _end, cstr);
		}
		_end = newEnd;
	} else {
		return false;
	}

	return true;

}

std::string ZoarialStringBuffer::getString() {

	if (empty()) {
		return "";
	}

	char* strEnd = (char*)std::memchr(buf + _start, 0, LENGTH - _start);
	std::string str;

	//	If the string warps around
	if (strEnd == nullptr) {
		uint32_t spaceFromStart = LENGTH - _start;
		strEnd = std::strchr(buf, 0);
		str.append(buf + _start, spaceFromStart);
		str.append(buf);
	} else {
		str.append(buf + _start);
	}
	_start = strEnd - buf;

	return str;
}

uint32_t ZoarialStringBuffer::capacity() {
	return LENGTH - ((_end - _start) % LENGTH);
}

bool ZoarialStringBuffer::empty() {
	return _start == _end;
}

uint32_t ZoarialStringBuffer::inc(uint32_t num) {
	return (num + 1) % LENGTH;
}