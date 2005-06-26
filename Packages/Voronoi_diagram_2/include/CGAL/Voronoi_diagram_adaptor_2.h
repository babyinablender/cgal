// Copyright (c) 2005 Foundation for Research and Technology-Hellas (Greece).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $Source$
// $Revision$ $Date$
// $Name$
//
// Author(s)     : Menelaos Karavelas <mkaravel@tem.uoc.gr>

#ifndef CGAL_VORONOI_DIAGRAM_ADAPTOR_2_H
#define CGAL_VORONOI_DIAGRAM_ADAPTOR_2_H 1

#include <CGAL/Voronoi_diagram_adaptor_2/basic.h>
#include <CGAL/iterator.h>
#include <CGAL/circulator.h>

#include <iterator>
#include <vector>

#include <CGAL/Voronoi_diagram_adaptor_2/Halfedge.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Face.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Vertex.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Circulator_adaptors.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Iterator_adaptors.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Handle_adaptor.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Validity_testers.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Dummy_iterator.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Unbounded_faces.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Unbounded_edges.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Degeneracy_tester_binders.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Cached_degeneracy_testers.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Locate_type.h>
#include <CGAL/Voronoi_diagram_adaptor_2/Accessor.h>

CGAL_BEGIN_NAMESPACE


template<class DG, class Tr>
class Voronoi_diagram_adaptor_2
  : public CGAL_VORONOI_DIAGRAM_2_NS::Locate_type_accessor
  < Voronoi_diagram_adaptor_2<DG,Tr>, true>
{
 private:
  typedef Voronoi_diagram_adaptor_2<DG,Tr>   Self;
  typedef Triangulation_cw_ccw_2             CW_CCW_2;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Locate_type_accessor<Self,true> Base;

  friend struct CGAL_VORONOI_DIAGRAM_2_NS::Accessor<Self>;
 public:
  //-------
  // TYPES
  //-------

  // TYPES FOR THE DUAL GRAPH

  // the (triangulated) dual graph
  typedef DG                                   Dual_graph;
  typedef typename Dual_graph::Geom_traits     Geom_traits;  
  typedef Tr                                   Voronoi_traits;

  typedef typename Dual_graph::size_type       size_type;

  typedef typename Dual_graph::Vertex_handle   Dual_vertex_handle;
  typedef typename Dual_graph::Face_handle     Dual_face_handle;
  typedef typename Dual_graph::Edge            Dual_edge;

  typedef typename Dual_graph::Edge_circulator    Dual_edge_circulator;
  typedef typename Dual_graph::Vertex_circulator  Dual_vertex_circulator;
  typedef typename Dual_graph::Face_circulator    Dual_face_circulator;

  typedef typename Dual_graph::Finite_vertices_iterator 
  Dual_vertices_iterator;

  typedef typename Dual_graph::Finite_faces_iterator
  Dual_faces_iterator;

  typedef typename Dual_graph::Finite_edges_iterator
  Dual_edges_iterator;
  typedef typename Dual_graph::All_edges_iterator
  All_dual_edges_iterator;

  // POINT LOCATION RELATED TYPES
  typedef typename Voronoi_traits::Has_point_locator  Has_point_locator;
  typedef typename Voronoi_traits::Point_2            Point_2;

  // TYPES FOR THE DEGENERACY TESTERS
  typedef typename Voronoi_traits::Edge_degeneracy_tester
  Edge_degeneracy_tester;
  typedef typename Voronoi_traits::Face_degeneracy_tester
  Face_degeneracy_tester;

#ifndef VDA_NO_CACHED_TESTERS
 protected:
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Cached_edge_degeneracy_tester
  <Edge_degeneracy_tester>
  Cached_edge_degeneracy_tester;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Cached_face_degeneracy_tester
  <Face_degeneracy_tester>
  Cached_face_degeneracy_tester;
#endif

 protected:
  // DEGENERACY TESTER BINDERS
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Edge_degeneracy_tester_binder<Self>
  Edge_degeneracy_tester_binder;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Face_degeneracy_tester_binder<Self>
  Face_degeneracy_tester_binder;

  // ITERATORS FOR EDGES
  typedef Filter_iterator<Dual_edges_iterator,Edge_degeneracy_tester_binder>
  Non_degenerate_edges_iterator;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Edge_iterator_adaptor
  <Self,Non_degenerate_edges_iterator>
  Edge_iterator_base;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Edge_validity_tester
  <Self,Edge_iterator_base>
  Edge_validity_tester;

  typedef Filter_iterator<Edge_iterator_base,Edge_validity_tester>
  Valid_edges_iterator;

 public:
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Edge_iterator_adaptor
  <Self,Valid_edges_iterator,Tag_false>
  Edge_iterator;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Halfedge_iterator_adaptor
  <Self,Edge_iterator>
  Halfedge_iterator;

  // THE HALFEDGE
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Halfedge<Self>     Halfedge;

 protected:
  // ITERATORS FOR FACES
  typedef Filter_iterator<Dual_vertices_iterator,Face_degeneracy_tester_binder>
  Non_degenerate_faces_iterator;

 public:
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Face_iterator_adaptor
  <Self,Non_degenerate_faces_iterator>
  Face_iterator;

  // THE FACE
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Face<Self>         Face;

 protected:
  // ITERATORS FOR VERTICES
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Vertex_validity_tester<Self>
  Vertex_validity_tester;

  typedef Filter_iterator<Dual_faces_iterator,Vertex_validity_tester>
  Non_degenerate_vertices_iterator;

 public:
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Vertex_iterator_adaptor
  <Self,Non_degenerate_vertices_iterator>
  Vertex_iterator;

  // THE VERTEX
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Vertex<Self>       Vertex;

 public:
  // HANDLES
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Handle_adaptor<Halfedge>  Halfedge_handle;
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Handle_adaptor<Vertex>    Vertex_handle;
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Handle_adaptor<Face>      Face_handle;

  // CIRCULATORS
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Halfedge_around_vertex_circulator_adaptor
  <Halfedge>
  Halfedge_around_vertex_circulator;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Ccb_halfedge_circulator_adaptor
  <Halfedge>
  Ccb_halfedge_circulator;

  // THE HOLES ITERATOR
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Dummy_iterator<Ccb_halfedge_circulator>
  Holes_iterator;

  // THE BOUNDED AND UNBOUNDED FACES ITERATOR
 protected:
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Bounded_face_tester
  <Self,Non_degenerate_faces_iterator>
  Bounded_face_tester;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Unbounded_face_tester
  <Self,Non_degenerate_faces_iterator>
  Unbounded_face_tester;

 protected:
  typedef
  Filter_iterator<Non_degenerate_faces_iterator,Bounded_face_tester>
  Unbounded_faces_iterator_base;

  typedef
  Filter_iterator<Non_degenerate_faces_iterator,Unbounded_face_tester>
  Bounded_faces_iterator_base;

 public:
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Face_iterator_adaptor
  <Self,Unbounded_faces_iterator_base>
  Unbounded_faces_iterator;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Face_iterator_adaptor
  <Self,Bounded_faces_iterator_base>
  Bounded_faces_iterator;

  // THE BOUNDED AND UNBOUNDED HALFEDGES ITERATOR
 protected:
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Bounded_edge_tester
  <Self,Edge_iterator>
  Bounded_edge_tester;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Unbounded_edge_tester
  <Self,Edge_iterator>
  Unbounded_edge_tester;

 protected:
  typedef
  Filter_iterator<Edge_iterator,Bounded_edge_tester>
  Unbounded_edges_iterator_base;

  typedef
  Filter_iterator<Edge_iterator,Unbounded_edge_tester>
  Bounded_edges_iterator_base;

 public:
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Halfedge_iterator_adaptor
  <Self,Unbounded_edges_iterator_base>
  Unbounded_halfedges_iterator;

  typedef CGAL_VORONOI_DIAGRAM_2_NS::Halfedge_iterator_adaptor
  <Self,Bounded_edges_iterator_base>
  Bounded_halfedges_iterator;

 public:
  struct Face_circulator {}; // 1. circulates through the Voronoi cells
			     //    that are neighbors of the given
			     //    Voronoi cell;
                             // 2. also circulates through the Voronoi
                             //    cells adjacent to a Voronoi vertex

  struct Vertex_circulator {}; // 1. circulates through the Voronoi
			       //    vertices at the boundary of a
			       //    Voronoi cell
                               // 2. circulates also through the
                               //    Voronoi vertices that are
                               //    neighbors (through edges) to a
                               //    given vertex.

  struct Edge_circulator {}; // 1. circulates through the Voronoi
			     //    vertices at the boundary of a
			     //    Voronoi cell
                             // 2. also circulates around the edges of
                             //    a Voronoi vertex

public:
  //--------------
  // CONSTRUCTORS
  //--------------
#if 0
  Voronoi_diagram_adaptor_2(const Voronoi_traits& tr = Voronoi_traits())
    : dual_(), tr_(tr) {}
#endif

  Voronoi_diagram_adaptor_2(const Dual_graph& dg,
			    const Voronoi_traits& tr = Voronoi_traits())
#ifndef VDA_NO_CACHED_TESTERS
    : dual_(dg), tr_(tr), cached_e_tester_(), cached_f_tester_() {}
#else
    : dual_(dg), tr_(tr) {}
#endif

public:
  //------------------
  // ACCESS FUNCTIONS
  //------------------

  // DUAL
  const Dual_graph& dual() const { return dual_; }

  // VORONOI TRAITS
  const Voronoi_traits& voronoi_traits() const { return tr_; }

  // SIZE RELATED METHODS
  size_type number_of_vertices() const {
    size_type num_v = 0;
    for (Vertex_iterator it = vertices_begin();	it != vertices_end();
	 ++it, ++num_v) {}
    return num_v;
  }

  size_type number_of_faces() const {
    size_type num_f = 0;
    for (Face_iterator it = faces_begin(); it != faces_end();
	 ++it, ++num_f) {}
    return num_f;
  }

  size_type number_of_halfedges() const {
    size_type num_h = 0;
    for (Halfedge_iterator it = halfedges_begin(); it != halfedges_end();
	 ++it, ++num_h) {}
    return num_h;
  }

  // DEGENERACY TESTERS
#if 0
  const Edge_degeneracy_tester& edge_degeneracy_tester() const {
    return tr_.edge_degeneracy_tester_object();
  }

  const Face_degeneracy_tester& face_degeneracy_tester() const {
    return tr_.face_degeneracy_tester_object();
  }
#endif

#ifndef VDA_NO_CACHED_TESTERS
  const Cached_edge_degeneracy_tester& edge_tester() const {
    return cached_e_tester_;
  }

  const Cached_face_degeneracy_tester& face_tester() const {
    return cached_f_tester_;
  }
#else
  const Edge_degeneracy_tester& edge_tester() const {
    return tr_.edge_degeneracy_tester_object();
  }

  const Face_degeneracy_tester& face_tester() const {
    return tr_.face_degeneracy_tester_object();
  }
#endif

  // UNBOUNDED/BOUNDED FACE
  Face_handle unbounded_face() const {
    if ( unbounded_faces_begin() != unbounded_faces_end() ) {
      return unbounded_faces_begin();
    }
    return Face_handle();
  }

  Face_handle bounded_face() const {
    if ( bounded_faces_begin() != bounded_faces_end() ) {
      return bounded_faces_begin();
    }
    return Face_handle();
  }

  // UNBOUNDED/BOUNDED EDGE
  Halfedge_handle unbounded_halfedge() const {
    if ( unbounded_halfedges_begin() != unbounded_halfedges_end() ) {
      return unbounded_halfedges_begin();
    }
    return Halfedge_handle();
  }

  Halfedge_handle bounded_halfedge() const {
    if ( bounded_halfedges_begin() != bounded_halfedges_end() ) {
      return bounded_halfedges_begin();
    }
    return Halfedge_handle();
  }

  // FACE ITERATORS
 private:
  Non_degenerate_faces_iterator non_degenerate_faces_begin() const {
    return filter_iterator( dual_.finite_vertices_end(),
			    Face_degeneracy_tester_binder(this),
			    dual_.finite_vertices_begin() );
  }

  Non_degenerate_faces_iterator non_degenerate_faces_end() const {
    return filter_iterator( dual_.finite_vertices_end(),
			    Face_degeneracy_tester_binder(this) );
  }

 public:
  Face_iterator faces_begin() const {
    return Face_iterator(this, non_degenerate_faces_begin());
  }

  Face_iterator faces_end() const {
    return Face_iterator(this, non_degenerate_faces_end());
  }

 private:
  Unbounded_faces_iterator_base unbounded_faces_base_begin() const {
    return filter_iterator( non_degenerate_faces_end(),
			    Bounded_face_tester(this),
			    non_degenerate_faces_begin() );
  }

  Unbounded_faces_iterator_base unbounded_faces_base_end() const {
    return filter_iterator( non_degenerate_faces_end(),
			    Bounded_face_tester(this) );
  }

  Bounded_faces_iterator_base bounded_faces_base_begin() const {
    return filter_iterator( non_degenerate_faces_end(),
			    Unbounded_face_tester(this),
			    non_degenerate_faces_begin() );
  }

  Bounded_faces_iterator_base bounded_faces_base_end() const {
    return filter_iterator( non_degenerate_faces_end(),
			    Unbounded_face_tester(this) );
  }

 public:
  Unbounded_faces_iterator unbounded_faces_begin() const {
    return Unbounded_faces_iterator(this, unbounded_faces_base_begin());
  }

  Unbounded_faces_iterator unbounded_faces_end() const {
    return Unbounded_faces_iterator(this, unbounded_faces_base_end());
  }

  Bounded_faces_iterator bounded_faces_begin() const {
    return Bounded_faces_iterator(this, bounded_faces_base_begin());
  }

  Bounded_faces_iterator bounded_faces_end() const {
    return Bounded_faces_iterator(this, bounded_faces_base_end());
  }

  // EDGE ITERATORS
 private:
  Non_degenerate_edges_iterator non_degenerate_edges_begin() const {
    return filter_iterator( dual_.finite_edges_end(),
			    Edge_degeneracy_tester_binder(this),
			    dual_.finite_edges_begin() );
  }

  Non_degenerate_edges_iterator non_degenerate_edges_end() const {
    return filter_iterator( dual_.finite_edges_end(),
			    Edge_degeneracy_tester_binder(this) );
  }


  Edge_iterator_base edges_base_begin() const {
    return Edge_iterator_base(this, non_degenerate_edges_begin());
  }

  Edge_iterator_base edges_base_end() const {
    return Edge_iterator_base(this, non_degenerate_edges_end());
  }

  Valid_edges_iterator valid_edges_begin() const {
    return filter_iterator( edges_base_end(),
			    Edge_validity_tester(this),
			    edges_base_begin() );
  }

  Valid_edges_iterator valid_edges_end() const {
    return filter_iterator( edges_base_end(),
			    Edge_validity_tester(this) );
  }

 public:
  Edge_iterator edges_begin() const {
    return Edge_iterator(this, valid_edges_begin());
  }

  Edge_iterator edges_end() const {
    return Edge_iterator(this, valid_edges_end());
  }

  Halfedge_iterator halfedges_begin() const {
    return Halfedge_iterator(this, edges_begin());
  }

  Halfedge_iterator halfedges_end() const {
    return Halfedge_iterator(this, edges_end());
  }

 protected:
  Unbounded_edges_iterator_base unbounded_edges_base_begin() const {
    return filter_iterator( edges_end(),
			    Bounded_edge_tester(this),
			    edges_begin() );
  }

  Unbounded_edges_iterator_base unbounded_edges_base_end() const {
    return filter_iterator( edges_end(),
			    Bounded_edge_tester(this) );
  }

  Bounded_edges_iterator_base bounded_edges_base_begin() const {
    return filter_iterator( edges_end(),
			    Unbounded_edge_tester(this),
			    edges_begin() );
  }

  Bounded_edges_iterator_base bounded_edges_base_end() const {
    return filter_iterator( edges_end(),
			    Unbounded_edge_tester(this) );
  }

 public:
  Unbounded_halfedges_iterator unbounded_halfedges_begin() const {
    return Unbounded_halfedges_iterator(this, unbounded_edges_base_begin());
  }

  Unbounded_halfedges_iterator unbounded_halfedges_end() const {
    return Unbounded_halfedges_iterator(this, unbounded_edges_base_end());
  }

  Bounded_halfedges_iterator bounded_halfedges_begin() const {
    return Bounded_halfedges_iterator(this, bounded_edges_base_begin());
  }

  Bounded_halfedges_iterator bounded_halfedges_end() const {
    return Bounded_halfedges_iterator(this, bounded_edges_base_end());
  }

  // VERTEX ITERATORS
 private:
  Non_degenerate_vertices_iterator non_degenerate_vertices_begin() const {
    return filter_iterator( dual_.finite_faces_end(),
			    Vertex_validity_tester(this),
			    dual_.finite_faces_begin() );
  }

  Non_degenerate_vertices_iterator non_degenerate_vertices_end() const {
    return filter_iterator( dual_.finite_faces_end(),
			    Vertex_validity_tester(this) );
  }

 public:
  Vertex_iterator vertices_begin() const {
    return Vertex_iterator(this, non_degenerate_vertices_begin());
  }

  Vertex_iterator vertices_end() const {
    return Vertex_iterator(this, non_degenerate_vertices_end());
  }

  // CIRCULATORS
  Ccb_halfedge_circulator ccb_halfedges(const Face_handle& f) const {
    return Ccb_halfedge_circulator(*f->halfedge());
  }

  Ccb_halfedge_circulator ccb_halfedges(const Face_handle& f,
					const Halfedge_handle& he) const {
    CGAL_precondition( he->face() == f );
    return Ccb_halfedge_circulator(*he);
  }


  Halfedge_around_vertex_circulator
  incident_halfedges(const Vertex_handle& v) const {
    return incident_halfedges(v, v->halfedge());
  }

  Halfedge_around_vertex_circulator
  incident_halfedges(const Vertex_handle& v, const Halfedge_handle& he) const {
    CGAL_precondition( he->target() == v );
    return Halfedge_around_vertex_circulator(*he);
  }

  // VALIDITY TESTING
  bool is_valid() const {
    bool valid = dual_.is_valid();
    for (Vertex_iterator it = vertices_begin(); it != vertices_end(); ++it) {
      valid = valid && it->is_valid();
    }

    for (Face_iterator it = faces_begin(); it != faces_end(); ++it) {
      valid = valid && it->is_valid();
    }

    for (Halfedge_iterator it = halfedges_begin(); it != halfedges_end();
	 ++it) {
      valid = valid && it->is_valid();
    }
    return valid;
  }

  // POINT LOCATION
  typedef CGAL_VORONOI_DIAGRAM_2_NS::Locate_type<Self,true>  Locate_type;

 private:
  Locate_type locate(const Point_2& p, const Tag_false&) const {
    static unsigned int i = 0;
    if ( i == 0 ) {
      i++;
      std::cerr << "Point location is not supported..." << std::endl;
    }

    // to avoid warnings/errors...
    //    Face_handle f;
    return Locate_type(Face_handle());
  }

  Locate_type locate(const Point_2& p, const Tag_true&) const
  {
    CGAL_precondition( dual_.number_of_vertices() > 0 );

    typedef typename Voronoi_traits::Point_locator     Point_locator;
    typedef typename Point_locator::Locate_type        PL_Locate_type;

    Point_locator locate = tr_.point_locator_object();
    PL_Locate_type pl_lt = locate(dual_, p);

    if ( pl_lt.is_vertex() ) {
      Face_handle f( Face(this, pl_lt.vertex()) );
      return Base::make_locate_type(f);
    } else if ( pl_lt.is_face() ) {
      CGAL_VORONOI_DIAGRAM_2_NS::Find_valid_vertex<Self> vertex_finder;
      Dual_face_handle dfvalid = vertex_finder(this, pl_lt.face());
      Vertex_handle v( Vertex(this, dfvalid) );
      return Base::make_locate_type(v);
    } else if ( pl_lt.is_edge() ) {
      Dual_edge de = pl_lt.edge();
      CGAL_assertion(  !edge_tester()(dual_, de)  );
      if ( dual_.dimension() == 1 ) {
	Dual_vertex_handle v1 = de.first->vertex(CW_CCW_2::ccw(de.second));
	Dual_vertex_handle v2 =	de.first->vertex(CW_CCW_2::cw(de.second) );
	Halfedge_handle e( Halfedge(this, v1, v2) );
	return Base::make_locate_type(e);
      }
      Halfedge_handle e( Halfedge(this, de.first, de.second) );
      return Base::make_locate_type(e);
    }

    // I should never have reached this line;
    CGAL_assertion( false );
    return Base::make_locate_type(Face_handle());
  }

 public:
  Locate_type locate(const Point_2& p) const {
    return locate(p, Has_point_locator());
  }


private:
  Dual_graph  dual_;
  Voronoi_traits tr_;
#ifndef VDA_NO_CACHED_TESTERS
  Cached_edge_degeneracy_tester cached_e_tester_;
  Cached_face_degeneracy_tester cached_f_tester_;
#endif
};


CGAL_END_NAMESPACE

// TO-DO-LIST
// ----------
// * write code for vertices iterator; they need to return Vertex as type
// * decide whether infinite halfedges are indeed halfedges...

#endif // CGAL_VORONOI_DIAGRAM_ADAPTOR_2_H
