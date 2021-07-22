#ifndef DATAIO_HPP
#define DATAIO_HPP


#include <fstream>
#include "String.hpp"
#include "Types.hpp"

using namespace std;



class DataOut
{
	public:
	
	virtual void Write(muchar * d, mulong size);
	
	virtual DataOut & operator << (mbool d);
	
	virtual DataOut & operator << (muchar d);
	
	virtual DataOut & operator << (mchar d);
	
	virtual DataOut & operator << (mushort d);
	
	virtual DataOut & operator << (mshort  d);
	
	virtual DataOut & operator << (muint d);
	
	virtual DataOut & operator << (mint d);
	
	virtual DataOut & operator << (mulong d);
	
	virtual DataOut & operator << (mlong d);
	
	virtual DataOut & operator << (mfloat d);
	
	virtual DataOut & operator << (mdouble d);
	
	virtual DataOut & operator << (String d);
	
	virtual DataOut & operator << (const mchar * d);
	
};

class DataIn
{
	public:
	virtual void Read(muchar * d, mulong size);
	
	virtual void ReadLine(String & d);
	
	virtual DataIn & operator >>(mbool & d);
	
	virtual DataIn & operator >>(muchar & d);
	
	virtual DataIn & operator >>(mchar & d);
	
	virtual DataIn & operator >>(mushort & d);
	
	virtual DataIn & operator >>(mshort & d);
	
	virtual DataIn & operator >>(muint & d);
	
	virtual DataIn & operator >>(mint & d);
	
	virtual DataIn & operator >>(mulong & d);
	
	virtual DataIn & operator >>(mlong& d);
	
	virtual DataIn & operator >>(mfloat & d);
	
	virtual DataIn & operator >>(mdouble & d);
	
	virtual DataIn & operator >>(String & d);
};

/*


in	input	File open for reading: the internal stream buffer supports input operations.
out	output	File open for writing: the internal stream buffer supports output operations.
binary	binary	Operations are performed in binary mode rather than text.
ate	at end	The output position starts at the end of the file.
app	append	All output operations happen at the end of the file, appending to its existing contents.

*/



class DataFileWriter: public DataOut
{
	String _name;
	public:
	ofstream file;
	
	DataFileWriter(String name, ios_base::openmode mode = ios::binary);
	
	void Write(muchar * d, mulong size);
	
	inline void Close();
	
};

class DataFileReader: public DataIn
{
	String _name;
	public:
	ifstream file;
	DataFileReader(String name, ios_base::openmode mode = ios::binary);
	
	virtual void Read(muchar * d, mulong size);
	
	virtual void ReadLine(String & d);
	
	inline void Close();
	
};


#define $datastream(T, COUT, CIN)\
friend DataOut & operator  << (DataOut & out, T & o)\
{\
	COUT\
	return out;\
}\
friend DataIn & operator >> (DataIn & in, T & o)\
{\
	CIN\
	return in;\
}



#endif