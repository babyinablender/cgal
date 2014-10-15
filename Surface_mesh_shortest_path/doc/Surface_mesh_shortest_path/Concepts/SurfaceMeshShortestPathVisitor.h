/*!
\ingroup PkgSurfaceMeshShortestPathConcepts

\cgalConcept

The concept `SurfaceMeshShortestPathVisitor` describes the requirements of the visitor type
used to collect the edges and vertices traversed by a shortest path on the
surface of a triangulated surface mesh.

The methods are called in the order of the shortest path sequence along the
 surface, starting with the target point and ending with the source point.

*/

class SurfaceMeshShortestPathVisitor
{
public:

/// \name Methods
/// @{

  /*!
  \brief Called when an edge was traversed in the shortest path sequence.
  \param edge halfedge of the polyhedron crossed by the shortest path. The halfedge will be directed toward the face <em>nearest</em> to the target point.
  \param t value in the range [0.0,1.0] specifying where along `edge` the shortest path crossed. 
    - 0.0 means it crossed at `source(edge)`
    - 1.0 means it crossed at `target(edge)`
    - Any other value is linearly interpolated between the endpoints.
    
    Note that values of 0.0 and 1.0 are possible in some situations, and may not be reported as vertices.
  \todo Shall we handle this internally?
  */
  void edge(halfedge_descriptor edge, FT t);
  
  /*!
  \brief Called when a vertex is encountered in the shortest path sequence.
  \param vertex the vertex of the polyhedron encountered by the shortest path.
  */
  void vertex(vertex_descriptor vertex);
  
  /*!
  \brief Called when a face location is encountered in the shortest path sequence.
  \remarks This will only be called as the first and/or last element in the path 
  sequence, and only if the target/source point is an internal face location 
  (i.e. not on an edge or at a vertex).
  \param face a face of the polyhedron encountered at the start or the end of the shortest path.
  \param location the barycentric coordinate inside `face` of this point on the path.
  */
  void face(face_descriptor face, Barycentric_coordinate location);
};