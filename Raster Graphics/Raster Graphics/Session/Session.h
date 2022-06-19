#pragma once

#include <iostream>

#include "../Image/Image.h"
#include "../ImageData/ImageVector.h"
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

	bool containsFile(std::string_view fileLocation) const;

	// TODO: Method that cheks if there are unsaved changes

private:
	int nId;
	ImageVector m_images;
	std::vector<std::string> m_unsavedChanges;

	void saveImageToFile(Image* image, const std::string& fileName);
};
