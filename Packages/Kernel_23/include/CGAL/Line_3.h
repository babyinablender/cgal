// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
// 
// release       : 
// release_date  : 2000, October 15
// 
// source        : Line_3.fw
// file          : Line_3.h
// package       : _3 (3.9)
// maintainer    : Stefan Schirra <stschirr@mpi-sb.mpg.de>
// revision      : 3.9
// revision_date : 15 Oct 2000 
// author(s)     : Andreas Fabri
//                 Stefan Schirra
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra@mpi-sb.mpg.de>)
// ======================================================================
 


#ifndef CGAL_LINE_3_H
#define CGAL_LINE_3_H

#ifndef CGAL_REP_CLASS_DEFINED
#error  no representation class defined
#endif  // CGAL_REP_CLASS_DEFINED

#ifdef CGAL_HOMOGENEOUS_H
#ifndef CGAL_LINEH3_H
#include <CGAL/LineH3.h>
#endif // CGAL_LINEH3_H
#endif // CGAL_HOMOGENEOUS_H

#ifdef CGAL_CARTESIAN_H
#ifndef CGAL_LINEC3_H
#include <CGAL/Cartesian/Line_3.h>
#endif // CGAL_LINEC3_H
#endif // CGAL_CARTESIAN_H

#ifdef CGAL_SIMPLE_CARTESIAN_H
#include <CGAL/SimpleCartesian/LineS3.h>
#endif // CGAL_SIMPLE_CARTESIAN_H


#ifndef CGAL_SEGMENT_3_H
#include <CGAL/Segment_3.h>
#endif // CGAL_SEGMENT_3_H
#ifndef CGAL_POINT_3_H
#include <CGAL/Point_3.h>
#endif // CGAL_POINT_3_H
#ifndef CGAL_RAY_3_H
#include <CGAL/Ray_3.h>
#endif // CGAL_RAY_3_H

CGAL_BEGIN_NAMESPACE

template <class R_>
class Line_3 : public R_::Line_3_base
{
public:
  typedef          R_                       R;
  typedef typename R::RT                    RT;
  typedef typename R::FT                    FT;
  typedef typename R::Line_3_base  RLine_3;

  Line_3() : RLine_3()
  {}
  Line_3(const CGAL::Line_3<R>  & l) : RLine_3( ( const RLine_3&  )l)
  {}
  Line_3(const CGAL::Point_3<R> & p,
              const CGAL::Point_3<R> & q) : RLine_3(p,q)
  {}
  // conversion impl -> interface class
  Line_3(const RLine_3&  l) : RLine_3(l)
  {}
  Line_3(const CGAL::Segment_3<R> & s) : RLine_3( s )
  {}
  Line_3(const CGAL::Ray_3<R> & r) : RLine_3( r )
  {}
  Line_3(const CGAL::Point_3<R> & p,
              const CGAL::Direction_3<R> & d) : RLine_3( p, d )
  {}

  bool                operator==(const CGAL::Line_3<R> & l) const
  { return RLine_3::operator==(l); }

  bool                operator!=(const CGAL::Line_3<R> & l) const
  { return !(*this == l); }

  CGAL::Plane_3<R>     perpendicular_plane(const CGAL::Point_3<R> & p) const
  { return RLine_3::perpendicular_plane(p); }

  CGAL::Line_3<R>      opposite() const
  { return RLine_3::opposite(); }

  CGAL::Point_3<R>     point() const
  { return RLine_3::point(); }

  CGAL::Point_3<R>     point(int i) const
  { return RLine_3::point(i); }

  CGAL::Point_3<R>     projection(const CGAL::Point_3<R>& p) const
  { return RLine_3::projection(p); }

  CGAL::Direction_3<R> direction() const
  { return RLine_3::direction(); }

  bool                has_on(const CGAL::Point_3<R>& p) const
  { return RLine_3::has_on(p); }

  bool                is_degenerate() const
  { return RLine_3::is_degenerate(); }

  CGAL::Line_3<R>      transform(const CGAL::Aff_transformation_3<R> & t) const
  { return RLine_3::transform(t); }
};

#ifndef NO_OSTREAM_INSERT_LINE_3
template < class R >
std::ostream&
operator<<(std::ostream& os, const Line_3<R>& l)
{
  typedef typename  R::Line_3_base  RLine_3;
  return os << (const RLine_3& )l;
}
#endif // NO_OSTREAM_INSERT_LINE_3

#ifndef NO_ISTREAM_EXTRACT_LINE_3
template < class R >
std::istream&
operator>>(std::istream & is, Line_3<R> & p)
{
  typedef typename  R::Line_3_base  RLine_3;
  is >> ( RLine_3&  )p;
  return is;
}
#endif // NO_ISTREAM_EXTRACT_LINE_3

CGAL_END_NAMESPACE


#ifndef CGAL_PLANE_3_H
#include <CGAL/Plane_3.h>
#endif // CGAL_PLANE_3_H

#endif // CGAL_LINE_3_H
