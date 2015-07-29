//
// VarIterator.h
//
// $Id: //poco/Main/Foundation/include/Poco/Dynamic/VarIterator.h#1 $
//
// Library: Foundation
// Package: Dynamic
// Module:  VarIterator
//
// Definition of the VarIterator class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_VarIterator_INCLUDED
#define Foundation_VarIterator_INCLUDED


#include "Poco/Exception.h"
#include <iterator>
#include <algorithm>


namespace Poco {
namespace Dynamic {


class Var;


class Foundation_API VarIterator
	/// VarIterator class.
{
public:
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef Var                             value_type;
	typedef std::ptrdiff_t                  difference_type;
	typedef Var*                            pointer;
	typedef Var&                            reference;

	static const int POSITION_END;
		/// End position indicator.

	VarIterator(Var* pVar, bool positionEnd);
		/// Creates the VarIterator and positions it at the end of
		/// the recordset if positionEnd is true. Otherwise, it is
		/// positioned at the beginning.

	VarIterator(const VarIterator& other);
		/// Creates a copy of other VarIterator.

	~VarIterator();
		/// Destroys the VarIterator.

	VarIterator& operator = (const VarIterator& other);
		/// Assigns the other VarIterator.

	bool operator == (const VarIterator& other) const;
		/// Equality operator.

	bool operator != (const VarIterator& other) const;
		/// Inequality operator.

	Var& operator * () const;
		/// Returns value at the current position.

	Var* operator -> () const;
		/// Returns pointer to the value at current position.

	const VarIterator& operator ++ () const;
		/// Advances by one position and returns current position.

	VarIterator operator ++ (int) const;
		/// Advances by one position and returns copy of the iterator with 
		/// previous current position.

	const VarIterator& operator -- () const;
		/// Goes back by one position and returns copy of the iterator with 
		/// previous current position.

	VarIterator operator -- (int) const;
		/// Goes back by one position and returns previous current position.

	VarIterator operator + (std::size_t diff) const;
		/// Returns a copy the VarIterator advanced by diff positions.

	VarIterator operator - (std::size_t diff) const;
		/// Returns a copy the VarIterator backed by diff positions.
		/// Throws RangeException if diff is larger than current position.

	void swap(VarIterator& other);
		/// Swaps the VarIterator with another one.

private:
	VarIterator();

	void increment() const;
		/// Increments the iterator position by one. 
		/// Throws RangeException if position is out of range.

	void decrement() const;
		/// Decrements the iterator position by one. 
		/// Throws RangeException if position is out of range.

	void setPosition(std::size_t pos) const;
		/// Sets the iterator position. 
		/// Throws RangeException if position is out of range.

	Var*                _pVar;
	mutable std::size_t _position;

	friend class Var;
};


///
/// inlines
///


inline bool VarIterator::operator == (const VarIterator& other) const
{
	return _pVar == other._pVar && _position == other._position;
}


inline bool VarIterator::operator != (const VarIterator& other) const
{
	return _pVar != other._pVar || _position != other._position;
}


} } // namespace Poco::Dynamic


namespace std
{
	using std::swap;
	template<>
	inline void swap<Poco::Dynamic::VarIterator>(Poco::Dynamic::VarIterator& s1, 
		Poco::Dynamic::VarIterator& s2)
		/// Full template specalization of std:::swap for VarIterator
	{
		s1.swap(s2);
	}
}


#endif // Foundation_VarIterator_INCLUDED