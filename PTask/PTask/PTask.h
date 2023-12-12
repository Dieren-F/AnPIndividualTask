// header file

#pragma once

struct client {				// Struct for clients
	std::string name;		// Name of the client
	std::string number;		// Phone number of the client
	std::string sdate;		// Starting date of their subscription
	std::string edate;		// Ending date of their subscription
	double debt;			// Debt of the client
	double credit;			// Available credit
};

struct tariff {				// Struct for tariffs
	std::string name;		// Name of the tariff
	unsigned int id;		// ID of specific tariff
	double rate;			// Price per type
	std::string type;		// The frequency of payment for the tariff
};

struct uses {				// Struct for used tariffs
	std::string number;		// Phone number of the user
	unsigned int id;		// ID of the used tariff
	std::string date;		// Date of use (includes time of use)
	unsigned int timeused;	// How long the tariff was active
};

struct parameter {			// Struct for parameters of the programm
	std::string nameone;	// Name of the first tariff
	std::string nametwo;	// Name of the seccond tariff
	std::string sdate;		// Start of the timeframe
	std::string edate;		// End of the timeframe
};