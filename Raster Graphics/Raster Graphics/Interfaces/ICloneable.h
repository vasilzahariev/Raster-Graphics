#ifndef ICLONEABLE_H
#define ICLONEABLE_H

class ICloneable {
public:
	virtual ICloneable* clone() = 0;
};

#endif // !ICLONEABLE_H
