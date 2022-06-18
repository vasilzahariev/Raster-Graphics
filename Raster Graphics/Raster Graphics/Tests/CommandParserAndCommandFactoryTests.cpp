#include "doctest.h"
#include "../Command/CommandParser.h"

TEST_CASE("Command Parser and Command Factory") {
	SessionMaster sessionMaster;
	sessionMaster.addSession(Session());

	SUBCASE("Open Command") {
		Command* cmd = CommandParser::parseCommandLine("open       \"image1.ppm\"", &sessionMaster);

		REQUIRE(dynamic_cast<OpenCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Rotate Command") {
		Command* cmd = CommandParser::parseCommandLine("rotate   left   ", &sessionMaster);

		REQUIRE(dynamic_cast<RotateCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Grayscale Command") {
		Command* cmd = CommandParser::parseCommandLine("GraYsCaLe", &sessionMaster);

		REQUIRE(dynamic_cast<GrayscaleCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Monocrhome Command") {
		Command* cmd = CommandParser::parseCommandLine("monochrome", &sessionMaster);

		REQUIRE(dynamic_cast<MonochromeCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Negative Command") {
		Command* cmd = CommandParser::parseCommandLine("negative", &sessionMaster);

		REQUIRE(dynamic_cast<NegativeCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Add Command") {
		Command* cmd = CommandParser::parseCommandLine("add \"cool img.ppm\"", &sessionMaster);

		REQUIRE(dynamic_cast<AddCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Save Command") {
		Command* cmd = CommandParser::parseCommandLine("save", &sessionMaster);

		REQUIRE(dynamic_cast<SaveCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("SaveAs Command") {
		Command* cmd = CommandParser::parseCommandLine("saveAs bigImg.pgm", &sessionMaster);

		REQUIRE(dynamic_cast<SaveAsCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Close Command") {
		Command* cmd = CommandParser::parseCommandLine("close", &sessionMaster);

		REQUIRE(dynamic_cast<CloseCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Undo Command") {
		Command* cmd = CommandParser::parseCommandLine("undo", &sessionMaster);

		REQUIRE(dynamic_cast<UndoCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Help Command") {
		Command* cmd = CommandParser::parseCommandLine("help", &sessionMaster);

		REQUIRE(dynamic_cast<HelpCommand*>(cmd) != nullptr);

		delete cmd;
	}

	SUBCASE("Invalid Command") {
		REQUIRE_THROWS_AS(CommandParser::parseCommandLine("open", &sessionMaster), CommandException);
	}

	SUBCASE("Invalid Command 2") {
		REQUIRE_THROWS_AS(CommandParser::parseCommandLine("open \"file.ppm", &sessionMaster), CommandException);
	}

	SUBCASE("Invalid Command 3") {
		REQUIRE_THROWS_AS(CommandParser::parseCommandLine("kur", &sessionMaster), CommandException);
	}
}
