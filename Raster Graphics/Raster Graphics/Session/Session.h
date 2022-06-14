#ifndef SESSION_H
#define SESSION_H

#include "../PolymorphicVector/PolymorphicVector.h"
#include "../Image/Image.h"

class Session {
public:
	static int sIdCounter;

public:
	Session();

	int getId() const;

	void addImage(Image* image);

	void grayscale();

private:
	int nId;
	PolymorphicVector<Image> m_images;
};

#endif // !SESSION_H
