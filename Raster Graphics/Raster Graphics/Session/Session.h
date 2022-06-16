#ifndef SESSION_H
#define SESSION_H

#include "../PolymorphicVector/PolymorphicVector.h"
#include "../Image/Image.h"
#include "../Command/Command.h"

class Session {
public:
	static int sIdCounter;

public:
	Session();

	int getId() const;

	void addImage(Image* image);

	void rotate(std::string& direction);

	void grayscale();

	void saveChanges();
	void saveAs(const std::string& fileName);

	void close();

	// TODO: Method that cheks if there are unsaved changes

private:
	int nId;
	PolymorphicVector<Image> m_images;

	void saveImageToFile(Image* image, const std::string& fileName);
};

#endif // !SESSION_H
