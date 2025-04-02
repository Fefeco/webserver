/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:36:30 by fcarranz          #+#    #+#             */
/*   Updated: 2025/04/02 20:12:09 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <sys/socket.h>

class Socket {
public:
  Socket(int port);
  ~Socket(void);

private:
  Socket(void);
	int _socketFd;
	int _reuseOpt;
  struct sockaddr_in _addressIn;
};
