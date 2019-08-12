#pragma once

#include <cstdint>
#include <string>

class ZoarialStringBuffer {
private:

	const uint32_t LENGTH;
	char* const buf;

	uint32_t _start = 0;
	uint32_t _end = 0;

public:

	ZoarialStringBuffer(const uint32_t len);

	void addString(const std::string& str);
	std::string getString();

};