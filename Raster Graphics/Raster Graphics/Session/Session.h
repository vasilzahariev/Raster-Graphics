#ifndef SESSION_H
#define SESSION_H

#include <iostream>

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
	void monochrome();
	void negative();

	void saveChanges();
	void saveAs(const std::string& fileName);

	void undo();

	void close();

	std::string info(std::ostream& out = std::cout) const;

	// TODO: Method that cheks if there are unsaved changes

private:
	int nId;
	PolymorphicVector<Image> m_images;
	std::vector<const std::string> m_unsavedChanges;

	void saveImageToFile(Image* image, const std::string& fileName);
};

#endif // !SESSION_H
