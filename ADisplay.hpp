/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:53:41 by                   #+#    #+#             */
/*   Updated: 2019/01/20 21:06:56 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADISPLAY_HPP
# define ADISPLAY_HPP
# include "ABoxData.hpp"

template < typename Display >
class ADisplay {

	public:

		ADisplay<Display>( void ) { }
		virtual ~ADisplay<Display>( void ) { }

		class DBox;

		template <typename Data>
			class Box : public ABox<Data>, public DBox {

			};

};


#endif // ADISPLAY_HPP
