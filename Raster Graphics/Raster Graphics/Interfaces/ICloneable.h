#pragma once

class ICloneable {
public:
	virtual ICloneable* clone() = 0;
};
