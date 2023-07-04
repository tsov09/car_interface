#include <iostream>
#include <string>


class Car_Interface {
protected:
	std::string motor_type;
	std::string battery;
	std::string wheel_type;
	int wheels_count;
public:
	virtual void set_motor_type(std::string motor) = 0;
	virtual void set_battery(std::string battery) = 0;
	virtual void set_wheel_type(std::string wheel_count) = 0;
	virtual void set_wheels_count(int count) = 0;
	virtual std::string get_motor_type() = 0;
	virtual std::string get_battery() = 0;
	virtual std::string get_wheel_type() = 0;
	virtual int get_wheels_count() = 0;
};

class Car : public Car_Interface {
	std::string name;
public:
	Car(std::string name) {
		this->set_name(name);
	}
	void set_name(std::string name) {
		this->name = name;
	}
	void set_motor_type(std::string motor) override{
		if (motor == "petrol" || motor == "diesel" || motor == "electrical") {
			this->motor_type = motor;
		}
	}
	void set_battery(std::string battery) override{
		if (battery == "acid" || battery == "base") {
			this->battery = battery;
		}
	}
	void set_wheel_type(std::string wheel_type) override {
		if (wheel_type == "hydraulic" || wheel_type == "elecrtical") {
			this->wheel_type = wheel_type;
		}
	}
	void set_wheels_count(int count) override {
		if (count >= 4 && count % 2 == 0) {
			this->wheels_count = count;
		}
	}
	std::string get_name() {
		return this->name;
	}
	std::string get_motor_type() override {
		return this->motor_type;
	}
	std::string get_battery() override {
		return this->battery;
	}
	std::string get_wheel_type() override {
		return this->wheel_type;
	}
	int get_wheels_count() override {
		return this->wheels_count;
	}
};




int main() {
	
	Car car("Mercedes ...");
	car.set_motor_type("petrol");
	car.set_battery("acid");
	car.set_wheel_type("hydraulic");
	car.set_wheels_count(4);

	std::cout << "Name: " << car.get_name() << ";" << std::endl;
	std::cout << "Motor type: " << car.get_motor_type() << ";" << std::endl;
	std::cout << "Battery type: " << car.get_battery() << ";" << std::endl;
	std::cout << "Wheel type: " << car.get_wheel_type() << ";" << std::endl;
	std::cout << "Wheels count: " << car.get_wheels_count() << ";" << std::endl;
	
	
	return 0;
}