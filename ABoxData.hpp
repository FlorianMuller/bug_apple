/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABoxData.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:30:44 by                   #+#    #+#             */
/*   Updated: 2019/01/19 18:30:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABOXDATA_HPP
# define ABOXDATA_HPP

template <typename Data>
class ABox {

	public:

		virtual ~ABox<Data>( void ) { }

	private:

		ABox<Data>( void );
		ABox<Data>( ABox<Data> const & );
		ABox<Data> & operator=( ABox<Data> const & );
};

#endif // ABOXDATA_HPP
