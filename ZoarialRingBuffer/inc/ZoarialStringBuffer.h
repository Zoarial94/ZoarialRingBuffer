#pragma once

#include <cstdint>
#include <string>

class ZoarialStringBuffer {
private:

	const uint32_t LENGTH;
	char* const buf;

	uint32_t _start = 0;
	uint32_t _end = 0;

	inline uint32_t inc(uint32_t num);
	uint32_t capacity();
	bool empty();

public:

	ZoarialStringBuffer(const uint32_t len);
	~ZoarialStringBuffer();

	bool addString(const std::string& str);
	std::string getString();

};