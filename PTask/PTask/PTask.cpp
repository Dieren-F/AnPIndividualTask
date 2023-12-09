#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PTask.h"

void openClients(std::vector<client>& clientsList) {
	std::ifstream file;
	unsigned int cnt = 0;
	std::string token;
	file.open("Clients.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			size_t pos = 0;
			int index = 0;
			clientsList.push_back({});
			while ((pos = line.find(',')) != std::string::npos) {
				token = line.substr(0, pos);
				switch (index) {
				case 0:
					clientsList[cnt].name = token;
					break;
				case 1:
					clientsList[cnt].number = token;
					break;
				case 2:
					clientsList[cnt].sdate = token;
					break;
				case 3:
					clientsList[cnt].edate = token;
					break;
				case 4:
					clientsList[cnt].debt = stod(token);
					break;
				case 5:
					clientsList[cnt].credit = stod(token);
					break;
				}
				line.erase(0, pos + 1);
				index++;
			}


			cnt++;
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

void openTariffs(std::vector<tariff>& tariffList) {
	std::ifstream file;
	unsigned int cnt = 0;
	std::string token;
	file.open("Tariffs.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			size_t pos = 0;
			int index = 0;
			tariffList.push_back({});
			while ((pos = line.find(',')) != std::string::npos) {
				token = line.substr(0, pos);
				switch (index) {
				case 0:
					tariffList[cnt].name = token;
					break;
				case 1:
					tariffList[cnt].id = stod(token);
					break;
				case 2:
					tariffList[cnt].rate = stod(token);
					break;
				case 3:
					tariffList[cnt].type = token;
					break;
				}
				line.erase(0, pos + 1);
				index++;
			}
			tariffList[cnt].type = line;
			cnt++;
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

void openUsedServices(std::vector<uses>& usedServicesList) {
	std::ifstream file;
	unsigned int cnt = 0;
	std::string token;
	file.open("UsedServices.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			size_t pos = 0;
			int index = 0;
			usedServicesList.push_back({});
			while ((pos = line.find(',')) != std::string::npos) {
				token = line.substr(0, pos);
				switch (index) {
				case 0:
					usedServicesList[cnt].number = token;
					break;
				case 1:
					usedServicesList[cnt].id = stod(token);
					break;
				case 2:
					usedServicesList[cnt].date = token;
					break;
				case 3:
					usedServicesList[cnt].timeused = stod(token);
					break;
				}
				line.erase(0, pos + 1);
				index++;
			}
			cnt++;
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

void openParam(std::vector<parameter>& parametersList) {
	std::ifstream file;
	unsigned int cnt = 0;
	std::string token;
	file.open("Param.ini");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			size_t pos = 0;
			int index = 0;
			parametersList.push_back({});
			while ((pos = line.find(',')) != std::string::npos) {
				token = line.substr(0, pos);
				switch (index) {
				case 0:
					parametersList[cnt].nameone = token;
					break;
				case 1:
					parametersList[cnt].nametwo = token;
					break;
				case 2:
					parametersList[cnt].sdate = token;
					break;
				}
				line.erase(0, pos + 1);
				index++;
			}
			parametersList[cnt].edate = line;
			cnt++;
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

bool checkIfInTime(std::string sdate, std::string edate, std::string date) {
	char discard;
	int day, month, year;
	int startDay, startMonth, startYear;
	int endDay, endMonth, endYear;

	std::stringstream ss1(sdate);
	ss1 >> startDay >> discard >> startMonth >> discard >> startYear;
	std::stringstream ss2(edate);
	ss2 >> endDay >> discard >> endMonth >> discard >> endYear;
	std::stringstream ss3(date);
	ss3 >> day >> discard >> month >> discard >> year;
	if (year > startYear && year < endYear) return true;
	else if (year == startYear || year == endYear) {
		if (month > startMonth && month < endMonth) return true;
		else if (month == startMonth || month == endMonth) {
			if (day >= startDay && day <= endDay) return true;
			else return false;
		}
	}
	return false;
}

int main() {
	std::setlocale(LC_ALL, "Russian");

	std::vector<client> clientsList;
	std::vector<tariff> tariffList;
	std::vector<uses> usedServicesList;
	std::vector<parameter> parametersList;

	openClients(clientsList);
	openTariffs(tariffList);
	openUsedServices(usedServicesList);
	openParam(parametersList);

	
	for (int i = 0; i != 4; i++) {
		std::cout << "Name: " << clientsList[i].name << std::endl;
		std::cout << "Number: " << clientsList[i].number << std::endl;
		std::cout << "Start Date: " << clientsList[i].sdate << std::endl;
		std::cout << "End Date: " << clientsList[i].edate << std::endl;
		std::cout << "Debt: " << clientsList[i].debt << std::endl;
		std::cout << "Credit: " << clientsList[i].credit << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i != 5; i++) {
		std::cout << "Name: " << tariffList[i].name << std::endl;
		std::cout << "ID: " << tariffList[i].id << std::endl;
		std::cout << "Rate: " << tariffList[i].rate << std::endl;
		std::cout << "Type: " << tariffList[i].type << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i != 3; i++) {
		std::cout << "Number: " << usedServicesList[i].number << std::endl;
		std::cout << "ID: " << usedServicesList[i].id << std::endl;
		std::cout << "Date of use: " << usedServicesList[i].date << std::endl;
		std::cout << "Time used: " << usedServicesList[i].timeused << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i != 2; i++) {
		std::cout << "name one: " << parametersList[i].nameone << std::endl;
		std::cout << "name two: " << parametersList[i].nametwo << std::endl;
		std::cout << "Start Date: " << parametersList[i].sdate << std::endl;
		std::cout << "End Date: " << parametersList[i].edate << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	for (int i = 0; i != 3; i++) {
		std::cout << parametersList[i].sdate << std::endl;
		std::cout << parametersList[i].edate << std::endl;
		std::cout << usedServicesList[i].date << std::endl;
		if (checkIfInTime(parametersList[i].sdate, parametersList[i].edate, usedServicesList[i].date)) std::cout << "True" << std::endl;
		else std::cout << "False" << std::endl;
	}
	

	std::ofstream file("Report.txt");
	if (file.is_open()) {
		for (int y = 0; y < parametersList.size(); y++) {
			for (int i = 0; i < clientsList.size(); i++) {
				for (int j = 0; j < usedServicesList.size(); j++) {
					if (clientsList[i].number == usedServicesList[j].number) {
						for (int e = 0; e < tariffList.size(); e++) {
							if (usedServicesList[j].id == tariffList[e].id && 
								(tariffList[e].name==parametersList[y].nameone || tariffList[e].name == parametersList[y].nametwo) &&
								checkIfInTime(parametersList[y].sdate, parametersList[y].edate, usedServicesList[j].date)) {
								file << clientsList[i].name << std::endl;
							}
						}
					}
				}
			}
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file";
	}

	return 0;
}