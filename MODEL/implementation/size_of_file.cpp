#include "../header/size_of_file.h"

size_of_file::operator unsigned long long int() const
{
	return getByte();
}

unsigned long long int size_of_file::getByte() const
{
    return size;
}

unsigned long long int size_of_file::getKByte() const
{
	return getByte()/rapporto;
}

unsigned long long int size_of_file::getMByte() const
{
    return getByte()/(rapporto*rapporto);
}

unsigned long long int size_of_file::getGByte() const
{
    return getByte()/(rapporto*rapporto*rapporto);
}

size_of_file &size_of_file::operator =(const size_of_file& s2)
{
    size = s2.size;
    return *this;
}
