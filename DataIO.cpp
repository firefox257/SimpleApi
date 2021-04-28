#ifndef DATAIO_CPP
#define DATAIO_CPP


#include <fstream>
#include "String.cpp"
#include "Types.cpp"
#include "DataIO.hpp"

using namespace std;




	void DataOut::Write(muchar * d, mulong size)
	{
		//cout << "write size " << size el;
	}
	DataOut & DataOut::operator << (mbool d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (muchar d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (mchar d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (mushort d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (mshort  d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (muint d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (mint d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (mulong d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (mlong d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (mfloat d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (mdouble d)
	{
		muchar * ptr = (muchar *)&d;
		Write(ptr, sizeof(d));
		return (*this);
	}
	DataOut & DataOut::operator << (String d)
	{
		mulong size = d.Size();
		if(size == 0)
		{
			Write((muchar *)"", 1);
		}
		else
		{
			Write((muchar*)d.cstr(), size+1);
		}
		return (*this);
	}
	DataOut & DataOut::operator << (const mchar * d)
	{
		mint size = 0;
		while(d[size] != 0) size++;
		Write((muchar *)d, size+1);
		return (*this);
	}
	


	void DataIn::Read(muchar * d, mulong size)
	{
		
	}
	void DataIn::ReadLine(String & d)
	{
		
	}
	DataIn & DataIn::operator >>(mbool & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(muchar & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(mchar & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(mushort & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(mshort & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(muint & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(mint & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(mulong & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(mlong& d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(mfloat & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(mdouble & d)
	{
		muchar * ptr = (muchar *)&d;
		Read(ptr, sizeof(d));
		return (*this);
	}
	DataIn & DataIn::operator >>(String & d)
	{
		ReadLine(d);
		return (*this);
	}


/*


in	input	File open for reading: the internal stream buffer supports input operations.
out	output	File open for writing: the internal stream buffer supports output operations.
binary	binary	Operations are performed in binary mode rather than text.
ate	at end	The output position starts at the end of the file.
app	append	All output operations happen at the end of the file, appending to its existing contents.

*/




	DataFileWriter::DataFileWriter(String name, ios_base::openmode mode)
	{
		_name = name;
		
		file.open(name.cstr(), mode);
		
	}
	void DataFileWriter::Write(muchar * d, mulong size)
	{
		file.write((char*)d, size);
	}
	inline void DataFileWriter::Close()
	{
		file.close();
	}



	DataFileReader::DataFileReader(String name, ios_base::openmode mode)
	{
		_name = name;
		file.open(name.cstr(), mode);
	}
	void DataFileReader::Read(muchar * d, mulong size)
	{
		file.read((char*)d, size);
	}
	void DataFileReader::ReadLine(String & d)
	{
		string str;
		getline(file, str, '\0');
		d = str.c_str();
	}
	inline void DataFileReader::Close()
	{
		file.close();
	}





#endif