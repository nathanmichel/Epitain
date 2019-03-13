//
// EPITECH PROJECT, 2019
// Epicraft
// File description:
// Session
//

#include "Session.hpp"
#include "Manager.hpp"

std::string JSON = "{\"version\":{\"name\":\"1.13.2\",\"protocol\":404},\"players\":{\"max\":10,\"online\":0},\"description\":{\"extra\":[{\"text\":\"Localhost\",\"color\":\"red\",\"bold\":true},{\"text\":\" test\",\"color\":\"green\",\"bold\":false}],\"text\":\"\"},\"favicon\":\"data:image/png;base64,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\u003d\"}";

net::Session::Session(boost::asio::io_context &ioContext, net::TcpServer &server, mgr::Manager &manager) :
	_socket(ioContext),
	_server(server),
	_manager(manager),
	_id((std::size_t) &_socket)
{

}

void		net::Session::run()
{
	listen();
}

void		net::Session::listen()
{
	async_read(_socket, boost::asio::buffer((char *) NULL, 0),
		   boost::bind(&Session::handleRead, this,
			       boost::asio::placeholders::error));
}

void		net::Session::handleRead(const boost::system::error_code &e)
{
	int size = readVarInt();
	static int it = 0;

	if (size > 0) {
		it++;
		boost::system::error_code error;
		char *data = new char[size];

		boost::asio::read(_socket, boost::asio::buffer(data, size),
				  boost::asio::transfer_exactly(size), error);
		_manager.callback(data, size, _status);
		/*if (it == 2) {
			writeVarInt(JSON.size() + 1 + 2);
			_buffer[_i] = 0;
			_i++;
			writeVarInt(JSON.size());
			std::memcpy(_buffer + _i, JSON.c_str(), JSON.size());
			_i += JSON.size();
			boost::asio::write(_socket, boost::asio::buffer(_buffer, _i));
		} else if (it == 3) {
			_i = 0;
			writeVarInt(size);
			std::memcpy(_buffer + _i, data, size);
			_i += size;
			boost::asio::write(_socket, boost::asio::buffer(_buffer, _i));
			}*/
		listen();
	} else {
		_server.removeSession(_id);
	}
}

int		net::Session::readVarInt()
{
	boost::system::error_code error;
	unsigned char buffer;
	int numRead = 0;
	int result = 0;

	do {
		boost::asio::read(_socket, boost::asio::buffer(&buffer, 1),
				  boost::asio::transfer_exactly(1), error);
		if (error)
			return -1;
		int value = (buffer & 0b01111111);

		result = result | (value << (7 * numRead));
		numRead++;
		if (numRead > 5)
			return -1;
	} while ((buffer & 0b10000000) != 0);
	return result;
}

void		net::Session::writeVarInt(unsigned int value)
{
	do {
		unsigned char temp = (unsigned char) (value & 0b01111111);

		value >>= 7;
		if (value != 0) {
			temp |= 0b10000000;
		}
		//_buffer[_i] = temp;
		//_i++;
	} while (value != 0);
}

boost::asio::ip::tcp::socket	&net::Session::getSocket()
{
	return _socket;
}

std::size_t	net::Session::getId() const
{
	return _id;
}
