/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:25:51 by youngski          #+#    #+#             */
/*   Updated: 2023/06/09 17:56:30 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int					Fixed_number;
		static const int	row;

	public :
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		//make copy assignment operator overload
		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif
