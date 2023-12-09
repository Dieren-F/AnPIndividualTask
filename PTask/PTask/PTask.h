#pragma once

struct client {
	std::string name;
	std::string number;
	std::string sdate;
	std::string edate;
	double debt;
	double credit;
};

struct tariff {
	std::string name;
	unsigned int id;
	double rate;
	std::string type;
};

struct uses {
	std::string number;
	unsigned int id;
	std::string date;
	unsigned int timeused;
};

struct parameter {
	std::string nameone;
	std::string nametwo;
	std::string sdate;
	std::string edate;
};