/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:36:30 by fcarranz          #+#    #+#             */
/*   Updated: 2025/04/01 11:45:07 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <sys/socket.h>
/*

void						Server::socketUp()
{
	_serverFd = socket(AF_INET, SOCK_STREAM, 0);
	_reuseOption = 1;
// Poder reutilizar el mismo puerto sin tener que esperar en caso de fallo del programa
	if (setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, &_reuseOption, sizeof(int)) == -1) {
		perror("setsockopt failed");
		close(_serverFd);
		throw new std::exception;
	}
	if (fcntl(_serverFd, F_SETFL, O_NONBLOCK) == -1) {
        perror("fcntl failed");
		close(_serverFd);
		throw new std::exception;
	}
// carga el host name y port en el addrinfo
// hints -> asignamos opciones de config
	memset(&_hints, 0, sizeof(_hints));
	_hints.ai_family = AF_INET;			// IPv4
	_hints.ai_socktype = SOCK_STREAM;	// TCP
	_hints.ai_flags = AI_PASSIVE;		// Para bind() (escuchar)
// con las opciones dadas en hints configura res
	int err = getaddrinfo(getHostName().c_str(), getPort().c_str(), &_hints, &_response);
	if (err) {
		std::cout << "error: getaddrinfo" << std::endl << gai_strerror(err) << std::endl;
		return ;
	}
// vincula fd del servidor al host name y port
	else if (bind(_serverFd, _response->ai_addr, _response->ai_addrlen) == -1) {
		std::cout << "error: bind" << std::endl;
		return ;
	}
// habilitamos el fd para que se quede escuchando
	if (listen(_serverFd, SOMAXCONN) == -1) {
		perror("listen failed");
		close(_serverFd);
		throw new std::exception;
	}
}
*/
class Socket {
public:
  Socket(void);
  Socket(int port);
  ~Socket(void);

private:
	int _socketFd;
};

/*
		//SocketUp
		int					_serverFd;
		int					_reuseOption;
		struct addrinfo*	_response;
		struct addrinfo		_hints;
*/
