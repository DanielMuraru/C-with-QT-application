#include <string>

class DTO
{
private:
	std::string tip;
	int count = 0;


public:
	DTO() = default;
	DTO(std::string tip2,int count) :tip(tip2),count(count) {}
	int get_nr() const;
	//void set_tip(std::string);
	void increment();



};