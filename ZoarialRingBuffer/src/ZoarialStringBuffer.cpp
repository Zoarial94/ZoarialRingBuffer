#include "ZoarialStringBuffer.h"

#include <cstring>

ZoarialStringBuffer::ZoarialStringBuffer(const uint32_t len) : LENGTH(len), buf(new char[len]) {

}

ZoarialStringBuffer::~ZoarialStringBuffer() {
	delete[] buf;
}

//	Store a string in the buffer
bool ZoarialStringBuffer::addString(const std::string& str) {
	const char* cstr = str.c_str();							//	Get C string
	uint32_t strLen = std::strlen(cstr);					//	Get the length of the string
	uint32_t newEnd = (strLen + _end) % LENGTH;				//	Calculate where the new end marker would be

	if (capacity() >= strLen) {								//	If the string can fit
		if (newEnd < _end) {								//	The string needs to wrap around
			uint32_t spaceTilEnd = LENGTH - _end;				//	Find length until the end of the buffer
			std::strncpy(buf + _end, cstr, spaceTilEnd);		//	Copy to the end of the buffer
			std::strcpy(buf, cstr + spaceTilEnd);				//	Wrap around and copy what is left
		} else {											//	The string does not need to wrap
			std::strcpy(buf + _end, cstr);						//	Copy the whole string
		}
		_end = newEnd;										//	Move the end marker
	} else {
		return false;
	}

	return true;

}

std::string ZoarialStringBuffer::getString() {

	if (empty()) {											//	If the buffer is empty return
		return "";
	}

	char* strEnd = (char*)std::memchr(buf + _start, 0, LENGTH - _start);	//	Find the \0 byte of the C string
	std::string str;														//	String to return

	//	If the string warps around
	if (strEnd == nullptr) {							//	The string wraps around
		uint32_t spaceFromStart = LENGTH - _start;			//	Get length of the part of the string before it wraps
		strEnd = std::strchr(buf, 0);						//	Find the end of the string
		str.append(buf + _start, spaceFromStart);			//	Copy first part of the string
		str.append(buf);									//	Copy the rest of the string
	} else {											//	The string does not wrap
		str.append(buf + _start);							//	Copy the string
	}
	_start = strEnd - buf;								//	Move the start marker

	return str;
}

//	Return how much space is left
uint32_t ZoarialStringBuffer::capacity() {
	return LENGTH - ((_end - _start) % LENGTH);
}

//	Return whether the buffer is empty
bool ZoarialStringBuffer::empty() {
	return _start == _end;
}

//	Returns (num + 1) and can wrap back to 0
uint32_t ZoarialStringBuffer::inc(uint32_t num) {
	return (num + 1) % LENGTH;
}