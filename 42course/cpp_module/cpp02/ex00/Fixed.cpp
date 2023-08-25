/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:25:39 by youngski          #+#    #+#             */
/*   Updated: 2023/06/09 17:59:53 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->Fixed_number = 0;
	this->row = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	this->Fixed_number = fixed.Fixed_number;
	this->row = fixed.row;
}

Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}
