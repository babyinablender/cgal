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
// source        : predicates_on_pointsH3.fw
// file          : predicates_on_pointsH3.h
// package       : H3 (2.14)
// maintainer    : Stefan Schirra <stschirr@mpi-sb.mpg.de>
// revision      : 2.14
// revision_date : 15 Oct 2000 
// author(s)     : Stefan Schirra
//
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra@mpi-sb.mpg.de>)
// ======================================================================
 

#ifndef CGAL_PREDICATES_ON_POINTSH3_H
#define CGAL_PREDICATES_ON_POINTSH3_H

#ifndef CGAL_PVDH3_H
#include <CGAL/PVDH3.h>
#endif // CGAL_PVDH3_H

CGAL_BEGIN_NAMESPACE

template < class FT, class RT >
inline
bool
x_equal(const PointH3<FT,RT> &p,
        const PointH3<FT,RT> &q)
{ return p.x()*q.hw() == q.x()*p.hw(); }

template < class FT, class RT >
inline
bool
y_equal(const PointH3<FT,RT> &p,
        const PointH3<FT,RT> &q)
{ return p.y()*q.hw() == q.y()*p.hw(); }

template < class FT, class RT >
inline
bool
z_equal(const PointH3<FT,RT> &p,
        const PointH3<FT,RT> &q)
{ return p.z()*q.hw() == q.z()*p.hw(); }

template < class FT, class RT>
CGAL_KERNEL_MEDIUM_INLINE
Comparison_result
compare_lexicographically_xyz(const PointH3<FT,RT>& p,
                                   const PointH3<FT,RT>& q)
{
  RT pV = p.hx()*q.hw();
  RT qV = q.hx()*p.hw();
  if ( pV < qV )
  {
      return SMALLER;
  }
  if ( qV < pV )    //   ( pV > qV )
  {
      return LARGER;
  }
  // same x
  pV = p.hy()*q.hw();
  qV = q.hy()*p.hw();
  if ( pV < qV )
  {
      return SMALLER;
  }
  if ( qV < pV )    //   ( pV > qV )
  {
      return LARGER;
  }
  // same x and y
  pV = p.hz()*q.hw();
  qV = q.hz()*p.hw();
  if ( pV < qV )
  {
      return SMALLER;
  }
  else
  {
      return (qV < pV) ? LARGER : EQUAL;
  }
}

template < class FT, class RT >
CGAL_KERNEL_MEDIUM_INLINE
bool
lexicographically_xyz_smaller_or_equal(const PointH3<FT,RT> &p,
                                            const PointH3<FT,RT> &q)
{
  RT pV = p.hx()*q.hw();
  RT qV = q.hx()*p.hw();
  if ( qV < pV )    //   ( pV > qV )
  {
      return false;
  }
  if ( !(pV == qV) )
  {
      return true;
  }
  // same x
  pV = p.hy()*q.hw();
  qV = q.hy()*p.hw();
  if ( qV < pV )    //   ( pV > qV )
  {
      return false;
  }
  if ( !(pV == qV) )
  {
      return true;
  }
  // same x and y
  pV = p.hz()*q.hw();
  qV = q.hz()*p.hw();
  if ( qV < pV )    //   ( pV > qV )
  {
      return false;
  }
  return true;
}

template < class FT, class RT >
CGAL_KERNEL_MEDIUM_INLINE
bool lexicographically_xyz_smaller(const PointH3<FT,RT> &p,
                                   const PointH3<FT,RT> &q)
{
  RT pV = p.hx()*q.hw();
  RT qV = q.hx()*p.hw();
  if ( pV < qV )
  {
      return true;
  }
  if ( qV < pV )
  {
      return false;
  }
  // same x
  pV = p.hy()*q.hw();
  qV = q.hy()*p.hw();
  if ( pV < qV )
  {
      return true;
  }
  if ( qV < pV )
  {
      return false;
  }
  // same x and y
  pV = p.hz()*q.hw();
  qV = q.hz()*p.hw();
  if ( pV < qV )
  {
      return true;
  }
  return false;
}

template < class FT, class RT >
CGAL_KERNEL_MEDIUM_INLINE
bool lexicographically_xy_smaller(const PointH3<FT,RT> &p,
                                  const PointH3<FT,RT> &q)
{
  RT pV = p.hx()*q.hw();
  RT qV = q.hx()*p.hw();
  if ( pV < qV )
  {
      return true;
  }
  if ( qV < pV )
  {
      return false;
  }
  // same x
  pV = p.hy()*q.hw();
  qV = q.hy()*p.hw();
  if ( pV < qV )
  {
      return true;
  }
  return false;
}

template < class FT, class RT>
CGAL_KERNEL_MEDIUM_INLINE
Comparison_result
compare_lexicographically_xy(const PointH3<FT,RT>& p,
                             const PointH3<FT,RT>& q)
{
  RT pV = p.hx()*q.hw();
  RT qV = q.hx()*p.hw();
  if ( pV < qV )
  {
      return SMALLER;
  }
  if ( qV < pV )    //   ( pV > qV )
  {
      return LARGER;
  }
  // same x
  pV = p.hy()*q.hw();
  qV = q.hy()*p.hw();
  if ( pV < qV )
  {
      return SMALLER;
  }
  if ( qV < pV )    //   ( pV > qV )
  {
      return LARGER;
  }
  // same x and y
  return EQUAL;
}

template < class FT, class RT >
inline
Comparison_result
compare_x(const PointH3<FT,RT> &p, const PointH3<FT,RT> &q)
{ return CGAL_NTS compare(p.hx() * q.hw(), q.hx() * p.hw() ); }

template < class FT, class RT >
inline
Comparison_result
compare_y(const PointH3<FT,RT> &p, const PointH3<FT,RT> &q)
{ return CGAL_NTS compare(p.hy() * q.hw(), q.hy() * p.hw() ); }

template < class FT, class RT >
inline
Comparison_result
compare_z(const PointH3<FT,RT> &p, const PointH3<FT,RT> &q)
{ return CGAL_NTS compare(p.hz() * q.hw(), q.hz() * p.hw() ); }

template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
equal_xy(const PointH3<FT,RT> &p, const PointH3<FT,RT> &q)
{
  return   (p.hx_ref() * q.hw_ref() == q.hx_ref() * p.hw_ref() )
        && (p.hy_ref() * q.hw_ref() == q.hy_ref() * p.hw_ref() );
}

template < class FT, class RT >  // ???  ->   ==
CGAL_KERNEL_INLINE
bool
equal_xyz(const PointH3<FT,RT> &p, const PointH3<FT,RT> &q)
{
  return   (p.hx_ref() * q.hw_ref() == q.hx_ref() * p.hw_ref() )
        && (p.hy_ref() * q.hw_ref() == q.hy_ref() * p.hw_ref() )
        && (p.hz_ref() * q.hw_ref() == q.hz_ref() * p.hw_ref() );
}

template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
less_x(const PointH3<FT,RT> &p, const PointH3<FT,RT> &q)
{ return   (p.hx_ref() * q.hw_ref() < q.hx_ref() * p.hw_ref() ); }


template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
less_y(const PointH3<FT,RT> &p, const PointH3<FT,RT> &q)
{ return   (p.hy_ref() * q.hw_ref() < q.hy_ref() * p.hw_ref() ); }

template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
less_z(const PointH3<FT,RT> &p, const PointH3<FT,RT> &q)
{ return   (p.hz_ref() * q.hw_ref() < q.hz_ref() * p.hw_ref() ); }


CGAL_END_NAMESPACE

#ifndef ORIENTATION_PREDICATESH3_H
#include <CGAL/orientation_predicatesH3.h>
#endif // ORIENTATION_PREDICATESH3_H
CGAL_BEGIN_NAMESPACE

template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
collinear(const PointH3<FT,RT> &p,
          const PointH3<FT,RT> &q,
          const PointH3<FT,RT> &r)
{
  DirectionH3<FT,RT> dir_pq = (p - q).direction();
  DirectionH3<FT,RT> dir_rq = (r - q).direction();

  return    ( dir_pq == dir_rq ) || (dir_pq == -dir_rq)
         || ( p == q ) || ( p == r ) || ( q == r ) ;
}

template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
are_ordered_along_line(const PointH3<FT,RT> &p,
                            const PointH3<FT,RT> &q,
                            const PointH3<FT,RT> &r)
{
  if (!collinear(p, q, r))
  {
       return false;
  }
  return collinear_are_ordered_along_line(p, q, r);
}

template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
collinear_are_ordered_along_line(const PointH3<FT,RT> &p,
                                      const PointH3<FT,RT> &q,
                                      const PointH3<FT,RT> &r)
{
  CGAL_kernel_exactness_precondition( collinear(p, q, r) );
  const RT phx = p.hx();
  const RT phw = p.hw();
  const RT qhx = q.hx();
  const RT qhw = q.hw();
  const RT rhx = r.hx();
  const RT rhw = r.hw();

  const RT pqx = phx*qhw;
  const RT qpx = qhx*phw;
  const RT prx = phx*rhw;
  const RT qrx = qhx*rhw;
  const RT rqx = rhx*qhw;
  const RT rpx = rhx*phw;

  if ( prx != rpx )   // px != rx
  {
                //    (px <= qx)&&(qx <= rx) || (px >= qx)&&(qx >= rx)
                // !(((qx <  px)||(rx <  qx))&&((px <  qx)||(qx <  rx)))
      return ! (   ((qpx < pqx) || (rqx < qrx))
                && ((pqx < qpx) || (qrx < rqx))  );
  }

  const RT phy = p.hy();
  const RT qhy = q.hy();
  const RT rhy = r.hy();

  const RT pqy = phy*qhw;
  const RT qpy = qhy*phw;
  const RT pry = phy*rhw;
  const RT qry = qhy*rhw;
  const RT rqy = rhy*qhw;
  const RT rpy = rhy*phw;

  if ( pry != rpy )
  {
      return ! (   ((qpy < pqy) || (rqy < qry))
                && ((pqy < qpy) || (qry < rqy))  );
  }

  const RT phz = p.hz();
  const RT qhz = q.hz();
  const RT rhz = r.hz();

  const RT pqz = phz*qhw;
  const RT qpz = qhz*phw;
  const RT prz = phz*rhw;
  const RT qrz = qhz*rhw;
  const RT rqz = rhz*qhw;
  const RT rpz = rhz*phw;

  if ( prz != rpz )
  {
      return ! (   ((qpz < pqz) || (rqz < qrz))
                && ((pqz < qpz) || (qrz < rqz))  );
  }
  // p == r
  return  ((rqx == qrx) && (rqy == qry) && (rqz == qrz));
}

template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
are_strictly_ordered_along_line(const PointH3<FT,RT> &p,
                                     const PointH3<FT,RT> &q,
                                     const PointH3<FT,RT> &r)
{
  if ( ! collinear(p, q, r) ) return false;
  return collinear_are_strictly_ordered_along_line( p, q, r);
}

template < class FT, class RT >
CGAL_KERNEL_INLINE
bool
collinear_are_strictly_ordered_along_line(const PointH3<FT,RT> &p,
                                               const PointH3<FT,RT> &q,
                                               const PointH3<FT,RT> &r)
{
  CGAL_kernel_exactness_precondition( collinear(p, q, r) );
  if ( p == r) return false;
  DirectionH3<FT,RT> dir_pq = (p - q).direction();
  DirectionH3<FT,RT> dir_rq = (r - q).direction();
  return (dir_pq == -dir_rq);
}



template < class FT, class RT >
CGAL_KERNEL_LARGE_INLINE
Oriented_side
side_of_oriented_sphere(const PointH3<FT,RT> &p,
                             const PointH3<FT,RT> &q,
                             const PointH3<FT,RT> &r,
                             const PointH3<FT,RT> &s,
                             const PointH3<FT,RT> &t)
{
  CGAL_kernel_precondition( !coplanar(p,q,r,s) );
  const RT phx = p.hx();
  const RT phy = p.hy();
  const RT phz = p.hz();
  const RT phw = p.hw();
  const RT phw2 = phw*phw;

  const RT qhx = q.hx();
  const RT qhy = q.hy();
  const RT qhz = q.hz();
  const RT qhw = q.hw();
  const RT qhw2 = qhw*qhw;

  const RT rhx = r.hx();
  const RT rhy = r.hy();
  const RT rhz = r.hz();
  const RT rhw = r.hw();
  const RT rhw2 = rhw*rhw;

  const RT shx = s.hx();
  const RT shy = s.hy();
  const RT shz = s.hz();
  const RT shw = s.hw();
  const RT shw2 = shw*shw;

  const RT thx = t.hx();
  const RT thy = t.hy();
  const RT thz = t.hz();
  const RT thw = t.hw();
  const RT thw2 = thw*thw;

  const RT det = det5x5_by_formula(
        phx*phw, phy*phw, phz*phw, phx*phx + phy*phy + phz*phz, phw2,
        qhx*qhw, qhy*qhw, qhz*qhw, qhx*qhx + qhy*qhy + qhz*qhz, qhw2,
        rhx*rhw, rhy*rhw, rhz*rhw, rhx*rhx + rhy*rhy + rhz*rhz, rhw2,
        shx*shw, shy*shw, shz*shw, shx*shx + shy*shy + shz*shz, shw2,
        thx*thw, thy*thw, thz*thw, thx*thx + thy*thy + thz*thz, thw2);
  if (det < RT(0))
  {
      return ON_POSITIVE_SIDE;
  }
  else
  {
      return (RT(0) < det) ? ON_NEGATIVE_SIDE : ON_ORIENTED_BOUNDARY;
  }
}

template < class FT, class RT >
CGAL_KERNEL_MEDIUM_INLINE
Bounded_side
side_of_bounded_sphere(const PointH3<FT,RT> &p,
                            const PointH3<FT,RT> &q,
                            const PointH3<FT,RT> &r,
                            const PointH3<FT,RT> &s,
                            const PointH3<FT,RT> &test)
{
  Oriented_side  oside = side_of_oriented_sphere(p,q,r,s,test);
  if ( are_positive_oriented( p,q,r,s) )
  {
    switch (oside)
    {
        case ON_POSITIVE_SIDE    :   return ON_BOUNDED_SIDE;
        case ON_ORIENTED_BOUNDARY:   return ON_BOUNDARY;
        case ON_NEGATIVE_SIDE    :   return ON_UNBOUNDED_SIDE;
    }
  }
  else
  {
    switch (oside)
    {
        case ON_POSITIVE_SIDE    :   return ON_UNBOUNDED_SIDE;
        case ON_ORIENTED_BOUNDARY:   return ON_BOUNDARY;
        case ON_NEGATIVE_SIDE    :   return ON_BOUNDED_SIDE;
    }
  }
  return ON_BOUNDARY;  // Pls, no warnings anylonger
}


CGAL_END_NAMESPACE


#endif // PREDICATES_ON_POINTSH3_H
