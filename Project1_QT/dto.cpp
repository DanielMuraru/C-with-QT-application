#include "dto.h"

int DTO::get_nr() const
{

	return count;
}
//void DTO::set_tip(std::string ot_tip)
//{
//	tip = ot_tip;
//}
void DTO::increment()
{
	count++;
}