#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>

#if 0
int main(int argc, char const *argv[])
{
	boost::asio::io_service io;
	boost::asio::deadline_timer t( io, boost::posix_time::seconds(5) );
	t.wait();

	std::cout<<"Hello, World! \n";


	return 0;
}
#endif



#if 1
void print(const boost::system::error_code& /*e*/)
{
	std::cout<< "Hello , World !" <<std::endl; 

}


int main(int argc, char const *argv[])
{
	
	boost::asio::io_service io;
	boost::asio::deadline_timer t( io, boost::posix_time::seconds(10) );
	t.async_wait(&print);

	std::cout<< "Here1" <<std::endl;
	io.run();
	std::cout<< "Here2" <<std::endl;


	return 0;
}

#endif


#if 0


void print( const boost::system::error_code& err )
{
	if (err)
	{			
		/* code */
		std::cout << "Timer is canceled \n";
		return;
	}


}

int main(int argc, char const *argv[])
{
	boost::asio::io_service io;

	boost::asio::deadline_timer timer( io, boost::posix_time::seconds(5) );
	timer.async_wait(&print);

	boost::asio::deadline_timer timer2( io, boost::posix_time::seconds(2) );
	timer2.wait();

	timer.cancel();

	io.run();



	return 0;
}

#endif


