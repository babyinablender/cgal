// ============================================================================
//
// Copyright (c) 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------------
// 
// release       :
// release_date  :
// 
// source        : Test.fw
// file          : _test_to_interval.h
// revision      : 4.2
// revision_date : 13 Dec 2000 
// author(s)     : Stefan Schirra
//
// maintainer    : Stefan Schirra <Stefan.Schirra@mpi-sb.mpg.de> 
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra@mpi-sb.mpg.de>)
// ============================================================================
 

#include <cassert>
template <class NT> bool test_to_interval(const NT& n);

template <class NT>
bool
test_to_interval(const NT& n)
{
  CGAL::Interval_base I = CGAL::to_interval( NT(2) );
  assert( I.inf()<=2.0 && I.sup()>=2.0 );
  return true;
}
