
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
// release_date  : 2000, December 10
// 
// source        : webmisc/kernel_to_kernel.fw
// file          : include/CGAL/kernel_to_kernel.h
// package       : Kernel_basic (3.17)
// maintainer    : Stefan Schirra <stschirr@mpi-sb.mpg.de>
// revision      : 3.17
// revision_date : 10 Dec 2000 
// author(s)     : Stefan Schirra
//
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra@mpi-sb.mpg.de>)
// ======================================================================
 

#ifdef CGAL_USE_LEDA
#include <CGAL/leda_integer.h>
#include <LEDA/rat_point.h>
#endif // CGAL_USE_LEDA

namespace CGAL {

template <class NumberType>
struct Cartesian_double_to_Homogeneous
{
  typedef Point_2< Homogeneous< NumberType> >    Point2;
  typedef Segment_2< Homogeneous< NumberType> >  Segment;

  Point2
  operator()(  const Point_2<Cartesian<double> >& p)
  { return Point2( NumberType(p.x()), NumberType(p.y()) ); }

  Segment
  operator()(  const Segment_2<Cartesian<double> >& s)
  {
    return Segment( Point2( NumberType(s.source().x()),
                            NumberType(s.source().y()) ),
                    Point2( NumberType(s.target().x()),
                            NumberType(s.target().y()) ) );
  }
};


template <class NumberType>
struct Cartesian_double_to_Cartesian
{
  typedef Point_2< Cartesian< NumberType> >    Point2;
  typedef Point_3< Cartesian< NumberType> >    Point3;
  typedef Segment_2< Cartesian< NumberType> >  Segment;

  Point2
  operator()(  const Point_2<Cartesian<double> >& p)
  { return Point2( NumberType(p.x()), NumberType(p.y()) ); }

  Point3
  operator()(  const Point_3<Cartesian<double> >& p)
  { return Point3( NumberType(p.x()),
                   NumberType(p.y()),
                   NumberType(p.z()) ); }

  Segment
  operator()(  const Segment_2<Cartesian<double> >& s)
  {
    return Segment( Point2( NumberType(s.source().x()),
                            NumberType(s.source().y()) ),
                    Point2( NumberType(s.target().x()),
                            NumberType(s.target().y()) ) );
  }
};

template <class NumberType>
struct Cartesian_float_to_Cartesian
{
  typedef Point_2< Cartesian< NumberType> >    Point2;
  typedef Segment_2< Cartesian< NumberType> >  Segment;

  Point2
  operator()(  const Point_2<Cartesian<float> >& p)
  { return Point2( NumberType(p.x()), NumberType(p.y()) ); }

  Segment
  operator()(  const Segment_2<Cartesian<float> >& s)
  {
    return Segment( Point2( NumberType(s.source().x()),
                            NumberType(s.source().y()) ),
                    Point2( NumberType(s.target().x()),
                            NumberType(s.target().y()) ) );
  }
};


#ifdef CGAL_USE_LEDA
struct Cartesian_double_to_H_double_int
{
  typedef Point_2< Homogeneous< double> >    Point2;
  typedef Segment_2< Homogeneous< double> >  Segment;

  Segment
  operator()(  const Segment_2< Cartesian< double> >& s)
  {
    leda_rat_point rs =  leda_point(s.source().x(), s.source().y());
    leda_rat_point rt =  leda_point(s.target().x(), s.target().y());

    return
    Segment(
      Point2(::to_double(rs.X()),::to_double(rs.Y()),::to_double(rs.W())),
      Point2(::to_double(rt.X()),::to_double(rt.Y()),::to_double(rt.W())) );
  }
};

struct Cartesian_float_to_H_double_int
{
  typedef Point_2< Homogeneous< double> >    Point2;
  typedef Segment_2< Homogeneous< double> >  Segment;

  Segment
  operator()(  const Segment_2< Cartesian< float> >& s)
  {
    leda_rat_point rs =  leda_point(s.source().x(), s.source().y());
    leda_rat_point rt =  leda_point(s.target().x(), s.target().y());

    return
    Segment(
      Point2(::to_double(rs.X()),::to_double(rs.Y()),::to_double(rs.W())),
      Point2(::to_double(rt.X()),::to_double(rt.Y()),::to_double(rt.W())) );
  }
};
#endif // CGAL_USE_LEDA

} // namespace CGAL
