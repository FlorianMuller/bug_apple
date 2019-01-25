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
# include "IMonitorDisplay.hpp"
# include "IDisplayBox.hpp"
# include "BoxRegistry.hpp"
# include "ABoxData.hpp"
# include <list>
# include <algorithm>
# include <functional>


template < typename Display >
class ADisplay : public IMonitorDisplay {

	public:

		ADisplay<Display>( void ) { }
		virtual ~ADisplay<Display>( void ) { }

		class DBox;

		template <typename Data>
			class Box : public ABox<Data>, public DBox {

				public:

					Box<Data>(unsigned int y, unsigned int x) : DBox(y, x) { }
					virtual ~Box<Data>( void ) { }

					Box<Data>(IMonitorModule const & source) :
						ABox<Data>(source) { }

					void	update( void );
					static IDisplayBox *	generate(
							IMonitorModule const & module) {
						return new Box<Data>(module);
					}

				private:

						Box<Data> ( void );
						Box<Data> ( Box<Data> const & );
						Box<Data> & operator=( Box<Data> const & );

			};

		virtual	void update( void ) const {
			for_each(std::begin(boxes), std::end(boxes),
					std::mem_fun(&IDisplayBox::update));
		}

		virtual void customizeBox(ADisplay<Display>::DBox *box) = 0;

		void addModuleBox( IMonitorModule const & module) {

			IDisplayBox *	box = _registry.getBox(module);
			this->customizeBox(dynamic_cast<ADisplay<Display>::DBox *>(box));
			boxes.push_front(box);
		}


	protected:

		std::list<IDisplayBox *>	boxes;

	private:

		// Coplien
		ADisplay<Display>( ADisplay<Display> const & );
		ADisplay<Display> & operator=( ADisplay<Display> const & );

		BoxRegistry<Display>	_registry;
};


#endif // ADISPLAY_HPP
