/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:36:23 by fcarranz          #+#    #+#             */
/*   Updated: 2025/04/02 20:23:48 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"
#include <exception>
#include <sys/socket.h>

Socket::Socket(void) {}

Socket::Socket(int port) : _reuseOpt(1) {
  _socketFd = socket(AF_INET, SOCK_STREAM, 0);

  if (_socketFd < 0) {
    exit(EXIT_FAILURE);
  } // or throw exception

  if (setsockopt(_socketFd, SOL_SOCKET, SO_REUSEADDR, &_reuseOpt, sizeof(int)) < 0) {
    perror("setsockopt failed");
    close(_socketFd);
    throw new std::exception;
  }

  std::memset(_addressIn, 0, sizeof(_addressIn));
  _addressIn.sin_family = AF_INET;
  _addressIn.sin_port = htons(_port);
  _addressIn.sin_addr.s_addr = INADDR_ANY;

  if (bind(_socketFd, (struct sockaddr *)&_addressIn, sizeof(_addressIn)) < 0) {
    perror("Socket bind failed");
    close(_socketFd);
    throw new std::exception;
  }
}

Socket::~Socket(void) { close(_socketFd); }
