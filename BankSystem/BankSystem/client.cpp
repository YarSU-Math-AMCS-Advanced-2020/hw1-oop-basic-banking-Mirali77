#include "client.h"

//Сеттер айди
void Client::set_client_id(int id) {
	client_id = id;
}

//Конструктор физ.лица
Individual::Individual(string _name, string _surname, string _patronymic,
	Date _birth_date, string _phone_number)
{
	name = _name;
	surname = _surname;
	patronymic = _patronymic;
	if (patronymic == "") {
		has_patronymic = false;
	}
	else {
		has_patronymic = true;
	}
	birth_date = _birth_date;
	phone_number = _phone_number;
}

//Конструктор юр.лица
Buisness::Buisness(string _name, string _adress, string _service_phone_number) {
	name = _name;
	adress = _adress;
	service_phone_number = _service_phone_number;
}

//Вывод ифнормации физ.лица
void Individual::print_information() {
	cout << "Client's information: " << endl;
	cout << "Name, surname, patronymic: " << name << " " << surname << " " << patronymic << endl;
	cout << "Birthdate: " << birth_date.day << "." << birth_date.month << "." << birth_date.year << endl;
	cout << "Phone number: " << phone_number << endl;
}

//Вывод информации юр.лица
void Buisness::print_information() {
	cout << "Client's information: " << endl;
	cout << "Name: " << name << endl;
	cout << "Adress: " << adress << endl;
	cout << "Service phone number: " << service_phone_number << endl;
}