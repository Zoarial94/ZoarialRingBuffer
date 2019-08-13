#pragma once

#include <cstdint>
#include <string>

//	Store C style strings
class ZoarialStringBuffer {
private:

	const uint32_t LENGTH;	//	Length of the buffer
	char* const buf;		//	Const pointer to the buffer

	uint32_t _start = 0;	//	Start marker
	uint32_t _end = 0;		//	End marker

	inline uint32_t inc(uint32_t num);
	inline uint32_t capacity();
	inline bool empty();

public:

	ZoarialStringBuffer(const uint32_t len);
	~ZoarialStringBuffer();

	bool addString(const std::string& str);
	std::string getString();

};