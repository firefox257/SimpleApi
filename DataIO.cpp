#ifndef DATAIO_CPP
#define DATAIO_CPP


#include <fstream>
#include "String.cpp"
#include "types.cpp"

using namespace std;

class dataout
{
	public:
	
	virtual void write(unsigned char * d, unsigned long long size)
	{
		//cout << "write size " << size el;
	}
	virtual dataout & operator << (bool d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (unsigned char d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (char d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (unsigned short d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (short  d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (unsigned int d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (int d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (unsigned long long d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (long long d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (float d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (double d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		write(ptr, sizeof(d));
		return (*this);
	}
	virtual dataout & operator << (String d)
	{
		unsigned long long size = d.size();
		if(size == 0)
		{
			write((unsigned char *)"", 1);
		}
		else
		{
			write((unsigned char*)d.cstr(), size+1);
		}
		return (*this);
	}
	virtual dataout & operator << (const char * d)
	{
		int size = 0;
		while(d[size] != 0) size++;
		write((unsigned char *)d, size+1);
		return (*this);
	}
	
	
	
	
	
	
	
};

class datain
{
	public:
	virtual void read(unsigned char * d, unsigned long long size)
	{
		//cout << "read size " << size el;
	}
	virtual void readLine(String & d)
	{
		//cout << "read line " el;
	}
	virtual datain & operator >>(bool & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(unsigned char & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(char & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(unsigned short & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(short & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(unsigned int & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(int & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(unsigned long long & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(long long & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(float & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(double & d)
	{
		unsigned char * ptr = (unsigned char *)&d;
		read(ptr, sizeof(d));
		return (*this);
	}
	virtual datain & operator >>(String & d)
	{
		readLine(d);
		return (*this);
	}
};



class datafilewrite: public dataout
{
	ofstream file;
	public:
	datafilewrite(String name)
	{
		file.open(name.cstr(), ios::binary);
	}
	void write(unsigned char * d, unsigned long long size)
	{
		file.write((char*)d, size);
	}
	inline void close()
	{
		file.close();
	}
};

class datafileread: public datain
{
	ifstream file;
	public:
	datafileread(String name)
	{
		file.open(name.cstr(), ios::binary);
	}
	virtual void read(unsigned char * d, unsigned long long size)
	{
		file.read((char*)d, size);
	}
	virtual void readLine(String & d)
	{
		string str;
		getline(file, str, '\0');
		d = str.c_str();
	}
	inline void close()
	{
		file.close();
	}
};







#endif
