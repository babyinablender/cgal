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
// source        : basic.fw
// file          : known_bit_size_integers.h
// package       : Kernel_basic (3.17)
// maintainer    : Stefan Schirra <stschirr@mpi-sb.mpg.de>
// revision      : 3.17
// revision_date : 10 Dec 2000 
// author(s)     : Lutz Kettner
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra@mpi-sb.mpg.de>)
// ======================================================================
 

#ifndef CGAL_KNOWN_BIT_SIZE_INTEGERS_H
#define CGAL_KNOWN_BIT_SIZE_INTEGERS_H
CGAL_BEGIN_NAMESPACE


#if (defined(__sparc__) || defined(__sparc) || defined(sparc)) || \
    (defined(__sgi__)   || defined(__sgi)   || defined(sgi)) || \
    (defined(__i386__)  || defined(__i386)  || defined(i386)) || \
    (defined(__powerpc__) || defined(__powerpc) || defined(powerpc))
    typedef  signed char             Integer8;
    typedef  short                   Integer16;
    typedef  int                     Integer32;
    typedef  unsigned char           UInteger8;
    typedef  unsigned short          UInteger16;
    typedef  unsigned int            UInteger32;
//  ANSI C++ does not support `long long'
//  typedef  long long int           Integer64;
//  typedef  unsigned long long int  UInteger64;
//  the above definitions for long long are now in file
//  include/CGAL/long_long.h and not included automatically anymore
#else
#  if defined(__BORLANDC__)
    typedef  __int8                  Integer8;
    typedef  __int16                 Integer16;
    typedef  __int32                 Integer32;
    typedef  __int64                 Integer64;
    typedef  unsigned __int8         UInteger8;
    typedef  unsigned __int16        UInteger16;
    typedef  unsigned __int32        UInteger32;
    typedef  unsigned __int64        UInteger64;
#  else
#  if defined(_MSC_VER)
    typedef  signed char             Integer8;
    typedef  short                   Integer16;
    typedef  int                     Integer32;
    typedef  __int64                 Integer64;
    typedef  unsigned char           UInteger8;
    typedef  unsigned short          UInteger16;
    typedef  unsigned int            UInteger32;
    typedef  unsigned __int64        UInteger64;
#  else
#    error "patch this"
#  endif
#  endif
#endif

CGAL_END_NAMESPACE

#endif // CGAL_KNOWN_BIT_SIZE_INTEGERS_H
