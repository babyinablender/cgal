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
// source        : predicates_on_points_3.fw
// file          : predicates_on_points_3.h
// package       : _3 (3.9)
// maintainer    : Stefan Schirra <stschirr@mpi-sb.mpg.de>
// revision      : 3.9
// revision_date : 15 Oct 2000 
// author(s)     : Andreas Fabri
//                 Stefan Schirra
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra@mpi-sb.mpg.de>)
// ======================================================================
 

#ifndef CGAL_PREDICATES_ON_POINTS_3_H
#define CGAL_PREDICATES_ON_POINTS_3_H

#ifndef CGAL_REP_CLASS_DEFINED
#error  no representation class defined
#endif  // CGAL_REP_CLASS_DEFINED

#ifdef CGAL_HOMOGENEOUS_H
#ifndef PREDICATES_ON_POINTSH3_H
#include <CGAL/predicates_on_pointsH3.h>
#endif // PREDICATES_ON_POINTSH3_H
#endif // CGAL_HOMOGENEOUS_H

#ifdef CGAL_CARTESIAN_H
#ifndef CGAL_PREDICATES_ON_POINTSC3_H
#include <CGAL/Cartesian/predicates_on_points_3.h>
#endif // CGAL_PREDICATES_ON_POINTSC3_H
#endif // CGAL_CARTESIAN_H

#ifdef CGAL_SIMPLE_CARTESIAN_H
#include <CGAL/SimpleCartesian/predicates_on_pointsS3.h>
#endif // CGAL_SIMPLE_CARTESIAN_H


#ifndef CGAL_POINT_3_H
#include <CGAL/Point_3.h>
#endif // CGAL_POINT_3_H

CGAL_BEGIN_NAMESPACE

template < class R >
inline
Comparison_result
compare_lexicographically_xyz( const Point_3<R> &p,
                               const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return compare_lexicographically_xyz((const RPoint_3& )p,
                                       (const RPoint_3& )q);
}

template < class R >
inline
bool
lexicographically_xyz_smaller_or_equal(const Point_3<R> &p,
                                       const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return ( !( compare_lexicographically_xyz((const RPoint_3& )p,
                                            (const RPoint_3& )q)
              == LARGER ) );
}

template < class R >
inline
bool
lexicographically_xyz_smaller(const Point_3<R> &p,
                              const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return ( compare_lexicographically_xyz((const RPoint_3& )p,
                                         (const RPoint_3& )q)
           == SMALLER );
}

template < class R >
inline
Comparison_result
compare_x(const Point_3<R> &p, const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return compare_x((const RPoint_3& )p, (const RPoint_3& )q);
}


template < class R >
inline
Comparison_result
compare_y(const Point_3<R> &p, const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return compare_y((const RPoint_3& )p, (const RPoint_3& )q);
}


template < class R >
inline
Comparison_result
compare_z(const Point_3<R> &p, const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return compare_z((const RPoint_3& )p, (const RPoint_3& )q);
}

template < class R >
inline
bool
x_equal(const Point_3<R> &p,
        const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return x_equal((const RPoint_3& )p, (const RPoint_3& )q);
}

template < class R >
inline
bool
y_equal(const Point_3<R> &p,
        const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return y_equal((const RPoint_3& )p, (const RPoint_3& )q);
}

template < class R >
inline
bool
z_equal(const Point_3<R> &p,
        const Point_3<R> &q)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return z_equal((const RPoint_3& )p, (const RPoint_3& )q);
}

template < class R >
inline
bool
coplanar(const Point_3<R> &p,
         const Point_3<R> &q,
         const Point_3<R> &r,
         const Point_3<R> &s)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return ( coplanar((const RPoint_3& )p, (const RPoint_3& )q,
                         (const RPoint_3& )r, (const RPoint_3& )s) );
}

template < class R >
inline
bool
collinear(const Point_3<R> &p,
          const Point_3<R> &q,
          const Point_3<R> &r)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return (collinear((const RPoint_3& )p,
                    (const RPoint_3& )q,
                    (const RPoint_3& )r));
}

template < class R >
inline
bool
are_ordered_along_line(const Point_3<R> &p,
                       const Point_3<R> &q,
                       const Point_3<R> &r)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return (are_ordered_along_line((const RPoint_3& )p,
                                 (const RPoint_3& )q,
                                 (const RPoint_3& )r));
}

template < class R >
inline
bool
collinear_are_ordered_along_line(const Point_3<R> &p,
                                 const Point_3<R> &q,
                                 const Point_3<R> &r)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return collinear_are_ordered_along_line((const RPoint_3& )p,
                                          (const RPoint_3& )q,
                                          (const RPoint_3& )r
                                              );
}

template < class R >
inline
bool
are_strictly_ordered_along_line(const Point_3<R> &p,
                                const Point_3<R> &q,
                                const Point_3<R> &r)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return (are_strictly_ordered_along_line((const RPoint_3& )p,
                                          (const RPoint_3& )q,
                                          (const RPoint_3& )r));
}

template < class R >
inline
bool
collinear_are_strictly_ordered_along_line(const Point_3<R> &p,
                                          const Point_3<R> &q,
                                          const Point_3<R> &r)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return collinear_are_strictly_ordered_along_line((const RPoint_3& )p,
                                                   (const RPoint_3& )q,
                                                   (const RPoint_3& )r
                                              );
}

template < class R >
inline
Orientation
orientation(const Point_3<R> &p,
                 const Point_3<R> &q,
                 const Point_3<R> &r,
                 const Point_3<R> &s)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return orientation((const RPoint_3& )p, (const RPoint_3& )q,
                     (const RPoint_3& )r, (const RPoint_3& )s);
}

template <class R >
inline
Bounded_side
side_of_bounded_sphere( const Point_3<R> &p,
                        const Point_3<R> &q,
                        const Point_3<R> &r,
                        const Point_3<R> &s,
                        const Point_3<R> &test)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return side_of_bounded_sphere((const RPoint_3& )p,
                                (const RPoint_3& )q,
                                (const RPoint_3& )r,
                                (const RPoint_3& )s,
                                (const RPoint_3& )test);
}

template <class R >
inline
Oriented_side
side_of_oriented_sphere( const Point_3<R> &p,
                         const Point_3<R> &q,
                         const Point_3<R> &r,
                         const Point_3<R> &s,
                         const Point_3<R> &test)
{
  typedef typename  R::Point_3_base  RPoint_3;
  return side_of_oriented_sphere((const RPoint_3& )p,
                                 (const RPoint_3& )q,
                                 (const RPoint_3& )r,
                                 (const RPoint_3& )s,
                                 (const RPoint_3& )test);
}

CGAL_END_NAMESPACE


#endif // CGAL_PREDICATES_ON_POINTS_3_H
