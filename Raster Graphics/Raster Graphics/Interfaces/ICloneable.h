#ifndef ICLONEABLE_H
#define ICLONABLE_H

class ICloneable {
public:
	virtual ICloneable* clone() const = 0;
};

#endif // !ICLONEABLE_H
