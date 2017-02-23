#ifndef SIZE_OF_FILE
#define SIZE_OF_FILE

class size_of_file
{
private:
    unsigned long long int size;
    static const unsigned short int rapporto = 1024;	//da modificare se si desidera il rapporto tra unita di 1000, come usata negli HDD
	
public:
    size_of_file(unsigned long long int si) : size(si) {}
    operator unsigned long long int() const;	//ritorna i byte, utile per confronti
	//tutti arrotondati per difetto
    unsigned long long int getByte() const;
    unsigned long long int getKByte() const;
    unsigned long long int getMByte() const;
    unsigned long long int getGByte() const;
    size_of_file& operator = (const size_of_file&);
	
};

#endif
